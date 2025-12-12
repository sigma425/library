#pragma once

/*
	xorshift64
	決定的にしたければ x の初期値を適当に固定
*/
#include <chrono>
#include <climits>
using ll = long long;
using ull = unsigned long long;

ull _xorshift = 99882244335533ULL;
ull xorshift() {
	_xorshift ^= _xorshift<<7;
	return _xorshift ^= _xorshift>>9;
}
void set_seed(ull seed){
	_xorshift = seed;
}
void set_seed_nondeterministic(){
	_xorshift = ull(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) * 10150724397891781847ULL;
}

// [0,n)
ull rng(ull n){
	return xorshift()%n;
}
// [l,r] 閉区間！！ 負でも良い
ll rng(ll l, ll r){
	return l + xorshift() % (r-l+1);
}

// 確率pでtrue
bool gen_bool(double p){
	if(p <= 0) return false;
	if(p >= 1) return true;
	return xorshift() < ULLONG_MAX * p;
}

void my_shuffle(auto first, auto last){
	int n = last - first;
	for(int i = 1; i < n; i++){
		int j = rng(0, i);
		swap(first[i], first[j]);
	}
}