---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data structure/HLdecomp_simple.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/HLdecomp_simple.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-22 16:22:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    こっちは lazy がない方の HLdecomp
        OnEdge
        VV<E> G をコンストラクタに渡す
        query(u,v)
        assign(v,x) <- OnEdge = 0 のとき
        assign(u,v,x) <- OnEdge = 1 のとき
    
    verified at ABC133F
*/

template<class D>
struct segtree_simple{
	int N;
	vector<D> val;

	segtree_simple(){}
	segtree_simple(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e());
	}
	segtree_simple(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e());
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D query(int a,int b){		//non-commutative & unrecursive
		D L = D::e() , R = D::e();
		a+=N,b+=N;
		while(a<b){
			if(a&1) L = L + val[a++];
			if(b&1) R = val[--b] + R;
			a/=2,b/=2;
		}
		return L+R;
	}
};

template<class E, class D>		//for simple segtree
struct HLdecomp{
	using segtree = segtree_simple<D>;

	static const bool OnEdge = 1;

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
	D query(int u,int v){	//[u,w) + [w,v]			edge ver なら [u,w) + (w,v]
		int w = lca(u,v);
		D up,down;

		{
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				//chains[c][l,r]
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				D x = segs[c].query(l,r+1);
				up = x + up;
			}
			int c = id[u].fs;
			int l = id[w].sc+1;
			int r = id[u].sc;
			D x = segs[c].query(l,r+1);
			up = x + up;
		}
		{
			u = v;
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				D x = segs[c].query(l,r+1);
				down = x + down;
			}
			int c = id[u].fs;
			int l = id[w].sc + OnEdge;
			int r = id[u].sc;
			D x = segs[c].query(l,r+1);
			down = x + down;
		}

		// ! reverse up !
		return up + down;
	}

	// Vertex version
	// d[v] <= x
	void assign(int v,const D &x){
		int c = id[v].fs;
		int i = id[v].sc;
		segs[c].assign(i,x);
	}
	// Edge version
	// d[(v,u)] <= x
	void assign(int v,int u,const D &x){
		if(dep[v] < dep[u]) swap(v,u);
		assert(dep[v] == dep[u]+1);
		int c = id[v].fs;
		int i = id[v].sc;
		segs[c].assign(i,x);
	}
};

struct D{
	int x;
	D(){*this = e();}
	D(int x_):x(x_){}
	static D e(){
		return D(0);
	}
	D operator+(const D& r) const {
		return D(x+r.x);
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/HLdecomp_simple.cpp"
/*
    こっちは lazy がない方の HLdecomp
        OnEdge
        VV<E> G をコンストラクタに渡す
        query(u,v)
        assign(v,x) <- OnEdge = 0 のとき
        assign(u,v,x) <- OnEdge = 1 のとき
    
    verified at ABC133F
*/

template<class D>
struct segtree_simple{
	int N;
	vector<D> val;

	segtree_simple(){}
	segtree_simple(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e());
	}
	segtree_simple(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e());
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D query(int a,int b){		//non-commutative & unrecursive
		D L = D::e() , R = D::e();
		a+=N,b+=N;
		while(a<b){
			if(a&1) L = L + val[a++];
			if(b&1) R = val[--b] + R;
			a/=2,b/=2;
		}
		return L+R;
	}
};

template<class E, class D>		//for simple segtree
struct HLdecomp{
	using segtree = segtree_simple<D>;

	static const bool OnEdge = 1;

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
	D query(int u,int v){	//[u,w) + [w,v]			edge ver なら [u,w) + (w,v]
		int w = lca(u,v);
		D up,down;

		{
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				//chains[c][l,r]
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				D x = segs[c].query(l,r+1);
				up = x + up;
			}
			int c = id[u].fs;
			int l = id[w].sc+1;
			int r = id[u].sc;
			D x = segs[c].query(l,r+1);
			up = x + up;
		}
		{
			u = v;
			for(;id[u].fs!=id[w].fs; u = par[top[u]]){
				int c = id[u].fs;
				int l = id[top[u]].sc;
				int r = id[u].sc;
				D x = segs[c].query(l,r+1);
				down = x + down;
			}
			int c = id[u].fs;
			int l = id[w].sc + OnEdge;
			int r = id[u].sc;
			D x = segs[c].query(l,r+1);
			down = x + down;
		}

		// ! reverse up !
		return up + down;
	}

	// Vertex version
	// d[v] <= x
	void assign(int v,const D &x){
		int c = id[v].fs;
		int i = id[v].sc;
		segs[c].assign(i,x);
	}
	// Edge version
	// d[(v,u)] <= x
	void assign(int v,int u,const D &x){
		if(dep[v] < dep[u]) swap(v,u);
		assert(dep[v] == dep[u]+1);
		int c = id[v].fs;
		int i = id[v].sc;
		segs[c].assign(i,x);
	}
};

struct D{
	int x;
	D(){*this = e();}
	D(int x_):x(x_){}
	static D e(){
		return D(0);
	}
	D operator+(const D& r) const {
		return D(x+r.x);
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

