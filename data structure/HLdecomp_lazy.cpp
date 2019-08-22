/*
	HL-decomposition for lazy
	lazy segtree と同じことを木の(頂点集合 / 辺集合)に対してできる
	**** OnEdge **** という bool を変えるだけで使える

	assumption :
		a*b*..*c*d から d*c*..*b*a が簡単に計算できる (up を reverse する必要がある)
			そうでない場合、上向きと下向きのsegtreeを両方保つ必要がある(今は下向きだけ)

	usage : 
		OnEdge 変える
		vector<vector<Edge>> G をconstructorに渡す
		query(u,val_t)
		update(u,v,opr_t)

	verified at AGC14/E
				OpenCup/9922/E.cpp
*/

template<class Handler>
struct segtree_lazy{
	using val_t = typename Handler::val_t;
	using opr_t = typename Handler::opr_t;
	int N;
	vector<val_t> val;
	vector<opr_t> lazy;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	segtree_lazy(const vector<val_t>& vc){init(vc);}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		lazy.assign(N*2,opr_t::e());
	}
	void init(const vector<val_t>& vc){
		int n = vc.size();
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		rep(i,n) val[i+N] = vc[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
		lazy.assign(N*2,opr_t::e());
	}
	val_t realvalue(int k,int l,int r){
//		return Handler::act(lazy[k],val[k]);
		return Handler::act(lazy[k],val[k],k,l,r);
	}

	val_t query(int a,int b,int l=0,int r=-1,int k=1){	//query_calc
//		if(k==1) printf("query [%d,%d)\n",a,b);
		if(r==-1) r=N;
		if(b<=l||r<=a) return val_t::e();
		if(a<=l&&r<=b) return realvalue(k,l,r);
		propagate(l,r,k);
		val_t ret = query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);
		val[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);
		return ret;

	}
//	val_t query_leftassoc(){}
	void update(int a,int b,const opr_t &x,int l=0,int r=-1,int k=1){	//query_update
//		if(k==1) printf("update [%d,%d)\n",a,b);
		if(r==-1) r=N;
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			Handler::setg2fg(x,lazy[k]);
			return;
		}
		propagate(l,r,k);
		update(a,b,x,l,(l+r)/2,k*2);
		update(a,b,x,(l+r)/2,r,k*2+1);
		val[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);
	}
	void propagate(int l,int r,int k){	//opr_child -> opr_parent * opr_child		parent after child
		Handler::setg2fg(lazy[k],lazy[k*2  ]);
		Handler::setg2fg(lazy[k],lazy[k*2+1]);
		lazy[k] = opr_t::e();
	}
};

template<class E, class Handler>		//for lazy segtree
struct HLdecomp{
	using val_t = typename Handler::val_t;
	using opr_t = typename Handler::opr_t;
	using segtree = segtree_lazy<Handler>;

	static const bool OnEdge = 0;

	vector<vector<E>> G;
	using P = pair<int,int>;
	vector<P> id;				//id[v] = P(chain_id,pos_on_chain)	posはtop to bottom
	vector<int> sz;				//sz[v] = subtree_size
	vector<int> dep;			//dep[v] = depth
	vector<int> par;			//par[v] = parent
	vector<int> top;			//id[v].fs の一番上

	int C;	//num of chains
	vector<vector<int>> chains;	//chains[c][i] = v <=> id[v] = P(c,i)
	vector<segtree> segs;

	HLdecomp(const vector<vector<E>>& G_, int r = 0):G(G_){
		int N = G.size();
		C = 1;
		chains.pb({0});
		id.assign(N,P(0,0));
		sz.assign(N,0);
		dep.assign(N,0);
		par.assign(N,0);
		top.assign(N,0);

		dfs_base(r);
		dfs_decomp(r);

	
		rep(c,C) segs.pb(segtree(chains[c].size()));
	}
	void dfs_base(int v,int p=-1){	//calc sz,dep
		sz[v] = 1;
		par[v] = p;
		if(p==-1) dep[v] = 0;
		else dep[v] = dep[p] + 1;
		for(const auto& e: G[v]){
			int u = e.to;
			if(u==p) continue;
			dfs_base(u,v);
			sz[v] += sz[u];
		}
	}
	void dfs_decomp(int v,int p=-1){
		int heavy = -1;
		for(const auto& e: G[v]){
			int u = e.to;
			if(u == p) continue;
			if(heavy == -1 || sz[heavy]<sz[u]) heavy = u;
		}
		for(const auto& e: G[v]){
			int u = e.to;
			if(u == p) continue;
			if(u == heavy){
				id[u] = P(id[v].fs,id[v].sc+1);
				top[u] = top[v];
			}else{
				id[u] = P(C,0);
				top[u] = u;
				C++;
				chains.pb({});
			}
			chains[id[u].fs].pb(u);
			dfs_decomp(u,v);
		}
	}
	int lca(int a,int b){
		while(id[a].fs != id[b].fs){
			if(id[a].fs < id[b].fs) b = par[top[b]];
			else a = par[top[a]];
		}
		return dep[a]<dep[b] ? a : b;
	}
	int up(int v,int d){	//vから上にd上がった点
		if(dep[v]<d) return -1;
		while(true){
			int d1 = dep[v] - dep[top[v]];
			if(d1<=d){
				d -= d1;
				v = top[v];
			}else{
				int c = id[v].fs;
				return chains[c][d1-d];
			}
			if(d==0) return v;
			v = par[v];
			d--;
		}
		assert(0);
		return -1;
	}
	val_t query(int u,int v){	//[u,w) + [w,v]			edge ver なら [u,w) + (w,v]
		int w = lca(u,v);
		val_t up,down;

		{
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				//chains[c][l,r]
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				val_t x = segs[c].query(l,r+1);
				up = x + up;
			}
			int c = id[u].fs;
			int l = id[w].sc+1;
			int r = id[u].sc;
			val_t x = segs[c].query(l,r+1);
			up = x + up;
		}
		{
			u = v;
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				val_t x = segs[c].query(l,r+1);
				down = x + down;
			}
			int c = id[u].fs;
			int l = id[w].sc + OnEdge;
			int r = id[u].sc;
			val_t x = segs[c].query(l,r+1);
			down = x + down;
		}

		// ! reverse up !
		return up + down;
	}
	void update(int u,int v,const opr_t &x){	//[u,w) + [w,v]
		int w = lca(u,v);

		{
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				//chains[c][l,r]
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				segs[c].update(l,r+1,x);
			}
			int c = id[u].fs;
			int l = id[w].sc+1;
			int r = id[u].sc;
			segs[c].update(l,r+1,x);
		}
		{
			u = v;
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				segs[c].update(l,r+1,x);
			}
			int c = id[u].fs;
			int l = id[w].sc + OnEdge;
			int r = id[u].sc;
			segs[c].update(l,r+1,x);
		}
	}
};

struct handler2{
	/*
		range assign 0以上
		range sum

		val_t = int,+			val[k]= +
		opr_t(x) : y -> x		lazy[k]=assign

		assignは一緒なので、opr_t,getfgは変えなくていい
		気づいたんですが,actとかにl,rが必要なケースが多すぎる(sum系とかほぼ確実に必要)ので、もうこういうのはval_tにl,rを置くことにします
		と思ったが、やっぱりやめて、lとrを頑張ってactに渡すことにした
		getfgとかにも必要になると絶望感が増しそう

	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(x+r.x);
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void getfg(const opr_t &f, const opr_t &g){

	}
	/*
		もしコピーコストとかが気になって,しかも楽に書けるならsetg2fgを直接書く
		そうじゃないなら g = getfg(f,g)
	*/
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		if(f.x == -1) return v;
		return val_t(f.x*(r-l));
	}
};

struct Edge{int to;};

void unittest(){
	int N;
	cin>>N;
	vector<vector<Edge>> G(N);

	//brute
	vector<vector<int>> d(N,vector<int>(N,1e9));
	rep(i,N) d[i][i] = 0;


	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		G[x].pb({y});
		G[y].pb({x});
		d[x][y] = d[y][x] = 1;
	}
	rep(i,N) rep(j,N) rep(k,N) chmin(d[j][k],d[j][i]+d[i][k]);
	HLdecomp<Edge,handler2> HLD(G);

	vector<int> a(N);

	while(true){
		char c;
		cin>>c;
		if(c=='q'){
			int u,v;
			cin>>u>>v;
			int res = HLD.query(u,v).x;
			int brute = 0;
			rep(i,N) if(d[u][i]+d[i][v]==d[u][v]) brute += a[i];
			assert(res == brute);
		}else{
			int u,v,c;
			cin>>u>>v>>c;
			HLD.update(u,v,c);
			rep(i,N) if(d[u][i]+d[i][v]==d[u][v]) a[i] = c;
		}
	}
}

int main(){
	unittest();
}
