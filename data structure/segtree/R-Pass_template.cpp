/*
	point assign,range ほげ(+)
	semigroup D でのsegtree

	変えるべきところは,
	- Dのメンバ変数
	- Dのコンストラクタ
	- operator+
	- structの外のD::eのinitialize
	- (あとお好みでoperator<<)

*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define show(x) cout<< #x <<" "<<x<<endl
using namespace std;

struct D{
	int x;
	D(){}
	D(int x):x(x){}
	const static D e;
	D operator+(const D& r) const {
		return D(x+r.x);
	}
	friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}
};
const D D::e = D(0);

template<class D>
struct segtree{
	static const int N=1<<;

	D e=D::e;
	vector<D> seg;
	segtree():seg(N*2,e){}
	segtree(vector<D>& vc):seg(N*2,e){
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
	}
	void update(int k,D val){
		k+=N;
		seg[k]=val;
		k/=2;
		while(k){
			seg[k]=seg[k*2]+seg[k*2+1];
			k/=2;
		}
	}
	D calc(int a,int b,int l=0,int r=N,int k=1){
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