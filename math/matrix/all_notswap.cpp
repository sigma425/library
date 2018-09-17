/*
usedを持ってやる
detが未実装
verified by http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
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
template<class T>
ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"sz="<<vc.size()<<endl<<"[";
	for(T& v:vc) o<<v<<",";
	cout<<"]"<<endl;
	return o;
}
// Z/pZ
typedef long long ll;
struct mint{
	const static ll mod=3;
	ll a;
	mint():a(0){}
	mint(ll a):a((a%mod+mod)%mod){}
	mint operator+=(const mint& b){ if((a+=b.a)>=mod) a-=mod; return *this;}
	mint operator-=(const mint& b){ if((a+=mod-b.a)>=mod) a-=mod; return *this;}
	mint operator*=(const mint& b){ (a*=b.a)%=mod; return *this;}
	mint operator+(const mint& b){ return mint(*this)+=b;}
	mint operator-(const mint& b){ return mint(*this)-=b;}
	mint operator*(const mint& b){ return mint(*this)*=b;}
	int extgcd(int a,int b,int &x,int &y) const{
		int u[]={a,1,0},v[]={b,0,1};
		while(*v){
			int t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	mint inv() const{
		int x,y;
		extgcd(a,mod,x,y);
		if(x<0) x+=mod;
		return mint(x);
	}
	mint operator/=(const mint& b){ (*this)*=b.inv(); return *this; }
	mint operator/(const mint& b){ return mint(*this)/=b;}
	bool operator==(const mint& b) const { return a==b.a;}
	friend ostream& operator<<(ostream &o,const mint& x){ return o<<x.a;}
};
const mint zero(0),one(1);
bool iszero(mint x){
	return x.a==0;
}
/*double
const double zero=0,one=1;
bool iszero(double x){
	return abs(x)<1e-9;
}
*/
template<class T>
struct Matrix{
	int H,W;
	vector< vector<T> > m;
	Matrix():H(0),W(0){}
	Matrix(int H,int W):H(H),W(W),m( vector< vector<T> >(H,vector<T>(W,zero)) ){}
	//↓0*W行列を渡すと壊れるので危険←そんなの渡さないでしょ・・・
	//Matrix(vector< vector<T> > m):m(m),H(m.size()),W(m[0].size()){}
	Matrix operator+=(const Matrix& b){
		assert(H==b.H&&W==b.W);
		rep(i,H) rep(j,H) m[i][j]+=b.m[i][j];
		return *this;
	}
	Matrix operator-=(const Matrix& b){
		assert(H==b.H&&W==b.W);
		rep(i,H) rep(j,H) m[i][j]-=b.m[i][j];
		return *this;
	}
	Matrix operator+(const Matrix& b){return Matrix(*this)+=b;}
	Matrix operator-(const Matrix& b){return Matrix(*this)-=b;}
	Matrix operator*(const Matrix& b){
		assert(W==b.H);
		Matrix c(H,b.W);
		rep(i,H) rep(k,W) rep(j,b.W)c.m[i][j]+=m[i][k]*b.m[k][j];
		return c;
	}
	Matrix operator*=(const Matrix& b){return (*this)=(*this)*b;}
	int sweep(int var=-1){			//return rank 副作用
		if(var<0) var=W;
		int r=0;
		vector<bool> used(H);
		rep(j,var){
			int i=0;
			while(i<H&&(used[i]||iszero(m[i][j]))) i++;
			if(i==H) continue;
			used[i]=true;
			r++;
			T t=m[i][j];
			rep(k,W) m[i][k]=m[i][k]/t;
			rep(k,H) if(k!=i){
				t=m[k][j];
				rep(l,W) m[k][l]=m[k][l]-m[i][l]*t;
			}
			show((*this));
		}
		return r;
	}
	Matrix inv(){
		assert(H==W);
		Matrix a(H,2*H);
		rep(i,H) rep(j,H) a.m[i][j]=m[i][j];
		rep(i,H) a.m[i][i+H]=one;
		int r=a.sweep(H);
		show(r);
		if(r<H) return Matrix();
		Matrix b(H,H);
		rep(i_,H){
			int i=-1;
			rep(j,H) if(a.m[i_][j]==one) i=j;
			assert(i>=0);
			rep(j,H) b.m[i][j]=a.m[i_][j+H];
		}
		return b;
	}
	pair< int,vector<T> > sle(vector<T> b){		// return pair( 解の次元(もし空集合なら-1) ,x s.t.Ax=b)
		assert(H==b.size());
		Matrix a(H,W+1);
		rep(i,H) rep(j,W) a.m[i][j]=m[i][j];
		rep(i,H) a.m[i][W]=b[i];
		a.sweep(W);
		int d=0;
		rep(i,H){
			bool all0=1;
			rep(j,W) if(!iszero(a.m[i][j])) all0=0;
			if(all0){
				if(!iszero(a.m[i][W])){
					return pair<int,vector<T> >(-1,vector<T>());
				}
				d++;
			}
		}
		rep(i_,H){
			int i=-1;
			rep(j,W) if(a.m[i_][j]==one) i=j;
			if(i<0) continue;
			b[i]=a.m[i_][W];
//			show(b[i]);
		}
		return pair<int,vector<T> >(d,b);
	}
	friend ostream& operator<<(ostream &o,const Matrix& m){
		o<<m.H<<" * "<<m.W<<endl;
		rep(i,m.H){
			o<<"[";
			rep(j,m.W) o<<m.m[i][j]<<" ";
			o<<"]"<<endl;
		}
		return o;
	}
};
int main(){
	int H,W;
	cin>>H>>W;
	Matrix<mint> mat(H,W);
	rep(i,H) rep(j,W){
		int x;
		cin>>x;
		mat.m[i][j]=mint(x);
	}
	vector<mint> b(H);
	rep(i,H){
		int x;
		cin>>x;
		b[i]=mint(x);
	}
	auto p=mat.sle(b);
	int dim=p.fs;
	show(dim);
	if(dim>=0){
		puts("one of sols");
		rep(i,H) cout<<p.sc[i]<<" ";
		puts("");
	}
//	show(mat.sweep());
	// Matrix<mint> inv=mat.inv();
	// show(mat);
	// show(inv);
	// Matrix<mint> e=mat*inv;
	// show(e);
}
