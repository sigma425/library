/*
	最適二分探索木に対する Hu-Tucker algorithm O(NlogN)
	!! meldable heap をメモリプールの関係上グローバルに置いてるので、テンプレート型を直接変えること !!

	復元はマージ仮定の木 (invalid) から深さを計算し、そこから正しい木を計算する必要があり、やや大変そう
	verify:
		https://atcoder.jp/contests/atc002/tasks/atc002_c
	reference:
		https://web.archive.org/web/20220802104424/https://math.mit.edu/~shor/PAM/hu-tucker_algorithm.html
*/

#include "ds/persistent_meldable_heap.hpp"

PersistentMeldableHeap<ll> heap;
using NP = decltype(heap)::NP;

template<class T>
T hu_tucker(vector<T> A){
	constexpr T inf = numeric_limits<T>::max()/2;
	int N = A.size();
	vector<NP> hs(N-1, nullptr);
	vector<int> ls(N),rs(N);
	vector<T> cs(N-1);
	using P = pair<T,int>;
	priority_queue<P,vector<P>,greater<P>> q;
	rep(i,N-1){
		ls[i] = i-1, rs[i] = i+1, cs[i] = A[i]+A[i+1];
		q.emplace(cs[i],i);
	}
	T res = 0;
	rep(_,N-1){
		T cost; int i;
		while(true){
			tie(cost,i) = q.top(); q.pop();
			if(rs[i] >= 0 && cs[i] == cost) break;
		}
		bool ml = false, mr = false;
		if(hs[i] && A[i] + heap.top(hs[i]) == cost){
			hs[i] = heap.pop(hs[i]);
			ml = true;
		}else if(A[i] + A[rs[i]] == cost){
			ml = mr = true;
		}else{
			auto mn = heap.top(hs[i]); hs[i] = heap.pop(hs[i]);
			if(hs[i] && heap.top(hs[i]) + mn == cost){
				hs[i] = heap.pop(hs[i]);
			}else{
				mr = true;
			}
		}
		res += cost;
		hs[i] = heap.push(hs[i],cost);
		if(ml) A[i] = inf;
		if(mr) A[rs[i]] = inf;

		if(ml && i > 0){
			int j = ls[i];
			hs[j] = heap.merge(hs[j], hs[i]);
			rs[j] = rs[i]; rs[i] = -1; ls[rs[j]] = j;
			i = j;
		}
		if(mr && rs[i] < N-1){
			int j = rs[i];
			hs[i] = heap.merge(hs[i], hs[j]);
			rs[i] = rs[j]; rs[j] = -1; ls[rs[i]] = i;
		}
		cs[i] = A[i] + A[rs[i]];
		if(hs[i]){
			auto mn = heap.top(hs[i]);
			chmin(cs[i], min(A[i],A[rs[i]])+mn);
			NP tmp = heap.pop(hs[i]);
			if(tmp) chmin(cs[i], mn+heap.top(tmp));
		}
		q.emplace(cs[i],i);
	}
	return res;
}
