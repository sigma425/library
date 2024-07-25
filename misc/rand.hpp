#pragma once

/*
	xorshift64
	決定的にしたければ x の初期値を適当に固定
*/
#include <chrono>
#include <climits>
using ull = unsigned long long;
ull xorshift() {
	static ull x = ull(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) * 10150724397891781847ULL;
	x ^= x<<7;
	return x ^= x>>9;
}

// [0,n)
ull rng(ull n){
	return xorshift()%n;
}
// [l,r] 閉区間！！
ull rng(ull l, ull r){
	return l + xorshift() % (r-l+1);
}

// 確率pでtrue
double gen_bool(double p){
	if(p <= 0) return false;
	if(p >= 1) return true;
	return xorshift() < ULLONG_MAX * p;
}