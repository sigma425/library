/*
	スライド最小値っていちいち配列作って・・・ってやると重いことが多い気がするので使いまわし可能なやつを作った
	でもグローバルは流石に嫌だから、namespaceで
*/

// shiyourei
// nf[i] = max(f[i], f[i-w]+p, .., f[i-nw]+np)
// (w,p) が n 個あるときの個数制限付きナップザック

void slide(V<ll>& f, int w, ll p, int n){
	int W = si(f)-1;
	rep(r,w){
		SlideMax::clear();
		if(r > W) break;
		for(int i=0,x=r;x<=W;i++,x+=w){
			SlideMax::add(f[x]-i*p);
			f[x] = SlideMax::getmax() + i*p;
			if(f[x] < -inf/2) f[x] = -inf;
			if(i >= n) SlideMax::del();
		}
	}
}


namespace SlideMin{
	using D = int;
	const int X = 1000000;
	D a[X];
	int idx[X];
	int L,R,I,num_del;
	void clear(){
		L = R = I = num_del = 0;
	}
	void add(D v){
		while(L<R && v<a[R-1]) R--;			// D-D comparison v<a[R-1]
		a[R] = v;
		idx[R] = I;
		R++,I++;
	}
	void del(){
		if(L<R && idx[L] == num_del) L++;
		num_del++;
	}
	D getmin(){
		assert(L<R);
		return a[L];
	}
	int getargmin(){
		assert(L<R);
		return idx[L];
	}
}
namespace SlideMax{
	using D = int;
	const int X = 1000000;
	D a[X];
	int idx[X];
	int L,R,I,num_del;
	void clear(){
		L = R = I = num_del = 0;
	}
	void add(D v){
		while(L<R && v>a[R-1]) R--;			// D-D comparison v<a[R-1]
		a[R] = v;
		idx[R] = I;
		R++,I++;
	}
	void del(){
		if(L<R && idx[L] == num_del) L++;
		num_del++;
	}
	D getmax(){
		assert(L<R);
		return a[L];
	}
	int getargmax(){
		assert(L<R);
		return idx[L];
	}
}


/*
	スライド最小値
	[0,L), [1,L+1), .. , [N-L,N) のうちの !!!ARGMIN!!! を返す

	maxにしたければrsuccのwhileの不等式を逆にする

	長さ一定じゃなくても、書き換えれば尺取っぽいやつは全てできる
*/

template<class D>
vector<int> calcmins(vector<D> a,int L){
	int N = a.size();

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
