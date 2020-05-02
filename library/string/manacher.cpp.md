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


# :warning: string/manacher.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	R[i] = s[i] を中心とする最長回文の半径((len+1)/2)
	s:abaaababa
	R:121412321

 	偶数長も考えたいときは
	s:a$b$a$a$a$b$a$b$a

	文字列じゃないものに使うとき,1文字を回分とみなしてはいけない場合もある
	その場合は
	R[i]=j;
	if(R[i]==0){
		i++,j=0;
		continue;
	}
	でOK
*/
vector<int> manacher(string s){
	int N = s.size();
	vector<int> R(N);
	int i=0,j=0;
	while(i < N){
		while(i-j>=0 && i+j<N && s[i-j]==s[i+j]) ++j;
		R[i] = j;
		int k = 1;
		while(i-k>=0 && i+k<N && k+R[i-k]<j) R[i+k]=R[i-k],++k;
		i+=k,j-=k;
	}
	return R;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/manacher.cpp"
/*
	R[i] = s[i] を中心とする最長回文の半径((len+1)/2)
	s:abaaababa
	R:121412321

 	偶数長も考えたいときは
	s:a$b$a$a$a$b$a$b$a

	文字列じゃないものに使うとき,1文字を回分とみなしてはいけない場合もある
	その場合は
	R[i]=j;
	if(R[i]==0){
		i++,j=0;
		continue;
	}
	でOK
*/
vector<int> manacher(string s){
	int N = s.size();
	vector<int> R(N);
	int i=0,j=0;
	while(i < N){
		while(i-j>=0 && i+j<N && s[i-j]==s[i+j]) ++j;
		R[i] = j;
		int k = 1;
		while(i-k>=0 && i+k<N && k+R[i-k]<j) R[i+k]=R[i-k],++k;
		i+=k,j-=k;
	}
	return R;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

