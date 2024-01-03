/*
	mo-algorithm
	区間クエリがいっぱい来るときに、区間の1ひきのばしと1けずりが速くできるなら全体で(Q+N)sqrt(N) * その計算量 でクエリを回せる
	削れないときは → snapshot (snukeブログ参照)
	区間同士のmergeができるなら普通にsegtreeだけど、出来ないとき(ソート系が入るとだいたいそう)はこれ.
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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef pair<int,int> P;
typedef pair<P,int> PP;
PP qs[100000];
const int B = 320;
bool cmp(const PP& a,const PP& b){
	if(a.fs.fs/B != b.fs.fs/B) return a.fs.fs/B < b.fs.fs/B;
	return a.fs.sc < b.fs.sc;
}

typedef long long ll;
struct BIT{
	int N;
	vector<ll> bit;
	void init(int n){
		N=n;
		bit.resize(n+1);
	}
	ll sum(int i){		//i個の和a[0]+..a[i-1]
		ll s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	void add(int i,int x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
}bit,sbit;


ll sum = 0;
ll ssum = 0;
const int MX = 100000;
void add(int v){
	int id=bit.sum(v);
	sum += (ll)(id*2+1) * v;
	sum += (ssum-sbit.sum(v))* 2;
	bit.add(v,1);
	sbit.add(v,v);
	ssum+=v;
	// show(v);
	// show(id);
	// show(sum);
}
void erase(int v){
	int id=bit.sum(v);
	bit.add(v,-1);
	sbit.add(v,-v);
	ssum-=v;
	sum -= (ll)(id*2+1) * v;
	sum -= (ssum-sbit.sum(v))* 2;
	// show(v);
	// show(id);
	// show(sum);
}

int N,Q,a[100000];
double ans[100000];
int main(){
	bit.init(100010);
	sbit.init(100010);
	cin>>N>>Q;
	rep(i,N) cin>>a[i];
	rep(i,Q){
		int l,r;
		cin>>l>>r;
		qs[i]=PP(P(l-1,r),i);
	}
	sort(qs,qs+Q,cmp);
	int L=0,R=0;
	rep(t,Q){
		int l=qs[t].fs.fs,r=qs[t].fs.sc,id=qs[t].sc;
		for(;l<L;) add(a[--L]);
		for(;r>R;) add(a[R++]);
		for(;l>L;) erase(a[L++]);
		for(;r<R;) erase(a[--R]);
		// printf("[%d,%d)\n",L,R);
		// show(sum);
		ans[id]= (double)sum/(R-L)/(R-L);
	}
	rep(i,Q) printf("%.12f\n",ans[i]);
}
