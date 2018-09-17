/*
多項式.
shrink()でleading-0を取り除き,常にこの意味での正規系を値として持つ.
その意味でintとmint以外はまあまあまずいかな
でも+-とか簡単なのは出来る(いるか?)
mintだと,fft or ntt(おそい) を使って乗除ができる.
諸々含めてverified by フィボナッチ(TDPC T)

だいたいいろいろ組み合わせると思うんですけど,/atcoder/typicalDP/T.cppを参照
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(int N=0) : v(vector<D>(N)){}
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
		return mul_fft(r);
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
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
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
	Poly inv(int n) const{		// f * f.inv() = x^B + r(x) (B>=n)
		int N = size();
		assert(N>=1);		//f : non0
		assert(n>=N-1);		//f = .. + c_{N-1}x^{N-1}
		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		//need to strip!!
			g *= (Poly(vector<D>{2})-a*g).strip(2*i);
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
int main(){
	vector<int> vc={1,0,2,-1,0};
	Poly<int> poly(vc);
	show(poly);
}
