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


# :warning: math/bell.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/bell.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
Bell
区別のつくN個のものを区別の付かない箱に分割するようなものを列挙

bell.init(N)で列挙が終了,返り値はbell数.
unionfindで表現していて、bell.UFs[id] がid個めの状態を表す.
[0]が全てバラバラのもので、[B-1]が全部連結のもの.
0,...,B-1がちゃんとトポロジカル順序になっている(bfsをしているため,N-連結成分の個数が距離になるので)
bfsのとこのid->nidのところで全遷移が得られている.この時点で->idなる遷移は全て得られている(上と同様の理由)ので、ここで直接DPを書いたほうがいいかも

下の使用例では外から呼んでいて、どの連結成分を繋いだらどれに遷移するか(UF2idを使う)を見ている

*/
struct unionfind{
	int par[15];
	void init(int N){rep(i,N) par[i]=i;}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(x>y) swap(x,y);		//roots have the smallest id
		par[y]=x;
	}
};
struct Bell{
	//(1, )1, 2, 5, 15, 52,
	//203, 877, 4140, 21147, 115975,
	//678570, 4213597, 27644437, 190899322, 1382958545
	
	vector<unionfind> UFs;

	typedef vector<int> VI;
	int N;
	map<VI,int> VI2id;
	queue<int> que;

	VI UF2VI(unionfind UF){
		VI vi(N);
		rep(i,N) vi[i]=UF.find(i);
		return vi;
	}
	int add(unionfind UF){
		VI vi = UF2VI(UF);
		int id = UFs.size();
		VI2id[vi]=id;
		UFs.pb(UF);
		que.push(id);
		return id;
	}
	int UF2id(unionfind UF){
		VI vi = UF2VI(UF);
		if(VI2id.count(vi)) return VI2id[vi];
		return -1;
	}

	void bfs(){
		while(!que.empty()){
			int id = que.front();que.pop();
//			printf("id%d -> ",id);
//			show(UF2VI(UFs[id]));
			VI roots;
			rep(i,N) if(UFs[id].find(i)==i) roots.pb(i);
			int K=roots.size();
			rep(i,K) rep(j,i){
				unionfind UF = UFs[id];
				UF.unite(roots[i],roots[j]);
				int nid;
				if((nid=UF2id(UF))==-1){
					nid = add(UF);
				}
				//id->nid
//				printf("id%d->nid%d\n",id,nid);
			}
		}
	}
	int init(int N_){		//enum partitions
		N=N_;
		unionfind UF;
		UF.init(N);
		add(UF);
		bfs();
		return UFs.size();
	}


}bell;
const int B8=4140;

bool e[8][8];
ll dp[B8];
int main(){
	int N,M;
	cin>>N>>M;
	int B = bell.init(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		e[a][b]=e[b][a]=1;
	}
	rep(id,B){
//		printf("dp[%d]=%I64d\n",id,dp[id]);
		if(id==B-1) break;
		vector<int> roots;
		rep(i,N) if(bell.UFs[id].find(i)==i) roots.pb(i);
		int K=roots.size();
		int cnt = 0;
		rep(i,N) rep(j,i) if(e[i][j]&&bell.UFs[id].same(i,j)) cnt++;

		rep(i,K) rep(j,i){
			unionfind UF = bell.UFs[id];
			int cand = 0;
			rep(a,N) rep(b,N) if(e[a][b]&&UF.find(a)==roots[i]&&UF.find(b)==roots[j]) cand++;
			if(cand==0) continue;

			UF.unite(roots[i],roots[j]);
			int nid=bell.UF2id(UF);
			//id->nid
			ll tmp = dp[id]*cand;
			dp[nid] += tmp;
//				printf("dp[%d] += %I64d\n",nid,tmp);
		}
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/bell.cpp"
/*
Bell
区別のつくN個のものを区別の付かない箱に分割するようなものを列挙

bell.init(N)で列挙が終了,返り値はbell数.
unionfindで表現していて、bell.UFs[id] がid個めの状態を表す.
[0]が全てバラバラのもので、[B-1]が全部連結のもの.
0,...,B-1がちゃんとトポロジカル順序になっている(bfsをしているため,N-連結成分の個数が距離になるので)
bfsのとこのid->nidのところで全遷移が得られている.この時点で->idなる遷移は全て得られている(上と同様の理由)ので、ここで直接DPを書いたほうがいいかも

下の使用例では外から呼んでいて、どの連結成分を繋いだらどれに遷移するか(UF2idを使う)を見ている

*/
struct unionfind{
	int par[15];
	void init(int N){rep(i,N) par[i]=i;}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(x>y) swap(x,y);		//roots have the smallest id
		par[y]=x;
	}
};
struct Bell{
	//(1, )1, 2, 5, 15, 52,
	//203, 877, 4140, 21147, 115975,
	//678570, 4213597, 27644437, 190899322, 1382958545
	
	vector<unionfind> UFs;

	typedef vector<int> VI;
	int N;
	map<VI,int> VI2id;
	queue<int> que;

	VI UF2VI(unionfind UF){
		VI vi(N);
		rep(i,N) vi[i]=UF.find(i);
		return vi;
	}
	int add(unionfind UF){
		VI vi = UF2VI(UF);
		int id = UFs.size();
		VI2id[vi]=id;
		UFs.pb(UF);
		que.push(id);
		return id;
	}
	int UF2id(unionfind UF){
		VI vi = UF2VI(UF);
		if(VI2id.count(vi)) return VI2id[vi];
		return -1;
	}

	void bfs(){
		while(!que.empty()){
			int id = que.front();que.pop();
//			printf("id%d -> ",id);
//			show(UF2VI(UFs[id]));
			VI roots;
			rep(i,N) if(UFs[id].find(i)==i) roots.pb(i);
			int K=roots.size();
			rep(i,K) rep(j,i){
				unionfind UF = UFs[id];
				UF.unite(roots[i],roots[j]);
				int nid;
				if((nid=UF2id(UF))==-1){
					nid = add(UF);
				}
				//id->nid
//				printf("id%d->nid%d\n",id,nid);
			}
		}
	}
	int init(int N_){		//enum partitions
		N=N_;
		unionfind UF;
		UF.init(N);
		add(UF);
		bfs();
		return UFs.size();
	}


}bell;
const int B8=4140;

bool e[8][8];
ll dp[B8];
int main(){
	int N,M;
	cin>>N>>M;
	int B = bell.init(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		e[a][b]=e[b][a]=1;
	}
	rep(id,B){
//		printf("dp[%d]=%I64d\n",id,dp[id]);
		if(id==B-1) break;
		vector<int> roots;
		rep(i,N) if(bell.UFs[id].find(i)==i) roots.pb(i);
		int K=roots.size();
		int cnt = 0;
		rep(i,N) rep(j,i) if(e[i][j]&&bell.UFs[id].same(i,j)) cnt++;

		rep(i,K) rep(j,i){
			unionfind UF = bell.UFs[id];
			int cand = 0;
			rep(a,N) rep(b,N) if(e[a][b]&&UF.find(a)==roots[i]&&UF.find(b)==roots[j]) cand++;
			if(cand==0) continue;

			UF.unite(roots[i],roots[j]);
			int nid=bell.UF2id(UF);
			//id->nid
			ll tmp = dp[id]*cand;
			dp[nid] += tmp;
//				printf("dp[%d] += %I64d\n",nid,tmp);
		}
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

