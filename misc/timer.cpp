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
struct Timer{
	clock_t st;
	void start(){
		st = clock();
	}
	int ms(){
		return (clock()-st)*1000 / CLOCKS_PER_SEC;
	}
};
int main(){
	Timer timer;
	timer.start();
	unsigned long long ans = 0;
	for(unsigned long long i = 1; i<=1000000000ull; i++ ){
		ans ^= i;
	}
	show(ans);
	show(timer.ms());
}
