/*
Berlekamp-Massey
体K上のn+1項間線形漸化式から生成される数列の,はじめ2n項を渡すと,その線形漸化式(というか最小多項式)を求めてくれる
例えばfibなら4項必要.
input を u , N項 として output を c とすると
for all j < N-K,
c_0 * u_j + c_1 * u_{j+1} + .. + c_K * u_{j+K} = 0
となる.
O(N^2)
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
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}

int main(){
	vector<int> fib({0,1,1,2,3,5,8});
	//0,1,1,2 までは必要
	vector<int> hoge({0,1,2,-1,5,-2,5,3});	//		2 a_i + a_i+1 - a_i+2 - a_i+3 = 0
	//-2までは必要
	auto c = berlekamp_massey(hoge);	// return	2 x^0 +   x^1 -   x^2 -   x^3
	show(c);
}
