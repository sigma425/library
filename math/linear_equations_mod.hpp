/*
	一変数 x に対して、 x = r mod m や ax = r mod m などの条件を追加した結果最終的に
	x = r mod m になります、という (r,m) を保持する関数群
	どの段階でも 0 <= r < m を仮定
	解が存在しないものは (0,-1) で表す
	検索用: crt, garner, gcd
*/

#include "template.hpp"

template<class T> struct EG { T g, x, y; };
template<class T>
EG<T> extgcd_sub(T a, T b) {
	if(b == 0){
		if (a >= 0) return {a, 1, 0};
		else return {-a, -1, 0};
	}else{
		auto e = extgcd_sub(b, a % b);
		return {e.g, e.y, e.x - a / b * e.y};
	}
}
template<class T>
EG<T> extgcd(T a, T b){
	auto e = extgcd_sub(a,b);
	if(e.x < 0){
		if(b > 0){
			e.x += b/e.g;
			e.y -= a/e.g;
		}else{
			e.x -= b/e.g;
			e.y += a/e.g;
		}
	}
	return e;
}

/*
	x = r1 mod m1, x = r2 mod m2
	<=> x = r mod m
*/
template<class T>
pair<T,T> crt2(T r1, T m1, T r2, T m2){
	if(m1 == -1 || m2 == -1) return {0,-1};
	auto e = extgcd(m1,m2);
	T g = e.g;
	if((r2-r1)%g) return {0,-1};
	T q = (r2-r1)/g * e.x % (m2/g);
	T r = r1 + m1 * q;
	T m = m1 * (m2/g);
	if(r < 0) r += m;
	return {r,m};
}

/*
	ax = r mod m
	<=> x = r' mod m'
*/
template<class T>
pair<T,T> get_monic(T a, T r, T m){
	if(m == -1) return {0,-1};
	auto [rr,mm] = crt2<T>(r,m,0,a);
	if(mm == -1) return {0,-1};
	return {rr/a, mm/a};
}