/*
刺身系
[0,N)を分割する

w:monge & monotone の時
dp[l][r]=min(dp[l][i]+dp[i][r])+w[l][r]
		l<i<r

をO(N^2)で解く

verified by http://atc002.contest.atcoder.jp/tasks/atc002_c

*/

const int MAX_N=3000;
ll cost(int l,int r){		//[l,r)
	return w[l][r];
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
