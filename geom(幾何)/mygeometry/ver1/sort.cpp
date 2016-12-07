#include <cstdio>
#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) c.begin(),c.end()
#define fs first
#define sc second
#define X real()
#define Y imag()
#define pb push_back
using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;		//fs->sc
typedef vector<P> Pol;
struct C{P p;D r;};
D inf=1e50,eps=1e-10;
 bool eq(D a, D b) { return abs(a-b)<eps;}
// bool eq(P a, P b) { return abs(a-b)<eps;}
// int sig(D a) { return eq(a,0) ? 0 : (a>0 ? 1 : -1);}
//namespace std {
bool operator < (const complex<double>& l, const complex<double>& r){		//sort x -> y
	return l.Y < r.Y;
}
//}
bool compxy (const P& l, const P& r){		//sort x -> y
	return eq(l.real(),r.real()) ? l.imag()<r.imag() : l.real() < r.real();
}
bool compyx (const P& l, const P& r){		//sort y -> x
	return eq(l.imag(),r.imag()) ? l.real()<r.real() : l.imag() < r.imag();
}

int main(){
//	::compxy
	vector<P> vc;
	int n;
	cin>>n;
	rep(i,n){
		int x,y;
		cin>>x>>y;
		vc.pb(P(x,y));
	}
//	P a=P(2,3),b=P(3,4);
//	*vc.begin() < *vc.end();
	sort(all(vc));
}