/*
	木が与えられる
	クエリとしてサイズ K の頂点集合が来ると、縮約した木を O(K log N) でつくる

	usage:
		CompressedSubtree CS(tree)
		のあと好きなだけ CS.ComputeSubtree(vs) を呼べばいい
		返り値は vector<pair<int,int>> もとの頂点番号を使っている
		もしreindexしたいならindex[v] を見ればいい

	verified at : https://www.codechef.com/problems/UNIVERSE

*/

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

int bsr(int x){	//4~7 -> 2
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}

template<class E>
struct CompressedSubtree{
	int N,n;
	V<int> depth;
	VV<int> par;
	V<int> in;
	int I;

	V<int> index;
	V<int> vs;

	CompressedSubtree(const VV<E>& G, int r = 0):N((int)G.size()),n(bsr(N)),depth(N),par(N,V<int>(n+1)),in(N),I(0),index(N){
		dfs(r,-1,G);
		rep1(i,n){
			rep(v,N){
				if(par[v][i-1] == -1) par[v][i] = -1;
				else par[v][i] = par[par[v][i-1]][i-1];
			}
		}
	}

	V<pair<int,int>> ComputeTree(const V<int>& _vs){
		auto comp = [&](int x,int y){
			return in[x] < in[y];
		};
		vs = _vs;
		sort(all(vs),comp);
		vs.erase(unique(vs.begin(),vs.end()),vs.end());

		int K = vs.size();
		rep(i,K-1){
			vs.pb(lca(vs[i],vs[i+1]));
		}
		sort(all(vs),comp);
		vs.erase(unique(vs.begin(),vs.end()),vs.end());
		K = vs.size();
		rep(i,K) index[vs[i]] = i;
		V<pair<int,int>> es;
		rep1(i,K-1){
			int p = lca(vs[i-1],vs[i]);
			es.pb(pair<int,int>(vs[i],p));
		}
		return es;
	}

	void dfs(int v,int p,const VV<E>& G){
		in[v] = I++;
		par[v][0] = p;
		for(auto& e : G[v]){
			int u = e.to;
			if(u == p) continue;
			depth[u] = depth[v] + 1;
			dfs(u,v,G);
		}
	}

	int lca(int u,int v){
		if(depth[u]<depth[v]) swap(u,v);
		int d = depth[u]-depth[v];
		rep(i,n+1){
			if((d>>i)&1) u=par[u][i];
		}
		if(u==v) return u;
		for(int i=n;i>=0;i--){
			if(par[u][i]!=par[v][i]){
				u=par[u][i];
				v=par[v][i];
			}
		}
		return par[v][0];
	}
	int distance(int u,int v){
		return depth[u]+depth[v]-2*depth[lca(u,v)];
	}
};

struct edge{
	int to;
};

template<class D>
vector<D> dijkstra(const vector<vector<pair<int,D>>>& G, int s = 0){	//G:(v,cost)
	using P = pair<D,int>;
	priority_queue<P,vector<P>,greater<P> > que;
	int N = G.size();

	D inf = 1e18;
	vector<D> d(N,inf);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v = p.sc;
		D c = p.fs;
		if(d[v]!=c) continue;
		for(auto p:G[v]){
			int to=p.fs;
			if(d[to]>d[v]+p.sc){
				d[to]=d[v]+p.sc;
				que.push(P(d[to],to));
			}
		}
	}

	return d;
}

int main(){
	int N,M,Q;
	cin>>N>>M>>Q;
	VV<edge> T(N);
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		T[x].pb({y});
		T[y].pb({x});
	}
	CompressedSubtree<edge> CS(T);

	VV<int> t2vs(200000);
	V<int> x(M),tx(M),y(M),ty(M);
	V<int> qx(Q),qtx(Q),qy(Q),qty(Q);

	rep(i,M){
		cin>>x[i]>>tx[i]>>y[i]>>ty[i];
		x[i]--,tx[i]--,y[i]--,ty[i]--;
		t2vs[tx[i]].pb(x[i]);
		t2vs[ty[i]].pb(y[i]);
	}
	rep(i,Q){
		cin>>qx[i]>>qtx[i]>>qy[i]>>qty[i];
		qx[i]--,qtx[i]--,qy[i]--,qty[i]--;
		t2vs[qtx[i]].pb(qx[i]);
		t2vs[qty[i]].pb(qy[i]);
	}

	using P = pair<int,int>;
	map<P,int> mp;	//t,v -> id
	int I = 0;

	rep(t,200000){
		auto& vs = t2vs[t];
		sort(all(vs));
		vs.erase(unique(all(vs)),vs.end());
		auto es = CS.ComputeTree(vs);
		for(int v : CS.vs){
			mp[P(t,v)] = I++;
		}
	}
	VV<pair<int,ll>> G(I);

	auto add_edge = [&](int x,int y,ll d){
		G[x].pb(pair<int,ll>(y,d));
		G[y].pb(pair<int,ll>(x,d));
	};

	rep(t,200000){
		auto& vs = t2vs[t];
		auto es = CS.ComputeTree(vs);
		for(P e: es){
			int x = e.fs, y = e.sc;
			add_edge(mp[P(t,x)],mp[P(t,y)],CS.distance(x,y));
		}
	}
	rep(i,M){
		add_edge(mp[P(tx[i],x[i])],mp[P(ty[i],y[i])],1);
	}

	rep(qt,Q){
		int a = qx[qt], ta = qtx[qt], b = qy[qt], tb = qty[qt];
		vector<ll> d = dijkstra<ll>(G,mp[P(ta,a)]);
		ll ans = d[mp[P(tb,b)]];
		if(ans == 1e18) puts("impossible");
		else cout<<ans<<endl;
	}
}


/*
	重み付き
	dw が重みの総和
	distance(u,v) で引き算してるから可換群じゃなきゃだめ
	ちゃんとやればモノイドが乗る
*/

template<class E>
struct CompressedSubtree{
	int N,n;
	V<int> depth;
	V<ll> dw;
	VV<int> par;
	V<int> in;
	int I;

	V<int> index;
	V<int> vs;

	CompressedSubtree(const VV<E>& G, int r = 0):N((int)G.size()),n(bsr(N)),depth(N),dw(N),par(N,V<int>(n+1)),in(N),I(0),index(N){
		dfs(r,-1,G);
		rep1(i,n){
			rep(v,N){
				if(par[v][i-1] == -1) par[v][i] = -1;
				else par[v][i] = par[par[v][i-1]][i-1];
			}
		}
	}

	V<pair<int,int>> ComputeTree(const V<int>& _vs){
		auto comp = [&](int x,int y){
			return in[x] < in[y];
		};
		vs = _vs;
		sort(all(vs),comp);
		vs.erase(unique(vs.begin(),vs.end()),vs.end());

		int K = vs.size();
		rep(i,K-1){
			vs.pb(lca(vs[i],vs[i+1]));
		}
		sort(all(vs),comp);
		vs.erase(unique(vs.begin(),vs.end()),vs.end());
		K = vs.size();
		rep(i,K) index[vs[i]] = i;
		V<pair<int,int>> es;
		rep1(i,K-1){
			int p = lca(vs[i-1],vs[i]);
			es.pb(pair<int,int>(vs[i],p));
		}
		return es;
	}

	void dfs(int v,int p,const VV<E>& G){
		in[v] = I++;
		par[v][0] = p;
		for(auto& e : G[v]){
			int u = e.to;
			if(u == p) continue;
			depth[u] = depth[v] + 1;
			dw[u] = dw[v] + e.len;
			dfs(u,v,G);
		}
	}

	int lca(int u,int v){
		if(depth[u]<depth[v]) swap(u,v);
		int d = depth[u]-depth[v];
		rep(i,n+1){
			if((d>>i)&1) u=par[u][i];
		}
		if(u==v) return u;
		for(int i=n;i>=0;i--){
			if(par[u][i]!=par[v][i]){
				u=par[u][i];
				v=par[v][i];
			}
		}
		return par[v][0];
	}
	ll distance(int u,int v){
		return dw[u]+dw[v]-2*dw[lca(u,v)];
	}
};

struct edge{
	int to; ll len;
	edge(int to_, ll len_):to(to_),len(len_){}
};