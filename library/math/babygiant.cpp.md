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


# :warning: math/babygiant.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/babygiant.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//g in group G, x in set X
//G,Xをclassでなくtypedefにするときは==の条件とかに注意
const int BN,GN;
X act(G g,X x){

}
G pro(G f,G g){

}
G ex(G g,int N){
	G e=;
	while(N){
		if(N%2) e=pro(g,e);
		g=pro(g,g);
		N>>=1;
	}
	return e;
}
ll solve2(G g,X s,X t){		//calc min k s.t.{g^n(s)=t}		if no ans, -1
	if(s==t) return 0;
	pair<X,int> babies[BN];
	rep(i,BN){	//0~BN-1
		babies[i]=mp(t,i);
		t=act(g,t);
	}
	sort(babies,babies+BN);
	g=ex(g,BN);	//g->g^BN
	rep1(i,GN){		//1~GN
		s=act(g,s);
		int pos=upper_bound(babies,babies+BN,mp(s,BN))-babies-1;
		if(pos>=0&&babies[pos].fs==s) return i*BN-babies[pos].sc;
	}
	return -1;
}
ll solve(G g,X s,X t){		//calc next some times
	if(s==t) return 0;
	rep1(i,){
		s=act(g,s);
		if(s==t) return i;
	}
	//処理
	ll tmp=solve2();
	if(tmp>=0) return tmp+;
	return -1;
}
ll brute(G g,X s,X t){
	if(s==t) return 0;
	rep(i,1000000){
		s=act(g,s);
		if(s==t) return i+1;
	}
	return -1;
}
int main(){
	
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/babygiant.cpp"
//g in group G, x in set X
//G,Xをclassでなくtypedefにするときは==の条件とかに注意
const int BN,GN;
X act(G g,X x){

}
G pro(G f,G g){

}
G ex(G g,int N){
	G e=;
	while(N){
		if(N%2) e=pro(g,e);
		g=pro(g,g);
		N>>=1;
	}
	return e;
}
ll solve2(G g,X s,X t){		//calc min k s.t.{g^n(s)=t}		if no ans, -1
	if(s==t) return 0;
	pair<X,int> babies[BN];
	rep(i,BN){	//0~BN-1
		babies[i]=mp(t,i);
		t=act(g,t);
	}
	sort(babies,babies+BN);
	g=ex(g,BN);	//g->g^BN
	rep1(i,GN){		//1~GN
		s=act(g,s);
		int pos=upper_bound(babies,babies+BN,mp(s,BN))-babies-1;
		if(pos>=0&&babies[pos].fs==s) return i*BN-babies[pos].sc;
	}
	return -1;
}
ll solve(G g,X s,X t){		//calc next some times
	if(s==t) return 0;
	rep1(i,){
		s=act(g,s);
		if(s==t) return i;
	}
	//処理
	ll tmp=solve2();
	if(tmp>=0) return tmp+;
	return -1;
}
ll brute(G g,X s,X t){
	if(s==t) return 0;
	rep(i,1000000){
		s=act(g,s);
		if(s==t) return i+1;
	}
	return -1;
}
int main(){
	
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

