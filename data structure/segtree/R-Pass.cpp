/*
	point assign,range +
	書くものは
	D op()	(演算)
	D e		(単位元)
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define chmax(x,y) x=max(x,y)
using namespace std;

template<class D>
struct segtree_simple{
	int N;
	vector<D> val;

	segtree_simple(){}
	segtree_simple(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e);
	}
	segtree_simple(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D query(int a,int b){
		return query(a,b,0,N,1);
	}
	D query(int a,int b,int l,int r,int k){
		if(b<=l||r<=a) return D::e;
		if(a<=l&&r<=b) return val[k];
		return query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);
	}
};

struct Dplus{		//(int,+,0)
	int x;
	Dplus(){*this = e;}
	Dplus(int x):x(x){}
	const static Dplus e;
	Dplus operator+(const Dplus& r) const {
		return Dplus(x+r.x);
	}
	friend ostream& operator<<(ostream& o,const Dplus& d){return o<<d.x;}
};
const Dplus Dplus::e = Dplus(0);

struct Dmax{		//(int,max,-inf)
	int x;
	Dmax(){*this = e;}
	Dmax(int x):x(x){}
	const static Dmax e;
	Dmax operator+(const Dmax& r) const {
		return Dmax(max(x,r.x));
	}
	friend ostream& operator<<(ostream& o,const Dmax& d){return o<<d.x;}
};
const Dmax Dmax::e = Dmax(-1e9);

struct Dmin{		//(int,min,inf)
	int x;
	Dmin(){*this = e;}
	Dmin(int x):x(x){}
	const static Dmin e;
	Dmin operator+(const Dmin& r) const {
		return Dmin(min(x,r.x));
	}
	friend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}
};
const Dmin Dmin::e = Dmin(1e9);

struct Dleftmostmax{		//(int,max,-inf)
	int x,a;	//val,argid
	Dleftmostmax(){*this = e;}
	Dleftmostmax(int x,int a):x(x),a(a){}
	const static Dleftmostmax e;
	Dleftmostmax operator+(const Dleftmostmax& r) const {
		if(x>r.x || (x==r.x&&a<r.a)) return *this;
		else return r;
	}
	friend ostream& operator<<(ostream& o,const Dleftmostmax& d){return o<<d.x;}
};
const Dleftmostmax Dleftmostmax::e = Dleftmostmax(-1e9,-1);

void unittest(){	//どっちかというとstruct Dのテスト
	{
		vector<Dplus> vs = {4,2,5,4,8,3,1,4,1,5};
		segtree_simple<Dplus> seg(vs);
		rep(l,10) for(int r=l;r<=10;r++){
			int sum = 0;
			for(int i=l;i<r;i++) sum+=vs[i].x;
			assert( seg.query(l,r).x == sum );
		}
	}
	{
		vector<Dmax> vs = {-4,2,-5,-4,8,-3,1,-4,1,5};
		segtree_simple<Dmax> seg1(vs);
		rep(l,10) for(int r=l;r<=10;r++){
			int mx = Dmax::e.x;
			for(int i=l;i<r;i++) chmax(mx,vs[i].x);
			assert( seg1.query(l,r).x == mx );
		}
	}
	{
		using D = Dleftmostmax;
		vector<int> vi = {1,1,2,1,3,2,1,3,2,1};
		vector<D> vs;
		rep(i,10) vs.push_back(D(vi[i],i));
		segtree_simple<D> seg(vs);
		rep(l,10) for(int r=l+1;r<=10;r++){
			int mx = D::e.x;
			int ag = -1;
			for(int i=l;i<r;i++){
				if(mx<vi[i]){
					mx=vi[i];
					ag=i;
				}
			}
			assert( seg.query(l,r).a == ag );
		}
	}
}
int main(){
	unittest();
}