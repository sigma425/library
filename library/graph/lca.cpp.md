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


# :warning: graph/lca.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/lca.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-20 16:39:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
verified by AOJ GRL 5C

lca(u,v)をクエリO(logN)で求める
前処理O(NlogN)
pとdepthがうまってれば一個目のgenlcaだけでいいけど,一般にグラフGがある状況だと
下のdfs+genlcaしなきゃダメ

pathに分解するときは[u,z) + [v,z) + z みたいにするか, 片方を閉区間にする(depth-1持ち上げる)とok

*/

int bsr(int x){	//4~7 -> 2
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
struct LCA{
	int N,n;
	vector<int> depth;
	vector<vector<int>> par;

	void dfs(int v,int p,const vector<vector<int>>& G){
		if(p<0) depth[v]=0;
		else depth[v]=depth[p]+1;
		par[v][0]=p;
		for(int u:G[v]){
			if(u!=p) dfs(u,v,G);
		}
	}

	LCA(const vector<vector<int>>& G){
		N = G.size();
		n = bsr(N);
		depth = vector<int>(N,0);
		par = vector<vector<int>>(N,vector<int>(n+1,0));

		dfs(0,-1,G);
		rep1(i,n){
			rep(v,N){
				if(par[v][i-1]==-1){
					par[v][i]=-1;
				}else{
					par[v][i]=par[par[v][i-1]][i-1];
				}
			}
		}
	}

	int lca(int u,int v){
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		int d=depth[u]-depth[v];
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
		return depth[u] + depth[v] - 2*depth[lca(u,v)];
	}

	/*
		xからyにむかってdうごく
		dist(x,y) < d なら y を返す
		CF621 F
	*/
	int jump(int x,int y,int d){
		int z = lca(x,y);
		int d1 = depth[x]-depth[z];
		int d2 = depth[y]-depth[z];
		if(d <= d1){
			// up d from x
			rep(i,n+1) if(d&1<<i) x = par[x][i];
			return x;
		}else if(d <= d1+d2){
			// up d1+d2-d from y
			d = d1+d2-d;
			rep(i,n+1) if(d&1<<i) y = par[y][i];
			return y;
		}else{
			return y;
		}
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/lca.cpp"
/*
verified by AOJ GRL 5C

lca(u,v)をクエリO(logN)で求める
前処理O(NlogN)
pとdepthがうまってれば一個目のgenlcaだけでいいけど,一般にグラフGがある状況だと
下のdfs+genlcaしなきゃダメ

pathに分解するときは[u,z) + [v,z) + z みたいにするか, 片方を閉区間にする(depth-1持ち上げる)とok

*/

int bsr(int x){	//4~7 -> 2
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
struct LCA{
	int N,n;
	vector<int> depth;
	vector<vector<int>> par;

	void dfs(int v,int p,const vector<vector<int>>& G){
		if(p<0) depth[v]=0;
		else depth[v]=depth[p]+1;
		par[v][0]=p;
		for(int u:G[v]){
			if(u!=p) dfs(u,v,G);
		}
	}

	LCA(const vector<vector<int>>& G){
		N = G.size();
		n = bsr(N);
		depth = vector<int>(N,0);
		par = vector<vector<int>>(N,vector<int>(n+1,0));

		dfs(0,-1,G);
		rep1(i,n){
			rep(v,N){
				if(par[v][i-1]==-1){
					par[v][i]=-1;
				}else{
					par[v][i]=par[par[v][i-1]][i-1];
				}
			}
		}
	}

	int lca(int u,int v){
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		int d=depth[u]-depth[v];
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
		return depth[u] + depth[v] - 2*depth[lca(u,v)];
	}

	/*
		xからyにむかってdうごく
		dist(x,y) < d なら y を返す
		CF621 F
	*/
	int jump(int x,int y,int d){
		int z = lca(x,y);
		int d1 = depth[x]-depth[z];
		int d2 = depth[y]-depth[z];
		if(d <= d1){
			// up d from x
			rep(i,n+1) if(d&1<<i) x = par[x][i];
			return x;
		}else if(d <= d1+d2){
			// up d1+d2-d from y
			d = d1+d2-d;
			rep(i,n+1) if(d&1<<i) y = par[y][i];
			return y;
		}else{
			return y;
		}
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

