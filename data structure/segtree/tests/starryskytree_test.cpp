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
/*
	range add,range min
	http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d
*/
int inf=1e9;
struct starryskytree{
	static const int N=1<<17;
	int mx[N*2],ad[N*2];
	starryskytree(){
		rep(i,N*2) mx[i]=0,ad[i]=0;
	}
	void add(int a,int b,int v,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,v,l,(l+r)/2,k*2);
		add(a,b,v,(l+r)/2,r,k*2+1);
		mx[k]=max(mx[k*2]+ad[k*2],mx[k*2+1]+ad[k*2+1]);
	}
	int getmax(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return mx[k]+ad[k];
		return ad[k]+max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));
	}
}seg;
int a[100000],b[100000];
int main(){
	int N;
	cin>>N;
	rep(i,N){
		cin>>a[i]>>b[i];
		seg.add(a[i],b[i],1);
	}
	int ans=N-1;
	rep(i,N){
		seg.add(a[i],b[i],-1);
		int tmp=seg.getmax(0,seg.N);
		chmin(ans,tmp);
		seg.add(a[i],b[i],1);
	}
	cout<<ans<<endl;
}
