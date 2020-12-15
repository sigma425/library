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


# :warning: string/Z.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/Z.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	Z-algorithm
	the longest common prefix of S and S[i~]
	s: aaabaaaab
	Z: 921034210

    s[i~] と t の common prefix も t+"$"+s に対して呼べば求まる
*/
vector<int> Zalgo(string s){
	int N = s.size();
	vector<int> Z(N);
	Z[0] = N;
	int i = 1, j = 0;
	while(i<N){
		while(i+j<N && s[j]==s[i+j]) ++j;
		Z[i] = j;
		if(j==0){
			++i;
			continue;
		}
		int k = 1;
		while(i+k<N && k+Z[k]<j) Z[i+k]=Z[k],++k;
		i += k, j -= k;
	}
	return Z;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/Z.cpp"
/*
	Z-algorithm
	the longest common prefix of S and S[i~]
	s: aaabaaaab
	Z: 921034210

    s[i~] と t の common prefix も t+"$"+s に対して呼べば求まる
*/
vector<int> Zalgo(string s){
	int N = s.size();
	vector<int> Z(N);
	Z[0] = N;
	int i = 1, j = 0;
	while(i<N){
		while(i+j<N && s[j]==s[i+j]) ++j;
		Z[i] = j;
		if(j==0){
			++i;
			continue;
		}
		int k = 1;
		while(i+k<N && k+Z[k]<j) Z[i+k]=Z[k],++k;
		i += k, j -= k;
	}
	return Z;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

