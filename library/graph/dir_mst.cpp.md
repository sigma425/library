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


# :warning: graph/dir_mst.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dir_mst.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
rを根とする最小有向全域木
O(NM)なので隣接で持っても構わない
d[][]に辺のcost or inf を入れた状態でdir_mstを呼ぶ 
*/
typedef pair<double,int> P;
int N,M,from[101],nid[101];
double inf=1e5,d[101][101],d2[101][101];
bool vis[101];
vector<int> cycle;
bool visit(int v,int s,int r){
	if(v==r) return 0;
	if(vis[v]) return v==s;
	cycle.pb(v);
	vis[v]=1;
	return visit(from[v],s,r);
}
double dir_mst(int r){	//root = r
	int S=N;
	bool update=1;
	while(update){
		update=0;
		double sco=0;
		rep(i,S){
			if(i==r) continue;
			P mn=P(inf,-1);
			rep(j,S) if(i!=j) mn=min(mn,P(d[j][i],j));
			if(mn.fs==inf) return inf;
			from[i]=mn.sc;
			sco+=mn.fs;
		}
		rep(i,S){
			if(i==r) continue;
			rep(j,S) vis[j]=0;
			cycle.clear();
			if(!visit(i,i,r)) continue;
			update=1;
			int len=cycle.size();
			cycle.pb(cycle[0]);
			int S2=S-len+1,it=0;
			rep(j,S){
				if(!vis[j]) nid[j]=it++;
				else nid[j]=-1;
			}
			r=nid[r];
			rep(j,S) if(nid[j]!=-1){
				rep(k,S) if(nid[k]!=-1){
					d2[nid[j]][nid[k]]=d[j][k];
				}
			}
			rep(j,S) if(nid[j]!=-1){
				double mn=inf;
				rep(k,S) if(nid[k]==-1) mn=min(mn,d[k][j]);
				d2[S2-1][nid[j]]=mn;
			}
			double csum=0;
			rep(j,len) csum+=d[cycle[j+1]][cycle[j]];
			rep(j,S) if(nid[j]!=-1){
				double mn=inf;
				rep(k,len){
					mn=min(mn,d[j][cycle[k]]+csum-d[cycle[k+1]][cycle[k]]);
				}
				d2[nid[j]][S2-1]=mn;
			}
			S=S2;
			rep(j,S) rep(k,S) d[j][k]=d2[j][k];
			break;
		}
		if(!update) return sco;
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dir_mst.cpp"
/*
rを根とする最小有向全域木
O(NM)なので隣接で持っても構わない
d[][]に辺のcost or inf を入れた状態でdir_mstを呼ぶ 
*/
typedef pair<double,int> P;
int N,M,from[101],nid[101];
double inf=1e5,d[101][101],d2[101][101];
bool vis[101];
vector<int> cycle;
bool visit(int v,int s,int r){
	if(v==r) return 0;
	if(vis[v]) return v==s;
	cycle.pb(v);
	vis[v]=1;
	return visit(from[v],s,r);
}
double dir_mst(int r){	//root = r
	int S=N;
	bool update=1;
	while(update){
		update=0;
		double sco=0;
		rep(i,S){
			if(i==r) continue;
			P mn=P(inf,-1);
			rep(j,S) if(i!=j) mn=min(mn,P(d[j][i],j));
			if(mn.fs==inf) return inf;
			from[i]=mn.sc;
			sco+=mn.fs;
		}
		rep(i,S){
			if(i==r) continue;
			rep(j,S) vis[j]=0;
			cycle.clear();
			if(!visit(i,i,r)) continue;
			update=1;
			int len=cycle.size();
			cycle.pb(cycle[0]);
			int S2=S-len+1,it=0;
			rep(j,S){
				if(!vis[j]) nid[j]=it++;
				else nid[j]=-1;
			}
			r=nid[r];
			rep(j,S) if(nid[j]!=-1){
				rep(k,S) if(nid[k]!=-1){
					d2[nid[j]][nid[k]]=d[j][k];
				}
			}
			rep(j,S) if(nid[j]!=-1){
				double mn=inf;
				rep(k,S) if(nid[k]==-1) mn=min(mn,d[k][j]);
				d2[S2-1][nid[j]]=mn;
			}
			double csum=0;
			rep(j,len) csum+=d[cycle[j+1]][cycle[j]];
			rep(j,S) if(nid[j]!=-1){
				double mn=inf;
				rep(k,len){
					mn=min(mn,d[j][cycle[k]]+csum-d[cycle[k+1]][cycle[k]]);
				}
				d2[nid[j]][S2-1]=mn;
			}
			S=S2;
			rep(j,S) rep(k,S) d[j][k]=d2[j][k];
			break;
		}
		if(!update) return sco;
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

