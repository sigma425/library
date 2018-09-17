typedef long long ll;
const ll ccc=1000000;
bool prime[ccc+1];
vector<ll> pr;
void makeprime(){
	ll i,j;
	for(i=2;i<=ccc;i++) prime[i]=true;
	for(i=2;i*i<=ccc;i++) if(prime[i]) for(j=2;j*i<=ccc;j++) prime[j*i]=false;
	for(i=2;i<=ccc;i++) if(prime[i]) pr.push_back(i);
}
