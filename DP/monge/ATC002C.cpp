// http://atc002.contest.atcoder.jp/tasks/atc002_c
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmax(x,y) x=max(x,y)
template<class S,class T> bool chmin(S& x,T y){
	if(x>y){x=y;return 1;}
	return 0;
}
using namespace std;

/*
刺身系
w:monge & monotone の時
dp[l][r]=min(dp[l][i]+dp[i+1][r])+w[l][r]
		l<=i<r

d=r-lが短い順に埋める
initialize
dp[i][i]=0

をO(N^2)で解く
*/
typedef long long ll;
typedef pair<ll,int> P;
const int MAX_N=3000;
ll a[MAX_N],asum[MAX_N+1];
ll cost(int l,int r){		//[l,r)
	return asum[r]-asum[l];
}
ll dp[MAX_N][MAX_N+1];
int ar[MAX_N][MAX_N+1];
ll inf=1e17;
ll monge(int N){
	rep(i,N) rep(j,N+1) dp[i][j]=inf;
	rep(i,N) dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;
	for(int d=2;d<=N;d++){
		rep(l,N+1-d){
			int r=l+d;
			int L=ar[l][r-1];
			int R=ar[l+1][r];
			for(int i=L;i<=R;i++){
				if(chmin(dp[l][r],dp[l][i]+dp[i][r])) ar[l][r]=i;
			}
			dp[l][r]+=cost(l,r);
		}
	}
	return dp[0][N];
}


int main(){
	int N;
	cin>>N;
	rep(i,N) cin>>a[i],asum[i+1]=asum[i]+a[i];
	cout<<monge(N)-asum[N]<<endl;
}
