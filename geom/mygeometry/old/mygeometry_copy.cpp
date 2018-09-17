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
#define pb push_back
using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;		//fs->sc
typedef vector<P> Pol;
struct C{P p;D r;};
D inf=1e50,eps=1e-10;
//template<class T> bool eq(T a, T b) { return abs(a-b)<eps;}
//template<class T> int sig(T a) { return eq(a,0) ? 0 : (a>0 ? 1 : -1);}
bool eq(D a, D b) { return abs(a-b)<eps;}
bool eq(P a, P b) { return abs(a-b)<eps;}
int sig(D a) { return eq(a,0) ? 0 : (a>0 ? 1 : -1);}
bool operator < (const P& l, const P& r){		//sort x -> y
	return eq(l.real(),r.real()) ? l.imag()<r.imag() : l.real() < r.real();
}
bool compxy (const P& l, const P& r){		//sort x -> y
	return eq(l.real(),r.real()) ? l.imag()<r.imag() : l.real() < r.real();
}
bool compyx (const P& l, const P& r){		//sort y -> x
	return eq(l.imag(),r.imag()) ? l.real()<r.real() : l.imag() < r.imag();
}
inline D dot(P a, P b) { return real(conj(a)*b);};
inline D cro(P a, P b) { return imag(conj(a)*b);};
//enum ENCCW{CCW=1, CW=-1, FRONT=-2, BACK=2, ON=0};	//!!MAEHARAと一緒(convが書きやすい(次の点を取る条件をccw>0とかける))
//ON優先(including endpoint)
inline int ccw (P a, P b, P c){
//	cout << cro(b-a,c-a) << endl;
	if(sig(cro(b-a,c-a))==1) return 1;
	if(sig(cro(b-a,c-a))==-1) return -1;
	if(eq(abs(a-c)+abs(c-b),abs(a-b))) return 0;
	if(eq(abs(a-b)+abs(b-c),abs(a-c))) return -2;
	if(eq(abs(c-a)+abs(a-b),abs(c-b))) return 2;
}
inline P proj(P a, P b){		//ベクトルaのbへの射影
	return (dot(a,b)/norm(b))*b;
}
inline D verlength(L l,P p){
	return cro(l.fs-l.sc,p-l.sc)/abs(l.fs-l.sc);
}
inline P perp(L l, P p){		//垂線の足
	D t=dot(p-l.fs,l.fs-l.sc)/norm(l.fs-l.sc);
	return l.fs+t*(l.fs-l.sc);
}
inline P refl(L l, P p){
	return p+2.0*(perp(l,p)-p);
}
inline bool ispal(L a, L b){
	return sig(cro(a.fs-a.sc,b.fs-b.sc))==0;
}
inline bool ovLL(L a, L b){
	return ispal(a,b) && sig(cro(a.fs-a.sc,b.fs-a.sc))==0;
}
inline bool iLL(L a, L b){		//intersect or overload
	return !ispal(a,b) || ovLL(a,b);
}
inline bool iLS(L l, L s){		//intersect(including endpoint) or overload
	return cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<eps;
}
inline bool iLP(L l, P p){		//on line
	return sig(cro(l.sc-p,l.fs-p));
}
inline bool iSS(L a, L b){		//intersect(including endpoint) or overload
	return ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0 && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0;
}
inline bool iSP(L s, P p){		//intersect(including endpoint) or overload
	return ccw(s.fs,s.sc,p)==ON;
}
inline D dLP(L l, P p) { return abs(perp(l,p)-p);}
inline D dLL(L a, L b) { return iLL(a,b) ? 0 : dLP(a,b.fs);}
inline D dLS(L l, L s) { return iLS(l,s) ? 0 : min(dLP(l,s.fs),dLP(l,s.sc));}
inline D dSP(L s, P p) {
	P q=perp(s,p);
	return iSP(s,q) ? abs(p-q) : min(abs(p-s.fs),abs(p-s.sc));
}
inline D dSS(L a, L b) {
	if(iSS(a,b)) return 0;
	return min(min(dSP(a,b.fs),dSP(a,b.sc)),min(dSP(b,a.fs),dSP(b,a.sc)));
}
inline P intLL(L a, L b) {	//intersection
	assert(!ispal(a,b));
	D t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);
	return b.fs+t*(b.sc-b.fs);
}
enum ENICP{INC=1,ONC=0,OUTC=-1};
inline int iCP(C c, P p){
	D d=abs(p-c.p);
	return eq(d,c.r) ? ONC : (d<c.r ? INC : OUTC);
}
inline int iCL(C c, L l){		//num of intersection(s)
	D d=dLP(l,c.p);
	return eq(d,c.r) ? 1 : (d<c.r ? 2 : 0);
}
//inline int iCS
//inline int iCC(C a, C b){

/*inline P intCL1(C c, L l){		//iCL=1
	assert(iCL(c,l)==1);
}
inline L intCL2(C c, L l){		//iCL=2
	assert(iCL(c,l)==2);
}*/
D aTri(P a, P b, P c){ return cro(b-a,c-a)/2;}
D aPol(Pol p){			//点集合はCCWに与える
	int n=p.size();
	D ret=0;
	rep(i,n) ret+=cro(p[i],p[(i+1)%n])/2;
	return ret;
}
P gPol(Pol p){			//多角形内部が一様な重さを持つときの重心
	int n=p.size();
	P g;
	D s=aPol(p);
	assert(s>eps);
	rep(i,n){
		D ds=cro(p[i],p[(i+1)%n])/2;
		g+=ds/3*(p[i]+p[(i+1)%n]);
	}
	return g/s;
}
enum ENCONT{INP=1,ONP=0,OUTP=-1};
int contain(Pol pol, P p){
	bool in=false;
	rep(i,pol.size()){
		P a=pol[i]-p,b=pol[(i+1)%pol.size()]-p;
		if(ccw(a,b,P(0,0))==ON) return ONP;
		if(imag(a)>imag(b)) swap(a,b);
		if(sig(imag(a))<=0 && 0<sig(imag(b)) && ccw(P(0,0),a,b)==CCW) in=!in;
	}
	return in ? INP : OUTP;
}
inline D heron(D a, D b, D c){
	double s=(a+b+c)/2;
	if(s-a<eps || s-b<eps || s-c<eps) return 0;		//S=0 || 三角形できない
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
inline Pol conv(Pol p){		//convex
	int n=p.size(),k=0;
//	assert(n>=3);			//2点でもok
	sort(all(p),compxy);			//compyxで下から
	Pol ret(2*n);
	rep(i,n){
		while(k>=2 && ccw(ret[k-2],ret[k-1],p[i])<=0) --k;
		ret[k++]=p[i];
	}
	for(int i=n-2,t=k+1;i>=0;i--){
		while(k>=t && ccw(ret[k-2],ret[k-1],p[i])<=0) --k;
		ret[k++]=p[i];
	}
	ret.resize(k-1);
	return ret;
}
inline Pol convall(Pol p){		//conv上の点全部		//点が2回以上出てくる
	int n=p.size(),k=0;
//	assert(n>=3);
	sort(all(p),compxy);
//	if(p[0]<p[1]) ;
	Pol ret(2*n);
	rep(i,n){
		while(k>=2 && ccw(ret[k-2],ret[k-1],p[i])==-1) --k;
		ret[k++]=p[i];
	}
	for(int i=n-2,t=k+1;i>=0;i--){
		while(k>=t && ccw(ret[k-2],ret[k-1],p[i])==-1) --k;
		ret[k++]=p[i];
	}
	ret.resize(k-1);
//	Pol ret1=ret;
//	sort(all(ret),compxy);
	ret.erase(unique(all(ret)),ret.end());
	return ret;
}
D pol_diameter(Pol p){
	p=conv(p);
	int n=p.size();
	assert(n>=2);
	if(n==2) return abs(p[0]-p[1]);
	int i=0,j=0;
	rep(k,n){
		if(!compxy(p[i],p[k])) i=k;
		if(compxy(p[j],p[k])) j=k;
	}
	D ret=0;
	int si=i,sj=j;
	while(i!=sj || j!=si){
		ret=max(ret,abs(p[i]-p[j]));
		if(cro(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0) i=(i+1)%n;
		else j=(j+1)%n;
	}
	return ret;
}
D closest_pair(P *a, int n){
	if(n<=1) return inf;
	int m=n/2;
	D x=a[m].real();
	D d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compyx);
	vector<P> b;
	rep(i,n){
		if(abs(x-a[i].real())>=d) continue;
		rep(j,b.size()){
			P dp=a[i]-b[b.size()-1-j];
			if(dp.imag()>=d) break;
			d=min(d,abs(dp));
		}
		b.pb(a[i]);
	}
	return d;
}
D compute_shortest(P *a,int n){
	sort(a,a+n,compxy);
	return closest_pair(a,n);
}
int main(){
	
}