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
#define X real()
#define Y imag()
using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;
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
inline D dot(P a, P b) { return real(conj(a)*b);}
inline D cro(P a, P b) { return imag(conj(a)*b);}
//enum ENCCW{CCW(left)=1, CW(right)=-1, FRONT=-2, BACK=2, ON=0};
//ON優先(including endpoint)
inline int ccw (P a, P b, P c){
	if(sig(cro(b-a,c-a))==1) return 1;
	if(sig(cro(b-a,c-a))==-1) return -1;
	if(eq(abs(a-c)+abs(c-b),abs(a-b))) return 0;
	if(eq(abs(a-b)+abs(b-c),abs(a-c))) return -2;
	if(eq(abs(c-a)+abs(a-b),abs(c-b))) return 2;
}
inline int ccw(L a,P p){return ccw(a.fs,a.sc,p);}
inline P proj(P a, P b){		//ベクトルaのbへの射影
	return (dot(a,b)/norm(b))*b;
}
inline D verlen(L l,P p){	//垂線の長さ(符号付き ccw(左)が正)
	return cro(l.sc-l.fs,p-l.fs)/abs(l.sc-l.fs);
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
inline bool iLSex(L l, L s){		//intersect(excluding endpoint)
	return cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<-eps;
}
inline bool iLP(L l, P p){		//on line
	return abs(sig(cro(l.sc-p,l.fs-p)))!=1;
}
inline bool iSS(L a, L b){		//intersect(including endpoint) or overload
	return ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0 && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0;
}
inline bool iSSex(L a, L b){		//intersect(excluding endpoint)
	return ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<0 && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<0;
}
inline bool iSP(L s, P p){		//intersect(including endpoint) or overload
	return ccw(s.fs,s.sc,p)==0;
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
//
inline int iCL(C c, L l){		//num of intersection(s)
	D d=dLP(l,c.p);
	return eq(d,c.r) ? 1 : (d<c.r ? 2 : 0);
}
bool containCC(C a,C b){	//a contain c? (edge case is true)
	return abs(a.p-b.p)+b.r<a.r+eps;
}
// 交点が2個のとき、aをbが削ると思うと、削れた部分はret[0] -> res[1] (ccw) の部分
inline Pol intCC(C a,C b){
	int x=large(abs(a.p-b.p),(a.r+b.r));
	Pol ret;
	if(x==1) return ret;
	if(x==0){
		ret.pb((a.r*b.p+b.r*a.p)/(a.r+b.r));
		return ret;
	}
	if(containCC(a,b)||containCC(b,a)) return ret;
	D d=abs(a.p-b.p);
	D theta=acos((a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d));
	ret.pb(a.p+(b.p-a.p)/d*polar(a.r,-theta));
	ret.pb(a.p+(b.p-a.p)/d*polar(a.r,theta));
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
		ret.pb(L(a.p+p,b.p+p));
		ret.pb(L(a.p-p,b.p-p));
		return ret;
	}
	P p=(a.r*b.p-b.r*a.p)/(a.r-b.r);
	return tanCP(a,p);
}
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
//enum ENCONT{INP=1,ONP=0,OUTP=-1};
int contain(Pol pol, P p){
	bool in=false;
	rep(i,pol.size()){
		P a=pol[i]-p,b=pol[(i+1)%pol.size()]-p;
		if(ccw(a,b,P(0,0))==0) return 0;
		if(imag(a)>imag(b)) swap(a,b);
		if(sig(imag(a))<=0 && 0<sig(imag(b)) && ccw(P(0,0),a,b)==1) in=!in;
	}
	return in ? 1 : -1;
}
L BL;
bool compBL(const P& a,const P& b){			//BL上の点をソート(BL.fs側が小さい)
	return dot(BL.sc-BL.fs,a-BL.fs)<dot(BL.sc-BL.fs,b-BL.fs);
}
bool containE(Pol pol,L l){			//polは閉集合だと思って.
	vector<P> ps;
	ps.pb(l.fs);
	ps.pb(l.sc);
	int N=pol.size();
	rep(i,N){
		L a(pol[i],pol[(i+1)%N]);
		if(ispal(a,l)) continue;
		if(!ispal(a,l)&&iSS(a,l)) ps.pb(intLL(a,l));
	}
	BL=l;
	sort(all(ps),compBL);
	int K=ps.size();
	rep(i,K-1) ps.pb((ps[i]+ps[i+1])/2.0);
	for(P p:ps) if(!contain(pol,p)) return 0;
	return 1;
}
inline D heron(D a, D b, D c){
	double s=(a+b+c)/2;
	if(s-a<eps || s-b<eps || s-c<eps) return 0;		//S=0 || 三角形できない
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
inline Pol conv(Pol p){		//convex
	int n=p.size(),k=0;
	sort(all(p),compxy);
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
	sort(all(p),compxy);
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
	ret.erase(unique(all(ret)),ret.end());
	return ret;
}
inline Pol convexcut(Pol p,L l){	//ccw,leftが残る
	Pol ret;
	rep(i,p.size()){
		if(ccw(l.fs,l.sc,p[i])!=-1) ret.pb(p[i]);
		L s=L(p[i],p[(i+1)%p.size()]);
		if(iLSex(l,s)) ret.pb(intLL(l,s));
	}
	return ret;
}
inline Pol interpol(Pol a,Pol b){	//ccw,ccw
	rep(j,b.size()){
		a=convexcut(a,L(b[j],b[(j+1)%b.size()]));
	}
	return a;
}
inline vector<Pol> makevoronoi(Pol vp,Pol pol){	//left
	vector<Pol> ret;
	Pol polc=pol;
	rep(i,vp.size()){
		pol=polc;
		rep(j,vp.size()){
			if(i==j) continue;
			P p=(vp[i]+vp[j])/2.0,q=p+(vp[j]-vp[i])*P(0,1);
			pol=convexcut(pol,L(p,q));
		}
		ret.pb(pol);
	}
	return ret;
}
inline D pol_diameter(Pol p){
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
inline D closest_pair(P *a, int n){
	if(n<=1) return inf;
	int m=n/2;
	D x=a[m].X;
	D d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compyx);
	vector<P> b;
	rep(i,n){
		if(abs(x-a[i].X)>=d) continue;
		rep(j,b.size()){
			P dp=a[i]-b[b.size()-1-j];
			if(dp.Y>=d) break;
			d=min(d,abs(dp));
		}
		b.pb(a[i]);
	}
	return d;
}
inline D compute_shortest(P *a,int n){
	sort(a,a+n,compxy);
	return closest_pair(a,n);
}
