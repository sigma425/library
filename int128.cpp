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
	string s;
	i>>s;
	x=0;
	for(char c:s) x=(x*10+c-'0');
	return i;
}
ostream& operator<<(ostream& o, const ll& x){
	ll tmp=x;
	vector<int> ds;
	while(tmp) ds.pb(tmp%10),tmp/=10;
	reverse(all(ds));
	for(int d:ds) o<<d;
	return o;
}
int main(){
	ll x;
	cin>>x;
	cout<<x+1<<endl;
}