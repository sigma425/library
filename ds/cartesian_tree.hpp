/*
	cartesian tree
	一番小さいところで i 分けて、左右に分割
	range[i] = [l,r) の min/max が A[i]
	[l,i) の min が lch[i], [i+1,r) の min が rch[i] 空なら -1
	一番小さいとこが root

	tie-break は辞書順

	verify: yosupo judge
*/
template<class T, bool is_min>
struct CartesianTree {
	int N;
	vector<T> A;
	vector<pair<int,int>> range;
	vector<int> lch,rch,par;
	int root;

	CartesianTree(const vector<T>& A_): N(A_.size()), A(A_), range(N), lch(N,-1), rch(N,-1), par(N,-1){
		auto less = [&](int i, int j) -> bool {
			if(is_min) return (A[i] < A[j]) || (A[i] == A[j] && i < j);
			return (A[i] > A[j]) || (A[i] == A[j] && i < j);
		};
		vector<int> st;
		rep(i,N){
			while(!st.empty() && less(i, st.back())){
				lch[i] = st.back();
				st.pop_back();
			}
			range[i].first = (st.empty() ? 0 : st.back() + 1);
			st.eb(i);
		}
		st.clear();
		per(i,N){
			while(!st.empty() && less(i, st.back())){
				rch[i] = st.back();
				st.pop_back();
			}
			range[i].second = (st.empty() ? N : st.back());
			st.eb(i);
		}
		rep(i,N){
			if(lch[i] != -1) par[lch[i]] = i;
			if(rch[i] != -1) par[rch[i]] = i;
		}
		rep(i,N) if(par[i] == -1) root = i;
	}

	/*
		(l, r, h)
		l <= i < r
		h[i] をできるだけ左右に伸ばした時の長方形
	*/
	tuple<int, int, T> maximum_rectangle(int i){
		return {range[i].first, range[i].second, A[i]};
	}
};