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

int bsr(unsigned int x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}

template<class D>
struct SparseTable{
	vector<vector<D>> d;
	int lg;

	SparseTable(){}
	SparseTable(const vector<D>& v){
		int N = v.size();
		assert(N > 0);

		lg = bsr(N)+1;
		d.resize(lg);
		d[0] = v;
		for(int t=1;t<lg;t++){
			int len = 1<<(t-1);
			d[t].resize(N-len);
			rep(i,N-len){
				d[t][i] = d[t-1][i] + d[t-1][i+len];
			}
		}
	}
	D query(int l, int r) const {
		if(l>=r) return D::e();
		int u = bsr(r-l);
		return d[u][l]+d[u][r-(1<<u)];
	}
};

struct Dmax{		//(int,max,-inf)
	int x;
	Dmax(){*this = e();}
	Dmax(int x):x(x){}
	static Dmax e(){
		return Dmax(-1e9);
	}
	Dmax operator+(const Dmax& r) const {
		return Dmax(max(x,r.x));
	}
	friend ostream& operator<<(ostream& o,const Dmax& d){return o<<d.x;}
};

void unittest(){
	vector<Dmax> vc;
	rep(i,10) vc.pb(Dmax((i-4)*(i-4)));
	SparseTable<Dmax> stable(vc);
	rep(l,10) for(int r=l;r<10;r++){
		Dmax acc;
		for(int i=l;i<r;i++) acc = acc + vc[i];
		if(acc.x != stable.query(l,r).x){
			printf("[%d,%d)\n",l,r);
			show(acc.x);
			show(stable.query(l,r).x);
			assert(0);
		}
	}
}
int main(){
	unittest();
}