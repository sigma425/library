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


# :warning: math/matrix/matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a9839e7477a4d9c748aee996b52a14d5">math/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-10 18:00:49+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	行列の基本演算, 連立一次方程式の解, 逆行列 とか
	template 引数 T は体である必要がある
	+,-,*,/, unary -
	の他に, zero, one, iszero(), isone() がいる
	浮動小数点とかのためにiszeroとかは==zeroを避けている

	usage:
		field class (mintとか) を用意する
		zero,one,iszero(),isone()を書く

	solveLinearEquationに0個の式を入れると横幅が取得できず[0].size() で segfault ので注意

	complexity:
		sweep系はすべて O(rank * H * W)
		rankが小さいと勝手に計算量は減る

	verified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624 (solveLinearEquarion mod 2)
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (sLE on Rationals)

*/

template<class T>
struct Matrix{
	int H,W;
	VV<T> a;

	Matrix() : H(0),W(0){}
	Matrix(int H,int W) : H(H),W(W),a( VV<T>(H,V<T>(W)) ){}
	Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v){}

	static Matrix E(int n){
		Matrix a(n,n);
		rep(i,n) a.set(i,i,1);
		return a;
	}

	T at(int i,int j) const {
		return a[i][j];
	}
	void set(int i,int j,T v){
		a[i][j] = v;
	}

	Matrix operator+(const Matrix& r) const {
		assert(H==r.H && W==r.W);
		VV<T> v(H,V<T>(W));
		rep(i,H) rep(j,W) v[i][j] = a[i][j] + r.a[i][j];
		return Matrix(v);
	}
	Matrix operator-(const Matrix& r) const {
		assert(H==r.H && W==r.W);
		VV<T> v(H,V<T>(W));
		rep(i,H) rep(j,W) v[i][j] = a[i][j] - r.a[i][j];
		return Matrix(v);
	}
	Matrix operator*(const Matrix& r) const {
		assert(W==r.H);
		VV<T> v(H,V<T>(r.W));
		rep(i,H) rep(k,W) rep(j,r.W) v[i][j] += a[i][k] * r.a[k][j];
		return Matrix(v);
	}
	Matrix& operator+=(const Matrix& r){return (*this)=(*this)+r;}
	Matrix& operator-=(const Matrix& r){return (*this)=(*this)-r;}
	Matrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}

	Matrix pow(ll p) const {
		assert(H == W);
		Matrix a = E(H);
		Matrix x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}

	friend ostream& operator<<(ostream &o,const Matrix& A){
		rep(i,A.H){
			rep(j,A.W) o<<A.a[i][j]<<" ";
			o<<endl;
		}
		return o;
	}

	/*
		副作用がある, 基本的に自分でこれを呼ぶことはない
		掃き出し法をする
		左からvar列が掃き出す対象で、それより右は同時に値を変更するだけ(e.g. 逆行列は右に単位行列おいてから掃き出す)
		行swap, 列swap は行わない

		rank を返す
	*/
	int sweep(int var){
		int rank = 0;
		vector<bool> used(H);
		rep(j,var){
			int i=0;
			while(i<H && (used[i]||iszero(a[i][j]))) i++;
			if(i==H) continue;
			used[i] = true;
			rank++;
			T t = a[i][j];
			rep(k,W) a[i][k] = a[i][k]/t;
			rep(k,H) if(k!=i){
				T t = a[k][j];
				rep(l,W) a[k][l] = a[k][l]-a[i][l]*t;
			}
		}
		return rank;
	}

};

/*
	逆行列を返す
	なければ0*0行列
*/
template<class T>
Matrix<T> inv(const Matrix<T>& A){
	assert(A.H==A.W);
	int N = A.H;
	Matrix<T> X(N,2*N);
	rep(i,N) rep(j,N) X.set(i,j,A.at(i,j));
	rep(i,N) X.set(i,i+N,one);
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
	Ax = b を解く
	pair(解空間の次元, 解のうちひとつ) を返す
	解が存在しないなら(-1,{})

	解を複数得たい → ランダムな式を追加?
*/
template<class T>
pair< int, vector<T> > solveLinearEquation(const Matrix<T>& A, vector<T> b){
	assert(A.H==(int)b.size());
	int H = A.H, W = A.W;

	Matrix<T> X(H,W+1);
	rep(i,H) rep(j,W) X.set(i,j,A.at(i,j));
	rep(i,H) X.set(i,W,b[i]);
	int rank = X.sweep(W);
	rep(i,H){
		bool allzero = true;
		rep(j,W) if(!iszero(X.at(i,j))) allzero = false;
		if(allzero){
			if(!iszero(X.at(i,W))){		//0x + 0y + 0z = non0
				return pair<int,vector<T> >(-1,vector<T>());
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
	return pair<int,vector<T> >(W-rank,x);
}

/*
	determinant
*/
template<class T>
T det(Matrix<T> A){
	assert(A.H==A.W);
	int N = A.H;
	int rank = A.sweep(N);
	if(rank < N) return zero;
	T d = one;
	vector<int> to(N);
	rep(i,N){
		rep(j,N){
			if(!iszero(A.at(i,j))){
				to[i] = j;
				d *= A.at(i,j);
			}
		}
	}
	vector<bool> done(N);
	rep(i,N) if(!done[i]){
		int x = i;
		bool odd = 1;
		while(!done[x]){
			done[x] = 1;
			x = to[x];
			odd = !odd;
		}
		if(odd) d = -d;
	}
	return d;
}

/*
	rank
*/
template<class T>
int getrank(Matrix<T> A){
	return A.sweep(A.W);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix/matrix.cpp"
/*
	行列の基本演算, 連立一次方程式の解, 逆行列 とか
	template 引数 T は体である必要がある
	+,-,*,/, unary -
	の他に, zero, one, iszero(), isone() がいる
	浮動小数点とかのためにiszeroとかは==zeroを避けている

	usage:
		field class (mintとか) を用意する
		zero,one,iszero(),isone()を書く

	solveLinearEquationに0個の式を入れると横幅が取得できず[0].size() で segfault ので注意

	complexity:
		sweep系はすべて O(rank * H * W)
		rankが小さいと勝手に計算量は減る

	verified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624 (solveLinearEquarion mod 2)
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (sLE on Rationals)

*/

template<class T>
struct Matrix{
	int H,W;
	VV<T> a;

	Matrix() : H(0),W(0){}
	Matrix(int H,int W) : H(H),W(W),a( VV<T>(H,V<T>(W)) ){}
	Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v){}

	static Matrix E(int n){
		Matrix a(n,n);
		rep(i,n) a.set(i,i,1);
		return a;
	}

	T at(int i,int j) const {
		return a[i][j];
	}
	void set(int i,int j,T v){
		a[i][j] = v;
	}

	Matrix operator+(const Matrix& r) const {
		assert(H==r.H && W==r.W);
		VV<T> v(H,V<T>(W));
		rep(i,H) rep(j,W) v[i][j] = a[i][j] + r.a[i][j];
		return Matrix(v);
	}
	Matrix operator-(const Matrix& r) const {
		assert(H==r.H && W==r.W);
		VV<T> v(H,V<T>(W));
		rep(i,H) rep(j,W) v[i][j] = a[i][j] - r.a[i][j];
		return Matrix(v);
	}
	Matrix operator*(const Matrix& r) const {
		assert(W==r.H);
		VV<T> v(H,V<T>(r.W));
		rep(i,H) rep(k,W) rep(j,r.W) v[i][j] += a[i][k] * r.a[k][j];
		return Matrix(v);
	}
	Matrix& operator+=(const Matrix& r){return (*this)=(*this)+r;}
	Matrix& operator-=(const Matrix& r){return (*this)=(*this)-r;}
	Matrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}

	Matrix pow(ll p) const {
		assert(H == W);
		Matrix a = E(H);
		Matrix x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}

	friend ostream& operator<<(ostream &o,const Matrix& A){
		rep(i,A.H){
			rep(j,A.W) o<<A.a[i][j]<<" ";
			o<<endl;
		}
		return o;
	}

	/*
		副作用がある, 基本的に自分でこれを呼ぶことはない
		掃き出し法をする
		左からvar列が掃き出す対象で、それより右は同時に値を変更するだけ(e.g. 逆行列は右に単位行列おいてから掃き出す)
		行swap, 列swap は行わない

		rank を返す
	*/
	int sweep(int var){
		int rank = 0;
		vector<bool> used(H);
		rep(j,var){
			int i=0;
			while(i<H && (used[i]||iszero(a[i][j]))) i++;
			if(i==H) continue;
			used[i] = true;
			rank++;
			T t = a[i][j];
			rep(k,W) a[i][k] = a[i][k]/t;
			rep(k,H) if(k!=i){
				T t = a[k][j];
				rep(l,W) a[k][l] = a[k][l]-a[i][l]*t;
			}
		}
		return rank;
	}

};

/*
	逆行列を返す
	なければ0*0行列
*/
template<class T>
Matrix<T> inv(const Matrix<T>& A){
	assert(A.H==A.W);
	int N = A.H;
	Matrix<T> X(N,2*N);
	rep(i,N) rep(j,N) X.set(i,j,A.at(i,j));
	rep(i,N) X.set(i,i+N,one);
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
	Ax = b を解く
	pair(解空間の次元, 解のうちひとつ) を返す
	解が存在しないなら(-1,{})

	解を複数得たい → ランダムな式を追加?
*/
template<class T>
pair< int, vector<T> > solveLinearEquation(const Matrix<T>& A, vector<T> b){
	assert(A.H==(int)b.size());
	int H = A.H, W = A.W;

	Matrix<T> X(H,W+1);
	rep(i,H) rep(j,W) X.set(i,j,A.at(i,j));
	rep(i,H) X.set(i,W,b[i]);
	int rank = X.sweep(W);
	rep(i,H){
		bool allzero = true;
		rep(j,W) if(!iszero(X.at(i,j))) allzero = false;
		if(allzero){
			if(!iszero(X.at(i,W))){		//0x + 0y + 0z = non0
				return pair<int,vector<T> >(-1,vector<T>());
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
	return pair<int,vector<T> >(W-rank,x);
}

/*
	determinant
*/
template<class T>
T det(Matrix<T> A){
	assert(A.H==A.W);
	int N = A.H;
	int rank = A.sweep(N);
	if(rank < N) return zero;
	T d = one;
	vector<int> to(N);
	rep(i,N){
		rep(j,N){
			if(!iszero(A.at(i,j))){
				to[i] = j;
				d *= A.at(i,j);
			}
		}
	}
	vector<bool> done(N);
	rep(i,N) if(!done[i]){
		int x = i;
		bool odd = 1;
		while(!done[x]){
			done[x] = 1;
			x = to[x];
			odd = !odd;
		}
		if(odd) d = -d;
	}
	return d;
}

/*
	rank
*/
template<class T>
int getrank(Matrix<T> A){
	return A.sweep(A.W);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

