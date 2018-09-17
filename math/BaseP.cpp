/*
	base-10のstringをp進表記にしたのを返す ret[0]が1の位
	O(L^2)
*/
vector<ll> Basep(string s,ll p){
	int L=s.size();
	int up=4000;
	vector<ll> ret(up,0);
	int N=0;
	rep(i,L){
		rep(j,N) ret[j]*=10;
		ret[0]+=s[i]-'0';
		int j=0;
		while(j<N-1||ret[j]>=p){
			ret[j+1]+=ret[j]/p;
			ret[j]%=p;
			j++;
		}
		N=j+1;
	}
	ret.erase(ret.begin()+N,ret.end());
	return ret;
}
