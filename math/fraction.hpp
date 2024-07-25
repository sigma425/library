/*
	有理数体
	任意/正, gcd = 1 で常に持つ
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (Q上で連立方程式)

	using F = Frac<ll>;
*/

#pragma once
#include <ostream>

template<class Int>
struct Frac{
	Int x,y;		// x/y
	Frac(Int x_ = 0):x(x_),y(1){}
	Frac(Int x_,Int y_){
		Int g = __gcd((x_>=0?x_:-x_),(y_>=0?y_:-y_));	// int128だとgcd,absとかが使えないので
		if(y_ < 0) g = -g;
		x = x_ / g;
		y = y_ / g;
	}

	Frac operator-() const { return {-x,y}; }
	Frac operator+(const Frac& r) const { return {x * r.y + y * r.x, y * r.y}; }
	Frac operator-(const Frac& r) const { return *this + (-r); }
	Frac operator*(const Frac& r) const { return {x * r.x, y * r.y}; }
	Frac operator/(const Frac& r) const { return {x * r.y, y * r.x}; }
	Frac& operator+=(const Frac& r) { return *this = *this + r; }
	Frac& operator-=(const Frac& r) { return *this = *this - r; }
	Frac& operator*=(const Frac& r) { return *this = *this * r; }
	Frac& operator/=(const Frac& r) { return *this = *this / r; }
	template<class T> friend Frac operator+(T a, const Frac& b){ return (Frac(a) += b);}
	template<class T> friend Frac operator-(T a, const Frac& b){ return (Frac(a) -= b);}
	template<class T> friend Frac operator*(T a, const Frac& b){ return (Frac(a) *= b);}
	template<class T> friend Frac operator/(T a, const Frac& b){ return (Frac(a) /= b);}
	bool operator<(const Frac& r) const { return x * r.y < y * r.x; }
	bool operator>(const Frac& r) const { return r < *this; }
	bool operator<=(const Frac& r) const { return !(r < *this); }
	bool operator>=(const Frac& r) const { return !(*this < r); }
	bool operator==(const Frac& r) const { return x == r.x && y == r.y; }
	bool operator!=(const Frac& r) const { return !(*this == r); }
	explicit operator bool() const {return x!=0;}
	Frac inv() const {
		return Frac(y,x);
	}
	friend std::ostream& operator<<(std::ostream &o,const Frac& x){
		return o << x.x << "/" << x.y;
	}
};