#include<iostream>
#include<cstdio>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

int root[200005];
struct segtree{
	int lch_[4000000],rch_[4000000];
	int val_[4000000];

	int *lch,*rch,*val;
	int cnt;
	
	void init(){
		lch=&lch_[1];
		rch=&rch_[1];
		val=&val_[1];

		lch[-1]=rch[-1]=-1;
		val[-1]=0;
		cnt=0;
	}
	int query(int a,int b,int i,int l,int r){
		if(i==-1) return 0;

		if(a<=l && r<=b){
			return val[i];
		}
		if(b<=l || r<=a) return 0;

		int md=(l+r)>>1;
		return query(a,b,lch[i],l,md)+query(a,b,rch[i],md,r);
	}
	int set(int p,int i,int l,int r){
		if(r-l==1){
			int v=cnt;++cnt;
			lch[v]=rch[v]=-1;
			val[v]=1+val[i];

			return v;
		}
		int md=(l+r)>>1;
		int v=cnt;++cnt;
		if(p<md){
			lch[v]=set(p,lch[i],l,md);
			rch[v]=rch[i];
		}else{
			rch[v]=set(p,rch[i],md,r);
			lch[v]=lch[i];
		}
		val[v]=val[lch[v]]+val[rch[v]];
		return v;
	}
};


segtree seg;
	
int n;

pi range[200005];
//const int INF=5e8;
int main(){
	root[0]=-1;
	cin>>n;
	REP(i,n) cin>>range[i].fr;
	REP(i,n) cin>>range[i].sc;
	
	seg.init();
	int x=0;
	REP(i,n){
		root[i+1]=seg.set(x,root[i],0,n);
		int cnt=seg.query(range[i].fr,range[i].sc,root[x+1],0,n);
		x=(cnt*(lint)range[i].fr+range[i].sc)%(i+2);
	}
	cout<<x<<endl;


	return 0;
}