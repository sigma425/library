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
