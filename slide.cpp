/*
	スライド最小値(deque)
	未だにパッと書けないのやばすぎる
	idからアクセスできるようにしといてdeque<int>にするのが一番楽そう
	尺取系ならなんでもできる
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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

int N;
int a[100];

vector<int> calcmins(int L){	//[0,L),[1,L+1),...,[N-L,N)
	vector<int> ret;
	deque<int> deq;
	auto rsucc = [&](int i){
		while(!deq.empty() && a[deq.back()]>a[i]) deq.pop_back();
		deq.push_back(i);
	};
	auto lsucc = [&](int i){
		if(!deq.empty() && deq.front()==i) deq.pop_front();
	};
	rep(i,N){
		rsucc(i);
		if(i>=L-1){
			ret.pb(deq.front());
			lsucc(i-L+1);
		}
	}
	return ret;
}

int main(){
	int L;
	cin>>N>>L;
	rep(i,N) cin>>a[i];
	show(calcmins(L));
}
