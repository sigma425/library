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


# :warning: math/bell_old.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/bell_old.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	ベル数(第二種スターリング数の和)
	グループに分ける方法の列挙
	B8=4140,B9=21147,B10=115975,B11=678570,...
	Nを代入してdfs(0)で全列挙
	より細かい分割がparts[]のindex小さい方にくることはない、つまりmergeするとidは減る (本当?)


	rep(i,K) rep(j,A) for(int k=j+1;k<A;k++)のところは 分割としてHasse図で直上のやつを全部探してる
	これをやることで「Xの細分全体」に再帰でアクセスできる(dfs2)ので包除とかに使える
	O((B_N)^2)とかになるのでN=9くらいまでっぽい(なんか包除するのにもっと良いオーダーのものがあるだろうか)
	↑包除の係数は1 -1 2 -6 24 -120 みたいになります
*/
typedef vector<int> vi;
typedef vector<vi> vv;
vector<vv> parts;
vv now;
map<vv,int> mp;
vector<int> G[21147];
int N,M;
void dfs(int x){
	if(x==N){
		mp[now]=parts.size();
		parts.pb(now);
		return;
	}
	rep(i,now.size()){
		now[i].pb(x);
		dfs(x+1);
		now[i].pop_back();
	}
	now.pb(vi(1,x));
	dfs(x+1);
	now.pop_back();
}

bool same(vv vs,int a,int b){
	int N=vs.size();
	int aa=-1,bb=-1;
	rep(i,N){
		for(int x:vs[i]){
			if(x==a) aa=i;
			if(x==b) bb=i;
		}
	}
	assert(aa>=0&&bb>=0);
	return aa==bb;
}
void showvv(vv vs){
	int N=vs.size();
	rep(i,N){
		cout<<"{";
		for(int x:vs[i]) cout<<x<<",";
		cout<<"}  ";
	}
	puts("");
}

long long calc[21147];
bool vis[21147];
int V;
void dfs2(int v){
	vis[v]=1;
	if(V!=v) calc[V]-=calc[v];
	for(int u:G[v]) if(!vis[u]) dfs2(u);
}

class Gxor{
	public:
	long long countsubs(vector <string> S){
		M=S.size();
		for(;;N++) if(N*(N-1)/2==S[0].size()) break;
		dfs(0);
		int K=parts.size();
		show(K);
		rep(i,K){
			int A=parts[i].size();
			rep(j,A) for(int k=j+1;k<A;k++){
				vv nv;
				rep(l,A){
					if(l==j){
						vi h=parts[i][j];
						h.insert(h.end(),all(parts[i][k]));
						sort(all(h));
						nv.pb(h);
					}else if(l!=k){
						nv.pb(parts[i][l]);
					}
				}
				assert(mp.count(nv));
				int id=mp[nv];
				G[id].pb(i);
			}
		}
		for(int i=K-1;i>=0;i--){		//partition small -> large
//			show(i);
			V=i;
			memset(vis,0,K);
			dfs2(i);
//			for(int j:G[i]) show(j),calc[i]-=calc[j];
//			puts("");
		}
		return calc[0];
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/bell_old.cpp"
/*
	ベル数(第二種スターリング数の和)
	グループに分ける方法の列挙
	B8=4140,B9=21147,B10=115975,B11=678570,...
	Nを代入してdfs(0)で全列挙
	より細かい分割がparts[]のindex小さい方にくることはない、つまりmergeするとidは減る (本当?)


	rep(i,K) rep(j,A) for(int k=j+1;k<A;k++)のところは 分割としてHasse図で直上のやつを全部探してる
	これをやることで「Xの細分全体」に再帰でアクセスできる(dfs2)ので包除とかに使える
	O((B_N)^2)とかになるのでN=9くらいまでっぽい(なんか包除するのにもっと良いオーダーのものがあるだろうか)
	↑包除の係数は1 -1 2 -6 24 -120 みたいになります
*/
typedef vector<int> vi;
typedef vector<vi> vv;
vector<vv> parts;
vv now;
map<vv,int> mp;
vector<int> G[21147];
int N,M;
void dfs(int x){
	if(x==N){
		mp[now]=parts.size();
		parts.pb(now);
		return;
	}
	rep(i,now.size()){
		now[i].pb(x);
		dfs(x+1);
		now[i].pop_back();
	}
	now.pb(vi(1,x));
	dfs(x+1);
	now.pop_back();
}

bool same(vv vs,int a,int b){
	int N=vs.size();
	int aa=-1,bb=-1;
	rep(i,N){
		for(int x:vs[i]){
			if(x==a) aa=i;
			if(x==b) bb=i;
		}
	}
	assert(aa>=0&&bb>=0);
	return aa==bb;
}
void showvv(vv vs){
	int N=vs.size();
	rep(i,N){
		cout<<"{";
		for(int x:vs[i]) cout<<x<<",";
		cout<<"}  ";
	}
	puts("");
}

long long calc[21147];
bool vis[21147];
int V;
void dfs2(int v){
	vis[v]=1;
	if(V!=v) calc[V]-=calc[v];
	for(int u:G[v]) if(!vis[u]) dfs2(u);
}

class Gxor{
	public:
	long long countsubs(vector <string> S){
		M=S.size();
		for(;;N++) if(N*(N-1)/2==S[0].size()) break;
		dfs(0);
		int K=parts.size();
		show(K);
		rep(i,K){
			int A=parts[i].size();
			rep(j,A) for(int k=j+1;k<A;k++){
				vv nv;
				rep(l,A){
					if(l==j){
						vi h=parts[i][j];
						h.insert(h.end(),all(parts[i][k]));
						sort(all(h));
						nv.pb(h);
					}else if(l!=k){
						nv.pb(parts[i][l]);
					}
				}
				assert(mp.count(nv));
				int id=mp[nv];
				G[id].pb(i);
			}
		}
		for(int i=K-1;i>=0;i--){		//partition small -> large
//			show(i);
			V=i;
			memset(vis,0,K);
			dfs2(i);
//			for(int j:G[i]) show(j),calc[i]-=calc[j];
//			puts("");
		}
		return calc[0];
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

