/*
依存関係 : mint,fft(ntt)


多項式.
shrink()でleading-0を取り除き,常にこの意味での正規系を値として持つ.
その意味でintとmint以外はまあまあまずいかな
でも+-とか簡単なのは出来る(いるか?)

割り算も O(NlogN) だがNが小さい時遅いので分割統治みたいなことをするときは注意

TODO:
	微積分
	sqrt
	log

計測:
	-O2

	fft2 *
	- N = 100000
	141 [ms]
	- N = 200000
	279 [ms]
	- N = 500000
	595 [ms]
	- N = 1000000
	1186 [ms]

	fft2 N % N/4 くらい 割る側の次数はこれくらいが一番遅い気がする
	- N = 10000
	44 [ms]
	- N = 100000
	643 [ms]
	- N = 200000
	1340 [ms]
	- N = 500000
	3033 [ms]
	- N = 1000000
	5875 [ms]

	ntt * 
	- N = 1000000
	231 [ms]

	ntt N % N/4
	- N = 200000
	147 [ms]
	- N = 500000
	310 [ms]
	- N = 1000000
	646 [ms]

*/

template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	//double? iszeroをglobalに用意したほうがいいかな
		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		//v[i] := x
		if(i>=size() && !x) return;
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}
	D eval(D x){
		D res = 0;
		int n = size();
		D a = 1;
		rep(i,n){
			res += a*v[i];
			a *= x;
		}
		return res;
	}

	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_fft(r);									// FFT or NTT ?
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);
//		return rem_naive(y);
	}
	Poly operator<<(const int &n) const{	// *=x^n
		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	// /=x^n
		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		return Poly(multiply_fft(v,r.v));
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv(n),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	//ignore x^n , x^n+1,...
		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	//ignore x^n ~  ->  return x^(n-1) * f(1/x)
		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}

	/*
		inv : O(NlogN)
	*/
	Poly inv(int n) const{		// f * f.inv() = x^B + r(x) (B>=n)
		int N = size();
		assert(N>=1);		//f : non0
		assert(n>=N-1);		//f = .. + c_{N-1}x^{N-1}
		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		//need to strip!!
			g *= (Poly(vector<D>{2})-a.strip(2*i)*g).strip(2*i);
		}
		return g.rev(n+1-N);
	}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};


/*
	↓ test
*/

template<class T>
T rnd(T l,T r){	//[l,r)
	using D = uniform_int_distribution<T>;
	static random_device rd;
	static mt19937 gen(rd());
	return D(l,r-1)(gen);
}
template<class T>
T rnd(T n){	//[0,n)
	return rnd(0,n);
}
struct Timer{
	clock_t st;
	void start(){
		st = clock();
	}
	int ms(){
		return (clock()-st)*1000 / CLOCKS_PER_SEC;
	}
}timer;


void unittest(){
	vector<int> Ns = {2,10,100,1000,10000,100000,200000,500000,1000000};
	for(int N: Ns){
		Poly<mint> f,g;
		rep(i,N) f.set(i,rnd<int>(mint::mod));
		rep(i,N) g.set(i,rnd<int>(mint::mod));
		timer.start();
		auto h = f*g;
		cerr << "- N = " << N << endl;
		cerr << "  " << timer.ms() << " [ms]" << endl;
	}
}

int main(){
	unittest();
}
