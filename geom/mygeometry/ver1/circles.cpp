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
D inf=1e50,eps=1e-10,PI=acos(0.0)*2;
bool eq(D a, D b) { return abs(a-b)<eps;}
bool eq(P a, P b) { return abs(a-b)<eps;}
int sig(D a) { return eq(a,0) ? 0 : (a>0 ? 1 : -1);}
int large(D a,D b){return eq(a,b)?0:(a>b?1:-1);}
bool compxy (const P& l, const P& r){
	return eq(l.X,r.X) ? l.Y<r.Y : l.X < r.X;
}
bool compyx (const P& l, const P& r){
	return eq(l.Y,r.Y) ? l.X<r.X : l.Y < r.Y;
}
inline D dot(P a, P b) { return real(conj(a)*b);};
inline D cro(P a, P b) { return imag(conj(a)*b);};
inline P perp(L l, P p){		//垂線の足
	D t=dot(p-l.fs,l.fs-l.sc)/norm(l.fs-l.sc);
	return l.fs+t*(l.fs-l.sc);
}
inline D dLP(L l, P p) { return abs(perp(l,p)-p);}
inline int iCL(C c, L l){		//num of intersection(s)
	D d=dLP(l,c.p);
	return eq(d,c.r) ? 1 : (d<c.r ? 2 : 0);
}
//bool containCC(C a,C b)
inline Pol intCC(C a,C b){
	int x=large(abs(a.p-b.p),(a.r+b.r));
	Pol ret;
	if(x==1) return ret;
	if(x==0){
		ret.pb((a.r*b.p+b.r*a.p)/(a.r+b.r));
		return ret;
	}
	//contain?
	D d=abs(a.p-b.p);
	D theta=acos((a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d));
	ret.pb(a.p+(b.p-a.p)/d*polar(a.r,theta));
	ret.pb(a.p+(b.p-a.p)/d*polar(a.r,-theta));
	return ret;
}
inline vector<L> tanCP(C c,P p){
	int x=large(c.r,abs(p-c.p));
	vector<L> ret;
	if(x==1) return ret;
	if(x==0){
		ret.pb(L(p,p+(c.p-p)*P(0,1)));
		return ret;
	}
	D theta=acos(c.r/abs(p-c.p));
	ret.pb(L(p,c.p+(p-c.p)/abs(p-c.p)*polar(c.r,theta)));
	ret.pb(L(p,c.p+(p-c.p)/abs(p-c.p)*polar(c.r,-theta)));
	return ret;
}
inline Pol intCL(C c,L l){
	int x=large(dLP(l,c.p),c.r);
	Pol ret;
	if(x==1) return ret;
	if(x==0){
		ret.pb(perp(l,c.p));
		return ret;
	}
	D d=dLP(l,c.p);
	if(d<eps){
		ret.pb(c.p+(l.fs-l.sc)/abs(l.fs-l.sc)*c.r);
		ret.pb(c.p-(l.fs-l.sc)/abs(l.fs-l.sc)*c.r);
		return ret;
	}
	D theta=acos(d/c.r);
	P p=perp(l,c.p);
	ret.pb(c.p+(p-c.p)/d*polar(c.r,theta));
	ret.pb(c.p+(p-c.p)/d*polar(c.r,-theta));
	return ret;
}
inline vector<L> intan(C a,C b){
	P p=(a.r*b.p+b.r*a.p)/(a.r+b.r);
	return tanCP(a,p);
}
inline vector<L> outtan(C a,C b){
	if(a.r==b.r){
		vector<L> ret;
		P p=(a.p-b.p)/abs(a.p-b.p)*polar(a.r,PI/2);
		cout<<p<<endl;
		ret.pb(L(a.p+p,b.p+p));
		ret.pb(L(a.p-p,b.p-p));
		return ret;
	}
	P p=(a.r*b.p-b.r*a.p)/(a.r-b.r);
	return tanCP(a,p);
}
int main(){
}