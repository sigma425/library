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


# :warning: math/LPsolver.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/LPsolver.cpp">View this file on GitHub</a>
    - Last commit date: 2019-03-14 22:42:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	LP
	max cx
	s.t. Ax <= b, x >= 0

	time complexity: exponential. fast $O(HW^2)$ in experiment. dependent on the modeling.
*/
template<class T>
struct LPsolver{
	const T eps = 1e-7;

	int type;
	T cx;
	V<T> sol;   //W

	// 0: found solution, 1: infeasible, 2: unbounded
	LPsolver(VV<T> A, V<T> b, V<T> c){
		int H = A.size(), W = A[0].size();
		assert((int)b.size() == H);
		assert((int)c.size() == W);

		Left.resize(H);
		Down.resize(W);
		sol.resize(W);
		cx = 0;

		auto pivot = [&](int x, int y) {
			swap(Left[x], Down[y]);
			T k = A[x][y];
			A[x][y] = 1;
			vector<int> nz;
			rep(i,W){
				A[x][i] /= k;
				if (!eq(A[x][i], 0)) nz.push_back(i);
			}
			b[x] /= k;

			rep(i,H){
				if (i == x || eq(A[i][y], 0)) continue;
				k = A[i][y];
				A[i][y] = 0;
				b[i] -= k * b[x];
				for (int j : nz) A[i][j] -= k * A[x][j];
			}
			if (eq(c[y], 0)) return;
			k = c[y];
			c[y] = 0;
			cx += k * b[x];
			for (int i : nz) c[i] -= k * A[x][i];
		};

		rep(i,W) Down[i] = i;
		rep(i,H) Left[i] = W + i;
		while (1) { // Eliminating negative b[i]
			int x = -1, y = -1;
			rep(i,H) if(ls(b[i], 0) && (x == -1 || b[i] < b[x])) x = i;
			if (x == -1) break;
			rep(i,W) if(ls(A[x][i], 0) && (y == -1 || A[x][i] < A[x][y])) y = i;
			if (y == -1){
				type = 1;   //infeasible
				cx = -1e100;
				return;
			}
			pivot(x, y);
		}
		while (1) {
			int x = -1, y = -1;
			rep(i,W) if(ls(0, c[i]) && (y == -1 || c[i] > c[y])) y = i;
			if (y == -1) break;
			rep(i,H) if(ls(0, A[i][y]) && (x == -1 || b[i] / A[i][y] < b[x] / A[x][y])) x = i;
			if (x == -1){
				type = 2;   //unbounded
				cx = 1e100;
				return;
			}
			pivot(x, y);
		}
		rep(i,H) if (Left[i] < W) sol[Left[i]] = b[i];
		type = 0;
	}

	V<int> Left,Down;   //H,W
	bool eq(T a, T b) { return fabs(a - b) < eps; }
	bool ls(T a, T b) { return a < b && !eq(a, b); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/LPsolver.cpp"
/*
	LP
	max cx
	s.t. Ax <= b, x >= 0

	time complexity: exponential. fast $O(HW^2)$ in experiment. dependent on the modeling.
*/
template<class T>
struct LPsolver{
	const T eps = 1e-7;

	int type;
	T cx;
	V<T> sol;   //W

	// 0: found solution, 1: infeasible, 2: unbounded
	LPsolver(VV<T> A, V<T> b, V<T> c){
		int H = A.size(), W = A[0].size();
		assert((int)b.size() == H);
		assert((int)c.size() == W);

		Left.resize(H);
		Down.resize(W);
		sol.resize(W);
		cx = 0;

		auto pivot = [&](int x, int y) {
			swap(Left[x], Down[y]);
			T k = A[x][y];
			A[x][y] = 1;
			vector<int> nz;
			rep(i,W){
				A[x][i] /= k;
				if (!eq(A[x][i], 0)) nz.push_back(i);
			}
			b[x] /= k;

			rep(i,H){
				if (i == x || eq(A[i][y], 0)) continue;
				k = A[i][y];
				A[i][y] = 0;
				b[i] -= k * b[x];
				for (int j : nz) A[i][j] -= k * A[x][j];
			}
			if (eq(c[y], 0)) return;
			k = c[y];
			c[y] = 0;
			cx += k * b[x];
			for (int i : nz) c[i] -= k * A[x][i];
		};

		rep(i,W) Down[i] = i;
		rep(i,H) Left[i] = W + i;
		while (1) { // Eliminating negative b[i]
			int x = -1, y = -1;
			rep(i,H) if(ls(b[i], 0) && (x == -1 || b[i] < b[x])) x = i;
			if (x == -1) break;
			rep(i,W) if(ls(A[x][i], 0) && (y == -1 || A[x][i] < A[x][y])) y = i;
			if (y == -1){
				type = 1;   //infeasible
				cx = -1e100;
				return;
			}
			pivot(x, y);
		}
		while (1) {
			int x = -1, y = -1;
			rep(i,W) if(ls(0, c[i]) && (y == -1 || c[i] > c[y])) y = i;
			if (y == -1) break;
			rep(i,H) if(ls(0, A[i][y]) && (x == -1 || b[i] / A[i][y] < b[x] / A[x][y])) x = i;
			if (x == -1){
				type = 2;   //unbounded
				cx = 1e100;
				return;
			}
			pivot(x, y);
		}
		rep(i,H) if (Left[i] < W) sol[Left[i]] = b[i];
		type = 0;
	}

	V<int> Left,Down;   //H,W
	bool eq(T a, T b) { return fabs(a - b) < eps; }
	bool ls(T a, T b) { return a < b && !eq(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

