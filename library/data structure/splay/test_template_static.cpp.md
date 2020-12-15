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


# :warning: data structure/splay/test_template_static.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a139cdef544a41bbe9de0547a0bc58bb">data structure/splay</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/splay/test_template_static.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;
/*	OK
template<class T>
struct A{
	static int i;
	T x;
};
template<> int A<int>::i=0;
*/
/*	OK
template<class T>
struct A{
	static int i;
	T x;
};
template<class T> int A<T>::i=0;
*/
template<class T>
struct A{
	struct Ta{
		T t;
		Ta(){}
	};
	static Ta x;
};
template<class T> typename A<T>::Ta A<T>::x=Ta();

int main(){
	cout << A<int>::x.t <<endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/splay/test_template_static.cpp"
#include <bits/stdc++.h>
using namespace std;
/*	OK
template<class T>
struct A{
	static int i;
	T x;
};
template<> int A<int>::i=0;
*/
/*	OK
template<class T>
struct A{
	static int i;
	T x;
};
template<class T> int A<T>::i=0;
*/
template<class T>
struct A{
	struct Ta{
		T t;
		Ta(){}
	};
	static Ta x;
};
template<class T> typename A<T>::Ta A<T>::x=Ta();

int main(){
	cout << A<int>::x.t <<endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

