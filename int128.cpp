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

typedef __int128 ll;
istream& operator>>(istream& i, ll& x){
	x=0;
	string s;
	i>>s;
	int N=s.size(),it=0;
	if(s[0]=='-') it++;
	for(;it<N;it++) x=(x*10+s[it]-'0');
	if(s[0]=='-') x=-x;
	return i;
}
ostream& operator<<(ostream& o, const ll& x){
	ll tmp=x;
	if(tmp==0) return o<<0;
	if(tmp<0) o<<'-',tmp=-tmp;
	vector<int> ds;
	while(tmp) ds.pb(tmp%10),tmp/=10;
	reverse(all(ds));
	for(int d:ds) o<<d;
	return o;
}
int main(){
	while(true){
		ll x;
		cin>>x;
		if(x==114514) break;
		cout<<x+1<<endl;
	}
}