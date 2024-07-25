/*
	多次元配列 を flatten したやつ
	A[i0]..[i_{D-1}] = f[i0 + i1*m0 + i2*m0*m1 + ..]
	0 が lsb で D-1 が msb ということです

	コンストラクタ:
		各次元のサイズ m[0],..,m[D-1]

	アクセス:
		左辺値右辺値どっちでも
		A[{i0,..,i_{D-1}}], あるいは直接 A[i]

	id: {i0,..,i_{D-1}} -> i
	di: i -> {i0,..,i_{D-1}}

	verify:
		ICPC final 46 Z
		djq 学生物 https://qoj.ac/submission/189638
*/
template<class T>
struct ndarray{
	int S;
	vector<T> v;
	vector<int> ms;
	vector<int> coefs;

	ndarray(){}
	ndarray(vector<int> ms_):ms(ms_),coefs(si(ms_),1){
		rep(d,si(ms)-1) coefs[d+1] = coefs[d] * ms[d];
		S = 1; rep(d,si(ms)) S *= ms[d];
		v.resize(S);
	}
	int id(const vector<int>& is) const {
		int s = 0;
		rep(d,si(ms)) s += is[d] * coefs[d];
		return s;
	}
	vector<int> di(int i){
		V<int> is(si(ms));
		per(d,si(ms)){
			is[d] = i/coefs[d];
			i %= coefs[d];
		}
		return is;
	}

	T& operator[](const vector<int>& is){
		return v[id(is)];
	}
	const T& operator[](const vector<int>& is) const {
		return v[id(is)];
	}
	T& operator[](int i){
		return v[i];
	}
	const T& operator[](int i) const {
		return v[i];
	}

	friend ostream& operator<<(ostream &o,const ndarray& a){
		return o << a.v;
	}
	int size(){
		return S;
	}
	int dim(){
		return si(ms);
	}
};