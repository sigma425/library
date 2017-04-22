/*
	point assign,range +
	semigroup D でのsegtree

	変えるべきところは,
	- Dのメンバ変数
	- Dのコンストラクタ
	- operator+
	- structの外のD::eのinitialize
	- (あとお好みでoperator<<)

	外から使うのは
	- update(0-indexed)
	- calc(0-indexed 半開区間)
	- あとinit

	20161209
*/

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define show(x) cout<< #x <<" "<<x<<endl
using namespace std;

struct D{
	int x;
	D(){*this = e;}
	D(int x):x(x){}
	const static D e;
	D operator+(const D& r) const {
		return D(x+r.x);
	}
	friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}
};
const D D::e = D(0);

template<class T>
struct segtree{
	int N;

	T e=T::e;
	vector<T> seg;
	segtree(){}
	segtree(int n){
		init(n);
	}
	segtree(vector<T>& vc){
		init(vc);
	}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		seg.assign(N*2,e);
	}
	void init(vector<T>& vc){
		N=1;
		int n=vc.size();
		while(N<n) N*=2;
		seg.assign(N*2,e);
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
	}
	void update(int x,T val){
		x+=N;
		seg[x]=val;
		x/=2;
		while(x){
			seg[x]=seg[x*2]+seg[x*2+1];
			x/=2;
		}
	}
	T calc(int a,int b,int l=0,int r=-1,int k=1){
		if(r==-1) r=N;
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		return calc(a,b,l,(l+r)/2,k*2)+calc(a,b,(l+r)/2,r,k*2+1);
	}
};
segtree<D> seg;
int main(){
	int N;
	cin>>N;
	vector<D> vc;
	rep(i,N){
		int x;
		cin>>x;
		vc.push_back(D(x));
	}
	seg=segtree<D>(vc);
	while(true){
		int l,r;
		cin>>l>>r;
		r++;
		cout<<"ans="<<seg.calc(l,r)<<endl;
	}
}