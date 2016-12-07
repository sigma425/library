/*
use under a[i][j]!=0 -> abs(i-j)<=B
(高々+-Bにしか辺が貼られてない)
掃き出し時のswapの影響で,-B~+2Bまでの3B+1個をviの中に持ってる
適当に0をつめてB-th value(0-indexed) がa[i][i]になるようにしている
time O(NB^2)
space O(NB)
*/
typedef long long ll;
ll mod=1e9+7;
typedef vector<ll> vi;
typedef vector<vi> bmat;
ll ex(ll x,ll p){
	ll a=1;
	while(p){
		if(p%2) a=a*x%mod;
		x=x*x%mod;
		p/=2;
	}
	return a;
}
ll inv(ll a){
	return ex(a,mod-2);
}
ll det(bmat a){
	int N=a.size();
	int B=a[0].size()/3;
	ll ans=1;
	rep(i,N){
		if(a[i][B]==0){
			for(int j=i+1;j<N;j++){
				if(B-(j-i)<0) break;
				if(a[j][B-(j-i)]!=0){
					int d=j-i;
					for(int k=d;k<=2*B+d;k++){
						swap(a[i][k],a[j][k-d]);
					}
					ans*=-1;
					break;
				}
			}
			if(a[i][B]==0) return 0;
		}
		for(int j=i+1;j<N;j++){
			if(B-(j-i)<0) break;
			int d=j-i;
			ll c=a[j][B-d]*inv(a[i][B])%mod;
			for(int k=B;k<=3*B;k++){
				a[j][k-d]=(a[j][k-d]-c*a[i][k])%mod;
			}
		}
		ans=ans*a[i][B]%mod;
	}
	if(ans<0) ans+=mod;
	return ans;
}