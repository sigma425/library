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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: data structure/2D/2Dseg_BIT.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#eb0b63dc6df90e849fe933d9d9d16989">data structure/2D</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/2D/2Dseg_BIT.cpp">View this file on GitHub</a>
    - Last commit date: 2018-05-18 18:37:56+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	point add range sum in 2D (N*N grid)
	!!!!!追加や削除される点の集合が先にわかっている場合!!!!! しか使えない 点更新はあってもいい 点更新がないなら time sweep で 1D でいける
	別に点集合が permutation みたいになってる必要とかはない
	http://sigma425.hatenablog.com/entry/2016/03/13/180106 のBITのとこに書いてあるやつ
	先に全部あるとしてからマージソートっぽい列を持つsegtreeを作っておいて、各ノードがBITを持つ
	O(log^2N) per query で splay tree をsegtreeに載せてるのと同じ計算量だけど、定数倍がかなりいいと思う 4倍くらいだった N = 10^5 で 0.5sec くらい

	しかも点に重みつけるのも簡単!

	usage:
		segtree seg( size of grid, candidate points );
		int count(x,y) //return sum of [0,x) * [0,y)
		void add(int x,int y)

	verified at atcoder/snuke/J (Drink Bar)
*/

struct BIT{
	using D = int;
	int N;
	vector<D> bit;

	BIT(int n){		//nは区間幅!!!
		N=n;
		bit.assign(n+1,0);
	}
	BIT(){}

	D sum(int i){		//i個の和a[0]+..a[i-1]
		D s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	void add(int i,D x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
};

struct segtree2D{
	int N;	//[0,N) * [0,N)
	vector<BIT> bit;
	vector<vector<int>> vals;

	//build with candidate points
	segtree2D(int n, vector<pair<int,int>> ps){
		int p2=1;
		while(p2<n) p2*=2;
		N=p2;
		bit.resize(N*2);
		vals.resize(N*2);

		int K = ps.size();

		rep(i,K){
			int x = ps[i].fs, y = ps[i].sc;
			vals[x+N].pb(y);
		}
		for(int i=N;i<2*N;i++){
			sort(all(vals[i]));
			vals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());
		}
		for(int i=N-1;i>0;i--){
			vals[i].resize(vals[i*2].size()+vals[i*2+1].size());
			merge(all(vals[i*2]),all(vals[i*2+1]),vals[i].begin());
			vals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());
		}
		for(int i=1;i<2*N;i++){
			bit[i] = BIT(vals[i].size());
		}
	}

	void add(int x,int y){			//add P(x,y)
		x+=N;
		while(x){
			int yid = lower_bound(all(vals[x]),y) - vals[x].begin();
			bit[x].add(yid,1);		//if weighted change this '1'
			x/=2;
		}
	}
	int count(int a,int b,int ya,int yb,int l,int r,int k){		//[a,b) * [ya,yb)
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b){
			int yaid = lower_bound(all(vals[k]),ya) - vals[k].begin();
			int ybid = lower_bound(all(vals[k]),yb) - vals[k].begin();
			return bit[k].sum(ybid) - bit[k].sum(yaid);
		}
		return count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);
	}
	int count(int a,int b){
//		printf("count [0,%d)*[0,%d)\n",a,b);
		return count(0,a,0,b,0,N,1);
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/2D/2Dseg_BIT.cpp"
/*
	point add range sum in 2D (N*N grid)
	!!!!!追加や削除される点の集合が先にわかっている場合!!!!! しか使えない 点更新はあってもいい 点更新がないなら time sweep で 1D でいける
	別に点集合が permutation みたいになってる必要とかはない
	http://sigma425.hatenablog.com/entry/2016/03/13/180106 のBITのとこに書いてあるやつ
	先に全部あるとしてからマージソートっぽい列を持つsegtreeを作っておいて、各ノードがBITを持つ
	O(log^2N) per query で splay tree をsegtreeに載せてるのと同じ計算量だけど、定数倍がかなりいいと思う 4倍くらいだった N = 10^5 で 0.5sec くらい

	しかも点に重みつけるのも簡単!

	usage:
		segtree seg( size of grid, candidate points );
		int count(x,y) //return sum of [0,x) * [0,y)
		void add(int x,int y)

	verified at atcoder/snuke/J (Drink Bar)
*/

struct BIT{
	using D = int;
	int N;
	vector<D> bit;

	BIT(int n){		//nは区間幅!!!
		N=n;
		bit.assign(n+1,0);
	}
	BIT(){}

	D sum(int i){		//i個の和a[0]+..a[i-1]
		D s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	void add(int i,D x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
};

struct segtree2D{
	int N;	//[0,N) * [0,N)
	vector<BIT> bit;
	vector<vector<int>> vals;

	//build with candidate points
	segtree2D(int n, vector<pair<int,int>> ps){
		int p2=1;
		while(p2<n) p2*=2;
		N=p2;
		bit.resize(N*2);
		vals.resize(N*2);

		int K = ps.size();

		rep(i,K){
			int x = ps[i].fs, y = ps[i].sc;
			vals[x+N].pb(y);
		}
		for(int i=N;i<2*N;i++){
			sort(all(vals[i]));
			vals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());
		}
		for(int i=N-1;i>0;i--){
			vals[i].resize(vals[i*2].size()+vals[i*2+1].size());
			merge(all(vals[i*2]),all(vals[i*2+1]),vals[i].begin());
			vals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());
		}
		for(int i=1;i<2*N;i++){
			bit[i] = BIT(vals[i].size());
		}
	}

	void add(int x,int y){			//add P(x,y)
		x+=N;
		while(x){
			int yid = lower_bound(all(vals[x]),y) - vals[x].begin();
			bit[x].add(yid,1);		//if weighted change this '1'
			x/=2;
		}
	}
	int count(int a,int b,int ya,int yb,int l,int r,int k){		//[a,b) * [ya,yb)
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b){
			int yaid = lower_bound(all(vals[k]),ya) - vals[k].begin();
			int ybid = lower_bound(all(vals[k]),yb) - vals[k].begin();
			return bit[k].sum(ybid) - bit[k].sum(yaid);
		}
		return count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);
	}
	int count(int a,int b){
//		printf("count [0,%d)*[0,%d)\n",a,b);
		return count(0,a,0,b,0,N,1);
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

