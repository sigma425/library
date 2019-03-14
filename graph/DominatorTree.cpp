/*
	G : directed graph
	v,w in V について,v dominates w ⇔ Dominator Treeにおいてvからwへのpathがある
	vの親をidom[v]として根付き木(dominator tree)を作ればdominate関係(r->wに行くとき必ずvを通るか)がすべてわかる
	verified at:
		AOJ294
		https://www.codechef.com/problems/GRAPHCNT (root からたどり着けない頂点がある)
	
*/

struct DominatorTree{
	V<int> par,m,parent,vertex,semi,U,idom;
	int I,N;
	VV<int> bucket,G,rG;

	DominatorTree(const VV<int>& G_, int r = 0):G(G_){
		N = G.size();
		I = 0;
		par.resize(N);
		m.resize(N);
		parent.resize(N);
		vertex = V<int>(N,-1);
		semi.resize(N);
		U.resize(N);
		idom = V<int>(N,-2);
		bucket.resize(N);
		rG.resize(N);
		rep(i,N) for(int j: G[i]){
			rG[j].pb(i);
		}

		rep(i,N){
			par[i] = i;
			m[i] = i;
			semi[i] = -1;
		}
		dfs(r);
		for(int i=N-1;i>0;i--){
			int w=vertex[i];
			if(w == -1) continue;
			for(int v:rG[w]) if(semi[v] != -1){
				int u=EVAL(v);
				chmin(semi[w],semi[u]);
			}
			bucket[vertex[semi[w]]].pb(w);
			for(int v:bucket[parent[w]]) U[v]=EVAL(v);
			bucket[parent[w]].clear();
			LINK(parent[w],w);
		}
		for(int i=1;i<N;i++){
			int w=vertex[i];
			if(w == -1) continue;
			int u=U[w];
			if(semi[w]==semi[u]) idom[w]=semi[w];
			else idom[w]=idom[u];
		}

		for(int i=1;i<N;i++){				//idom[w]の中身をvertex idから名前に変える
			int w=vertex[i];
			if(w == -1) continue;
			idom[w]=vertex[idom[w]];
		}
		idom[r] = -1;
	}

	int find(int v){
		if(par[v]==v) return v;
		int r=find(par[v]);
		if(semi[m[v]]>semi[m[par[v]]]) m[v]=m[par[v]];
		return par[v]=r;
	}
	int EVAL(int v){
		find(v);
		return m[v];
	}
	void LINK(int x,int y){
		par[y]=x;
	}
	void dfs(int v){
		semi[v]=I;
		vertex[I++]=v;
		for(int u:G[v]) if(semi[u]<0){
			parent[u]=v;
			dfs(u);
		}
	}
};

int main(){
	int N,M;
	cin>>N>>M;
	VV<int> G(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].pb(b);
	}
	DominatorTree DT(G,0);
	VV<int> tree(N);
	rep(i,N){
		int p = DT.idom[i];
		if(p >= 0){
			tree[p].pb(i);
		}
	}
	function<int(int)> dfs = [&](int v){
		int res = 1;
		for(int u:tree[v]) res += dfs(u);
		return res;
	};
	using ll = long long;
	V<ll> subtree_sz;
	for(int c: tree[0]) subtree_sz.pb(dfs(c));
	ll ans = 0;
	ll sm = 1;
	for(ll x: subtree_sz){
		ans += x * sm;
		sm += x;
	}
	cout << ans << endl;
}
