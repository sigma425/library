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


# :warning: math/matrix/matrix_new.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a9839e7477a4d9c748aee996b52a14d5">math/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix/matrix_new.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-21 23:35:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T>
Matrix<T> inv(const Matrix<T>& A){
	assert(A.H==A.W);
	int N = A.H;
	Matrix<T> X(N,2*N);
	rep(i,N) rep(j,N) X.set(i,j,A.at(i,j));
	rep(i,N) X.set(i,i+N,T(1));
	int rank = X.sweep(N);
	if(rank < N) return Matrix<T>();
	Matrix<T> B(N,N);
	rep(i,N){
		rep(j,N){
			B.set(i,j,X.at(i,j+N));
		}
	}
	return B;
}

/*
	Ax = b の解をひとつ返す
	存在しないなら {}

	解空間を得たい → これ + kernel(A)

	式が0個(i.e. A.empty()) になりうるときはちゃんとvarnumを指定する
*/
template<class T>
vector<T> solveLinearEquation(const Matrix<T>& A, vector<T> b, int varnum = -1){
	assert(A.H==(int)b.size());
	assert(A.H > 0 || varnum != -1);
	int H = A.H, W = (A.H == 0 ? varnum : A.W);

	Matrix<T> X(H,W+1);
	rep(i,H) rep(j,W) X.set(i,j,A.at(i,j));
	rep(i,H) X.set(i,W,b[i]);
	int rank = X.sweep(W);
	rep(i,H){
		bool allzero = true;
		rep(j,W) if(!iszero(X.at(i,j))) allzero = false;
		if(allzero){
			if(!iszero(X.at(i,W))){		//0x + 0y + 0z = non0
				return vector<T>();
			}
		}
	}
	vector<bool> done(H);
	vector<T> x(W);
	rep(j,W){
		int c0 = 0, c1 = 0;
		int I = -1;
		rep(i,H){
			if(iszero(X.at(i,j))) c0++;
			else if(isone(X.at(i,j))) c1++,I=i;
		}
		if(c0==H-1 && c1==1 && !done[I]){
			x[j] = X.at(I,W);
			done[I] = true;
		}
	}
	return x;
}

template<class T>
VV<T> kernel(const Matrix<T>& A, int varnum = -1){
	assert(A.H > 0 || varnum != -1);
	int H = A.H, W = (A.H == 0 ? varnum : A.W);
	Matrix B(W,H+W);
	rep(i,H) rep(j,W) B.set(j,i,A.at(i,j));
	rep(i,W) B.set(i,i+H,T(1));
	int r = 
}

/*
	determinant
*/
template<class T>
T det(VV<T> a){
	const int N = a.size();
	assert(N>0 && int(a[0].size()) == N);
	T ans(1);
	rep(i,N){
		for(int j=i+1;j<N;j++) if(!iszero(a[j][i])){
			ans = -ans;
			swap(a[j],a[i]);
			break;
		}
		if(iszero(a[i][i])) return T(0);
		ans *= a[i][i];
		for(int j=i+1;j<N;j++){
			mint w = -a[j][i]/a[i][i];
			for(int k=i;k<N;k++) a[j][k] += a[i][k]*w;
		}
	}
	return ans;
}

/*
	rank
*/
template<class T>
int getrank(VV<T> a){
	return A.sweep(A.W);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix/matrix_new.cpp"
template<class T>
Matrix<T> inv(const Matrix<T>& A){
	assert(A.H==A.W);
	int N = A.H;
	Matrix<T> X(N,2*N);
	rep(i,N) rep(j,N) X.set(i,j,A.at(i,j));
	rep(i,N) X.set(i,i+N,T(1));
	int rank = X.sweep(N);
	if(rank < N) return Matrix<T>();
	Matrix<T> B(N,N);
	rep(i,N){
		rep(j,N){
			B.set(i,j,X.at(i,j+N));
		}
	}
	return B;
}

/*
	Ax = b の解をひとつ返す
	存在しないなら {}

	解空間を得たい → これ + kernel(A)

	式が0個(i.e. A.empty()) になりうるときはちゃんとvarnumを指定する
*/
template<class T>
vector<T> solveLinearEquation(const Matrix<T>& A, vector<T> b, int varnum = -1){
	assert(A.H==(int)b.size());
	assert(A.H > 0 || varnum != -1);
	int H = A.H, W = (A.H == 0 ? varnum : A.W);

	Matrix<T> X(H,W+1);
	rep(i,H) rep(j,W) X.set(i,j,A.at(i,j));
	rep(i,H) X.set(i,W,b[i]);
	int rank = X.sweep(W);
	rep(i,H){
		bool allzero = true;
		rep(j,W) if(!iszero(X.at(i,j))) allzero = false;
		if(allzero){
			if(!iszero(X.at(i,W))){		//0x + 0y + 0z = non0
				return vector<T>();
			}
		}
	}
	vector<bool> done(H);
	vector<T> x(W);
	rep(j,W){
		int c0 = 0, c1 = 0;
		int I = -1;
		rep(i,H){
			if(iszero(X.at(i,j))) c0++;
			else if(isone(X.at(i,j))) c1++,I=i;
		}
		if(c0==H-1 && c1==1 && !done[I]){
			x[j] = X.at(I,W);
			done[I] = true;
		}
	}
	return x;
}

template<class T>
VV<T> kernel(const Matrix<T>& A, int varnum = -1){
	assert(A.H > 0 || varnum != -1);
	int H = A.H, W = (A.H == 0 ? varnum : A.W);
	Matrix B(W,H+W);
	rep(i,H) rep(j,W) B.set(j,i,A.at(i,j));
	rep(i,W) B.set(i,i+H,T(1));
	int r = 
}

/*
	determinant
*/
template<class T>
T det(VV<T> a){
	const int N = a.size();
	assert(N>0 && int(a[0].size()) == N);
	T ans(1);
	rep(i,N){
		for(int j=i+1;j<N;j++) if(!iszero(a[j][i])){
			ans = -ans;
			swap(a[j],a[i]);
			break;
		}
		if(iszero(a[i][i])) return T(0);
		ans *= a[i][i];
		for(int j=i+1;j<N;j++){
			mint w = -a[j][i]/a[i][i];
			for(int k=i;k<N;k++) a[j][k] += a[i][k]*w;
		}
	}
	return ans;
}

/*
	rank
*/
template<class T>
int getrank(VV<T> a){
	return A.sweep(A.W);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

