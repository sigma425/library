/*
	スライド最小値っていちいち配列作って・・・ってやると重いことが多い気がするので使いまわし可能なやつを作った
	でもグローバルは流石に嫌だから、namespaceで

	例: f[x] = min(f[x],f[x-v]+1,f[x-2v]+2,..f[x-Kv]+K)
	rep(r,v){
		SlideMin::clear();
		for(int x=r;x<=S;x+=v){
			int i = x/v;
			SlideMin::add(sum2mn[x]-i);
			sum2mn[x] = SlideMin::getmin()+i;
			if(i>=K) SlideMin::del();
		}
	}
*/

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
