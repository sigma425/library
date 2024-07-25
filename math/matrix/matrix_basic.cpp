/*
	基本操作だけMatrixライブラリにすることに
	sweepとかはもう直接vector<vector<T>> の関数で書く
*/

template<class T>
struct Matrix: public vector<vector<T>>{

	Matrix(int n) : vector<vector<T>>(n,vector<T>(n)){}
	Matrix(int h,int w) : vector<vector<T>>(h,vector<T>(w)){}
	Matrix(const vector<vector<T>>& m){(*this) = m;}

	static Matrix E(int n){
		Matrix a(n,n);
		rep(i,n) a[i][i] = 1;
		return a;
	}
	int h() const { return (*this).size(); }
	int w() const { return (*this)[0].size(); }

	Matrix operator+(const Matrix& r) const {
		assert(h() == r.h() && w() == r.w());
		int H = h(), W = w();
		Matrix z(H,W);
		rep(i,H) rep(j,W) z[i][j] = (*this)[i][j] + r[i][j];
		return z;
	}
	Matrix operator-(const Matrix& r) const {
		assert(h() == r.h() && w() == r.w());
		int H = h(), W = w();
		Matrix z(H,W);
		rep(i,H) rep(j,W) z[i][j] = (*this)[i][j] - r[i][j];
		return z;
	}
	Matrix operator*(const Matrix& r) const {
		assert(w() == r.h());
		int A = h(), B = w(), C = r.w();
		Matrix z(A,C);
		rep(i,A) rep(k,B) rep(j,C) z[i][j] += (*this)[i][k] * r[k][j];
		return z;
	}
	Matrix& operator+=(const Matrix& r){return (*this)=(*this)+r;}
	Matrix& operator-=(const Matrix& r){return (*this)=(*this)-r;}
	Matrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}

	Matrix pow(ll p) const {
		assert(h() == w());
		Matrix res = E(h());
		Matrix x = *this;
		while(p){
			if(p&1) res *= x;
			x *= x;
			p >>= 1;
		}
		return res;
	}

	friend ostream& operator<<(ostream &o,const Matrix& A){
		rep(i,A.h()){
			rep(j,A.w()) o << A[i][j]<<" ";
			o << endl;
		}
		return o;
	}
};

/*
	テンソル積 (クロネッカー積)
	A⊗B =[a{0,0}B .. a_{0,w-1}B]
		  [a{1,0}B .. a_{1,w-1}B]
			:
	Aの1マスを分割してBにするイメージ
*/
template<class T>
vector<vector<T>> tensor(vector<vector<T>> A, vector<vector<T>> B){
	int ah = si(A), aw = si(A[0]), bh = si(B), bw = si(B[0]);
	vector<vector<T>> C(ah*bh,vector<T>(aw*bw));
	rep(ai,ah) rep(aj,aw){
		rep(bi,bh) rep(bj,bw){
			C[ai*bh+bi][aj*bw+bj] = A[ai][aj] * B[bi][bj];
		}
	}
	return C;
}