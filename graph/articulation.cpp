/*
	関節点
	ord[v]: dfs森でのid
	low[v]: lowlink, dfs木で子にいく + 一回だけ後退辺で上に上がれる ときにたどりつけるord のmin
	vが関節点⇔
	vがdfs木のroot かつ 次数が2以上 or
	vがdfs木のrootでない かつ ある子uが存在し, ord[v]<=low[u]
	ord[v]=low[u]でも関節点(自分にサイクルが戻ってきたとしても上にはいけないのでまだ関節点なまま) なことに注意

	二重(頂点)連結成分
	橋に対する二重辺連結成分のように、二重連結成分が定義される。
	辺集合Eが二重連結⇔Eで誘導されるグラフが関節点を持たない


	二重辺連結成分分解が木を作るように、関節点と二重辺連結成分を頂点として持つ木みたいなのを作れる
	joi/spring/12/sokoban.cpp 山椒

	多重辺は対応していない、多重辺があっても関節点かどうかには関わりがない。
	対応したいならEdgeにidみたいなのを持たせておいてif文の判定をそれでやる

	Articulation Art(G);
	Art.constructCompressedGraph();
	VV<int> H = Art.H;
	
	Hは木であって、
		- もとの頂点 v が v に対応
		- biedges[i] が N+i に対応
		二部グラフになる、関節点でない頂点がHの葉になる
*/
template<class E>
struct Articulation{
	using P = pair<int,E>;

	//in
	VV<E> G;

	//out
	V<int> arts;
	VV<P> biedges;

	//out(constructCompressedGraph)
	VV<int> H;


	//tmp
	V<int> ord,low;
	int I;
	stack<P> st;

	Articulation(const VV<E>& G_):G(G_){	//calc arts,biedges
		int N = G.size();
		ord = low = V<int>(N);
		I = 0;

		rep(i,N) if(ord[i]==0){
			while(!st.empty()) st.pop();
			dfs(i);
		}
	}

	void constructCompressedGraph(){
		int N = G.size();
		int B = biedges.size();		//[N,N+B)

		H = VV<int>(N+B);

		rep(b,B){
			V<int> vc;
			for(P p:biedges[b]){
				int from = p.fs;
				int to = p.sc.to;
				vc.pb(from);
				vc.pb(to);
			}
			mkuni(vc);
			for(int v:vc){
				H[N+b].pb(v);
				H[v].pb(N+b);
			}
		}
	}

	void dfs(int v,int p = -1){
		ord[v]=++I;
		low[v]=ord[v];
		int c=0;
		bool isart=0;
		for(auto& e:G[v]) if(e.to!=p){
			int u = e.to;
			if(ord[u]<ord[v]) st.push(P(v,e));
			if(ord[u]) chmin(low[v],ord[u]);	//back edge
			else{
				dfs(u,v);
				c++;
				chmin(low[v],low[u]);
				if(low[u]>=ord[v]){
					isart = 1;
					vector<P> vp;
					while(true){
						P p=st.top();st.pop();
						vp.pb(p);
						if(p.fs==v && p.sc.to==u) break;
					}
					biedges.pb(vp);
				}
			}
		}
		if(p<0) isart=(c>1);
		if(isart) arts.pb(v);
	}
	
};
struct Edge{
	int to;
	friend ostream& operator<<(ostream& o,const Edge& e){return o<<e.to;}
};
