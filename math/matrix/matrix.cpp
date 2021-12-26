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

		定数倍が遅いので500とかのときは別のを使う

	verified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624 (solveLinearEquarion mod 2)
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (sLE on Rationals)

*/

template<class T>
struct Matrix{
	int H,W;
	VV<T> a;

	Matrix() : H(0),W(0){}
	Matrix(int H_,int W_) : H(H_),W(W_),a( VV<T>(H,V<T>(W)) ){}
	Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v){}

	static Matrix E(int n){
		Matrix a(n,n);
		rep(i,n) a[i][i] = 1;
		return a;
	}

	V<T>& operator[](int i){return a[i];}
	const V<T>& operator[](int i) const {return a[i];}

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
		Matrix res = E(H);
		Matrix x = *this;
		while(p){
			if(p&1) res *= x;
			x *= x;
			p >>= 1;
		}
		return res;
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
				T tt = a[k][j];
				rep(l,W) a[k][l] = a[k][l]-a[i][l]*tt;
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
	rep(i,N) rep(j,N) X[i][j] = A[i][j];
	rep(i,N) X[i][i+N] = 1;
	int rank = X.sweep(N);
	if(rank < N) return Matrix<T>();
	Matrix<T> B(N,N);
	rep(i,N){
		rep(j,N){
			B[i][j] = X[i][j+N];
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
	rep(i,H) rep(j,W) X[i][j] = A[i][j];
	rep(i,H) X[i][W] = b[i];
	int rank = X.sweep(W);
	rep(i,H){
		bool allzero = true;
		rep(j,W) if(!iszero(X[i][j])) allzero = false;
		if(allzero){
			if(!iszero(X[i][W])){		//0x + 0y + 0z = non0
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
			if(iszero(X[i][j])) c0++;
			else if(isone(X[i][j])) c1++,I=i;
		}
		if(c0==H-1 && c1==1 && !done[I]){
			x[j] = X[I][W];
			done[I] = true;
		}
	}
	return pair<int,vector<T> >(W-rank,x);
}

/*
	determinant
*/
template<class T>
T det(VV<T> a){
	const int N = a.size();
	if(N == 0) return T(1);
	assert(int(a[0].size()) == N);
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
int getrank(Matrix<T> A){
	return A.sweep(A.W);
}