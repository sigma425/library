/*
	線形代数いろいろ
	verified: yosupo
*/

template<class T>
T det(vector<vector<T>> a){
	assert(a.size() == a[0].size());
	int n = a.size();
	T ans = 1;
	rep(i,n){
		for(int j=i+1;j<n;j++) if(a[j][i]){
			ans = -ans;
			swap(a[j],a[i]);
			break;
		}
		if(!a[i][i]) return T(0);
		ans *= a[i][i];
		for(int j=i+1;j<n;j++){
			T w = -a[j][i]/a[i][i];
			for(int k=i;k<n;k++) a[j][k] += a[i][k]*w;
		}
	}
	return ans;	
}
/*
	左c列をsweep 指定しないとc = w
	行のswapはする
	掃き出しに使った列の集合を返す
*/
template<class T>
vector<int> sweep(vector<vector<T>>& a, int c = -1){
	if(a.empty()) return {};
	if(c == -1) c = a[0].size();
	int h = a.size(), w = a[0].size(), r = 0;
	vector<int> used_col;
	rep(i,c){
		if(r == h) break;
		for(int j=r;j<h;j++) if(a[j][i]){
			swap(a[r],a[j]); break;
		}
		if(!a[r][i]) continue;
		rep(j,h) if(j != r){
			const T t = -a[j][i]/a[r][i];
			for(int k=i;k<w;k++) a[j][k] += a[r][k]*t;
		}
		used_col.pb(i);
		r++;
	}
	return used_col;
}

/*
	ax = b の解のひとつを出力
	解空間は (output) + ker(a)
	解が存在しないなら {}

	式が0個(si(a) == 0) で壊れないように変数の個数 ( = si(a[0]) ) w を与える
*/
template<class T>
vector<T> linearEquation(vector<vector<T>> a, int w, vector<T> b){
	assert(a.size() == b.size());
	int h = a.size();
	rep(i,h) a[i].pb(b[i]);
	vector<int> idx = sweep(a,w);
	for(int i = idx.size();i<h;i++) if(a[i][w]) return {};
	vector<T> x(w);
	rep(i,idx.size()) x[idx[i]] = a[i][w] / a[i][idx[i]];
	return x;
}

template<class T>
struct BandMatrix{
	int h,w,width;
	vector<vector<T>> dat;

	BandMatrix():h(0),w(0),width(0){}
	BandMatrix(int h_,int w_,int width_):
		h(h_),w(w_),width(width_),dat(h_,vector<T>(2*width_+1)){}
	BandMatrix(int h_,int w_,int width_, const T& v):
		h(h_),w(w_),width(width_),dat(h_,vector<T>(2*width_+1)){
		rep(i,h){
			for(int j=max(0,i-width);j<=min(w-1,i+width);j++){
				dat[i][j-i+width] = v;
			}
		}
	}
	bool in_band(int i, int j) const{
		return 0 <= i && i < h && 0 <= j && j < w && abs(i-j) <= width;
	}
	T get(int i, int j) const{
		if(!in_band(i,j)) return T(0);
		return dat[i][j-i+width];
	}
	void set(int i, int j, const T& v){
		assert(0 <= i && i < h);
		assert(0 <= j && j < w);
		assert(abs(i-j) <= width);
		dat[i][j-i+width] = v;
	}

	struct CellProxy{
		BandMatrix *self;
		int i,j;
		operator T() const{
			return self->get(i,j);
		}
		CellProxy& operator=(const T& v){
			self->set(i,j,v);
			return *this;
		}
		CellProxy& operator+=(const T& v){
			return *this = T(*this) + v;
		}
		CellProxy& operator-=(const T& v){
			return *this = T(*this) - v;
		}
		CellProxy& operator*=(const T& v){
			return *this = T(*this) * v;
		}
		CellProxy& operator/=(const T& v){
			return *this = T(*this) / v;
		}
	};
	struct ConstRowProxy{
		const BandMatrix *self;
		int i;
		T operator[](int j) const{
			return self->get(i,j);
		}
	};
	struct RowProxy{
		BandMatrix *self;
		int i;
		CellProxy operator[](int j){
			return CellProxy{self,i,j};
		}
		T operator[](int j) const{
			return self->get(i,j);
		}
	};
	RowProxy operator[](int i){
		assert(0 <= i && i < h);
		return RowProxy{this,i};
	}
	ConstRowProxy operator[](int i) const{
		assert(0 <= i && i < h);
		return ConstRowProxy{this,i};
	}
};

/*
	Ax = b を、abs(i-j) > width なら A[i][j] = 0 であることを使って解く
	A は H * W でもよい
	input O(H * width), time O(H * width^2)
*/
template<class T>
vector<T> linearEquationBand(const BandMatrix<T>& A, vector<T> b){
	assert(a.h == si(b));
	int h = A.h, w = A.w, width = A.width;
	if(w == 0){
		rep(i,h) if(b[i]) return {};
		return vector<T>(0);
	}
	int span = 2*width+1;
	vector<vector<int>> add_row(w);
	rep(i,h){
		int l = max(0,i-width);
		if(l < w) add_row[l].pb(i);
	}
	vector<vector<T>> basis;
	vector<int> lead;
	vector<char> has_pivot(w,false);
	vector<T> rhs(w);
	vector<vector<T>> coef(w,vector<T>(span));

	auto lead_pos = [&](const vector<T>& v){
		rep(k,span) if(v[k]) return k;
		return -1;
	};
	auto reduce_row = [&](vector<T>& v){
		rep(id,si(basis)){
			int l = lead[id];
			if(v[l]){
				T mul = v[l] / basis[id][l];
				for(int k=l;k<=span;k++) v[k] -= basis[id][k] * mul;
			}
		}
	};

	rep(c,w){
		if(c){
			rep(id,si(basis)){
				rep(k,span-1) basis[id][k] = basis[id][k+1];
				basis[id][span-1] = 0;
			}
			rep(id,si(lead)) lead[id]--;
		}
		per(id,si(basis)){
			int l = lead_pos(basis[id]);
			if(l == -1){
				if(basis[id][span]) return vector<T>();
				basis.erase(basis.begin()+id);
				lead.erase(lead.begin()+id);
			}else{
				lead[id] = l;
			}
		}
		for(int i:add_row[c]){
			vector<T> v(span+1);
			for(int j=c;j<=min(w-1,c+2*width);j++) v[j-c] = A[i][j];
			v[span] = b[i];
			reduce_row(v);
			int l = lead_pos(v);
			if(l == -1){
				if(v[span]) return vector<T>();
				continue;
			}
			int pos = 0;
			while(pos < si(lead) && lead[pos] < l) pos++;
			basis.insert(basis.begin()+pos,v);
			lead.insert(lead.begin()+pos,l);
			for(int id=0;id<si(basis);id++) if(id != pos && basis[id][l]){
				T mul = basis[id][l] / basis[pos][l];
				for(int k=l;k<=span;k++) basis[id][k] -= basis[pos][k] * mul;
			}
			lead[pos] = l;
		}
		if(!basis.empty() && lead[0] == 0){
			has_pivot[c] = true;
			T piv = basis[0][0];
			rhs[c] = basis[0][span] / piv;
			for(int d=1;d<span;d++) coef[c][d] = basis[0][d] / piv;
			basis.erase(basis.begin());
			lead.erase(lead.begin());
		}
	}
	per(id,si(basis)) if(lead_pos(basis[id]) == -1){
		if(basis[id][span]) return vector<T>();
	}
	vector<T> x(w);
	for(int c=w-1;c>=0;c--){
		if(!has_pivot[c]) continue;
		T v = rhs[c];
		for(int d=1;d<span && c+d<w;d++) v -= coef[c][d] * x[c+d];
		x[c] = v;
	}
	rep(i,h){
		T s = 0;
		for(int j=max(0,i-width);j<=min(w-1,i+width);j++) s += A[i][j] * x[j];
		if(s != b[i]) return {};
	}
	return x;
}

/*
	{x | ax = 0} のある基底を出力
	式が0個(si(a) == 0) で壊れないように変数の個数 ( = si(a[0]) ) w を与える
	si(kernel) + rank(a) == w
*/
template<class T>
vector<vector<T>> kernel(vector<vector<T>> a, int w){
	int h = a.size();
	vector<vector<T>> b(w,vector<T>(h+w));
	rep(i,h) rep(j,w) b[j][i] = a[i][j];
	rep(i,w) b[i][h+i] = 1;
	int r = sweep(b,h).size();
	vector<vector<T>> res;
	for(int i=r;i<w;i++) res.eb(b[i].begin()+h,b[i].end());
	return res;
}

// mod 2
// 幅(例: 変数の個数)だけbitsetにして縦はしてないことに注意
// 例えば Ax = b の b は vector<bool>
using BS = bitset<8010>;	// max_width
vector<int> sweep_mod2(vector<BS>& a, int c = -1){
	if(a.empty()) return {};
	if(c == -1) c = a[0].size();
	int h = a.size(), r = 0;
	vector<int> used_col;
	rep(i,c){
		if(r == h) break;
		for(int j=r;j<h;j++) if(a[j][i]){
			swap(a[r],a[j]); break;
		}
		if(!a[r][i]) continue;
		rep(j,h) if(j != r && a[j][i]){
			a[j] ^= a[r];
		}
		used_col.pb(i);
		r++;
	}
	return used_col;
}
vector<bool> linearEquation_mod2(vector<BS> a, int w, vector<bool> b){
	assert(a.size() == b.size());
	int h = a.size();
	rep(i,h) a[i][w] = b[i];			// ここ込でwidthとること
	vector<int> idx = sweep_mod2(a,w);
	for(int i = idx.size();i<h;i++) if(a[i][w]) return {};
	vector<bool> x(w);
	rep(i,idx.size()) x[idx[i]] = a[i][w];
	return x;
}


/*
	inversion
	なければ {{}}
*/
template<class T>
vector<vector<T>> inv(vector<vector<T>> a){
	assert(a.size() == a[0].size());
	vector<vector<T>> no;
	int n = a.size();
	vector<int> ih(n,-1), jh(n,-1);
	rep(k,n){
		for(int i=k;i<n;i++) if(ih[k] == -1){
			for(int j=k;j<n;j++) if(a[i][j]){
				ih[k] = i, jh[k] = j; break;
			}
		}
		if(ih[k] == -1) return no;
		rep(j,n) swap(a[k][j],a[ih[k]][j]);
		rep(i,n) swap(a[i][k],a[i][jh[k]]);
		if(!a[k][k]) return no;
		a[k][k] = a[k][k].inv();
		rep(i,n) if(i != k) a[k][i] *= a[k][k];
		rep(i,n) if(i != k){
			rep(j,n) if(j != k){
				a[i][j] -= a[i][k]*a[k][j];
			}
		}
		rep(i,n) if(i != k) a[i][k] *= -a[k][k];
	}
	per(k,n){
		rep(j,n) swap(a[k][j],a[jh[k]][j]);
		rep(i,n) swap(a[i][k],a[i][ih[k]]);
	}
	return a;
}
