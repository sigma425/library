/*
N個中K個選んでできるものの和を列挙(総和をSとする)
O(NS)
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
const int MAX_N=600,MAX_S=100000,inf=1e9;
int N,K,a[MAX_N];
int dp0[MAX_N][MAX_S+1];
int dp1[MAX_N][MAX_S+1];
int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	int S=accumulate(a,a+N,0);
	for(int j=K;j<=N;j++) rep(s,S+1) dp0[j][s]=dp1[j][s]=inf;
	dp0[K][accumulate(a,a+K,0)]=0;
	for(int j=K;j<=N;j++){
		rep(s,S+1){
			if(dp1[j][s]==inf) continue;
			chmin(dp1[j+1][s],dp1[j][s]);
			int l=dp1[j][s],r=K;
			if(j>K) chmin(r,dp1[j-1][s]);
			for(int i=l;i<r;i++) chmin(dp0[j][s-a[i]],i+1);
		}
		rep(s,S+1){
			if(dp0[j][s]==inf) continue;
			chmin(dp0[j+1][s],dp0[j][s]);
			chmin(dp1[j+1][s+a[j]],dp0[j][s]);
		}
	}
	rep(s,S+1) if(dp0[N][s]!=inf) cout<<s<<" ";
	puts("");
}
