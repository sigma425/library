/*
	P-recursive (holonomic) sequence の漸化式を求める
	n項目を求めるのは愚直にやっているのでこれは調べる必要あるかも? ( ただ、そこまで遅くはない O(N * order * degree) )

	P-recursive:
		Berlekamp-Massey とかで扱う漸化式は a_n = 3a_{n-1} - 10a_{n-2} とかだったけど、P-recursive では、
		(5n-3)a_n = (3n+4)a_{n-1} + (n^5)a_{n-2} みたいなのが扱える

		つまり係数にnの多項式を入れられる

		ここで、
		d := degree とは この多項式の次数のmaxのことで、 
		k := order  とは (何項間漸化式か)-1 を表す

		nを固定した一つの式に現れる変数の個数は (d+1)(k+1) なので、式をこれだけ用意すれば一意に定まる
		そのためには はじめの (d+1)(k+1) + k 項 が必要 な気がするけど式全体にx倍みたいなのの自由度があるから
		結局 (d+1)(k+1) + k - 1 項あれば十分

	使い方:

*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<1000000007>;


vector<mint> extended(int n, const vector< vector<mint> >& coeffs, const vector<mint>& terms) {

	vector<mint> ret(max<int>(n + 1, terms.size()));
	copy(terms.begin(), terms.end(), ret.begin());
	const int order = coeffs.size() - 1;
	const int deg = coeffs[0].size() - 1;
	assert((int) terms.size() >= order);
	for (int m = terms.size(); m <= n; ++m) {
		mint s = 0;
		for (int i = 1; i <= order; ++i) {
			int k = m - i;
			mint t = ret[k];
			for (int d = 0; d <= deg; ++d) {
				s += t * coeffs[i][d];
				t *= k;
			}
		}
		mint denom = 0, mpow = 1;
		for (int d = 0; d <= deg; ++d) {
			denom += mpow * coeffs[0][d];
			mpow *= m;
		}
		ret[m] = -s/denom;
	}
	return ret;
}

vector< vector<mint> > find_recurrence_relation(const vector<mint>& terms, int deg, bool verify=true) {

	const int n = terms.size();
	const int B = (n + 2) / (deg + 2); // number of blocks
	const int C = B * (deg + 1); // number of columns
	const int R = n - (B - 1); // number of rows
	assert(B >= 2); assert(R >= C - 1);

	auto error = [] (int order, int deg) {
		fprintf(stderr, 
			"Error: Could not find a recurrence relation "
			"of order <= %d and degree <= %d.\n\n", 
			order, deg);
		assert(0);
	};

	vector< vector<mint> > mat(R, vector<mint>(C));
	for (int y = 0; y < R; ++y) {
		for (int b = 0; b < B; ++b) {
			mint v = terms[y+b];
			for (int d = 0; d <= deg; ++d) {
				mat[y][b * (deg + 1) + d] = v;
				v *= y+b;
			}
		}
	}

	int rank = 0;
	for (int x = 0; x < C; ++x) {
		int pivot = -1;
		for (int y = rank; y < R; ++y) if (mat[y][x] != 0) {
			pivot = y; break;
		}
		if (pivot < 0) break;
		if (pivot != rank) swap(mat[rank], mat[pivot]);
		mint inv = mat[rank][x].inv();
		for (int x2 = x; x2 < C; ++x2) mat[rank][x2] *= inv;
		for (int y = rank + 1; y < R; ++y) if (mat[y][x]) {
			mint c = -mat[y][x];
			for (int x2 = x; x2 < C; ++x2) {
				mat[y][x2] += c * mat[rank][x2];
			}
		}
		++rank;
	}

	if (rank == C) error(B - 1, deg);

	for (int y = rank - 1; y >= 0; --y) if (mat[y][rank]) {
		assert(mat[y][y] == 1);
		mint c = -mat[y][rank];
		for (int y2 = 0; y2 < y; ++y2) {
			mat[y2][rank] += c * mat[y2][y];
		}
	}

	int order = rank / (deg + 1);
	vector< vector<mint> > ret(order + 1, vector<mint>(deg + 1));
	ret[0][rank % (deg + 1)] = 1;
	for (int y = rank - 1; y >= 0; --y) {
		int k = order - y / (deg + 1), d = y % (deg + 1);
		ret[k][d] = -mat[y][rank];
	}

	if (verify) {
		auto extended_terms = extended(n - 1, ret, 
				vector<mint>(terms.begin(), terms.begin() + order));
		for (int i = 0; i < (int) terms.size(); ++i) {
			if (terms[i] != extended_terms[i]) error(B - 1, deg);
		}
	}

	auto verbose = [&] {
		int last = verify ? n - 1 : order + R - 1;
		fprintf(stderr, 
			"[ Found a recurrence relation ]\n"
			"- order %d\n"
			"- degree %d\n"
			"- verified up to a(%d) (number of non-trivial terms: %d)\n",
			order, deg, last, (last + 1) - ((deg + 2) * (order + 1) - 2)
		);
		fprintf(stderr, "{\n");
		for (int k = 0; k <= order; ++k) {
			fprintf(stderr, "  {");
			for (int d = 0; d <= deg; ++d) {
				if (d) fprintf(stderr, ", ");
				fprintf(stderr, "%d", ret[k][d].v <= mint::mod / 2 ? ret[k][d].v : ret[k][d].v - mint::mod);
			}
			fprintf(stderr, "}%s\n", k == order ? "" : ",");
		}
		fprintf(stderr, "}\n\n");
	};
	verbose();

	return ret;
}

void show_extended_sequence(int n, const vector<mint>& terms, int degree) {
	auto coeffs = find_recurrence_relation(terms, degree);
	auto extended_terms = extended(n, coeffs, terms);
	for (int i = 0; i < (int) extended_terms.size(); ++i) {
		printf("%d %d\n", i, extended_terms[i].v);
	}
	puts("");
}

int main() {
	while(true){
		int N,deg;
		cin>>N>>deg;
		V<mint> a(N);
		rep(i,N) cin>>a[i];
		show_extended_sequence(20,a,deg);
	}
	// dwacon 19 final D
	show_extended_sequence(200, {995554369,437065882,760163028,604374775,563201461,722533179,891029331,243207660,517900337,579351792,820966411,119983157,717013427,453585633,642921619,803562198,779547643,549466610,225987801,511146434,513208445,937519099,288901505,88889178,788877404,953101410,995286120,988949539,550614281,869514524,29874402,86888538,619021685,846782616,869986923,16005998,183318597,739787663,83435752,852566188,271885639,81969631,757364796,31757138,531970110,572889410,964895603,897876970,470735163,782448002,635946194,801119695,654617887,966330726,539188919,472170286,864176479,905095779,405308744,679701093,355096251,165180243,584499701,353630130,697278226,253747285,421059884,567078966,590283273,818044204,350177344,407191480,567551365,886451608,448116350,441779769,483964479,648188485,348176704,148164377,499546790,923857444,925919455,211078081,887599279,657518246,633503691,794144270,983480256,720052462,317082725,616099478,857714097,919165552,193858222,546036558,714532710,873864428,832691114,676902861},
	2);

	// Ones
	show_extended_sequence(10, {1, 1, 1, 1, 1}, 0);

	// Factorials
	show_extended_sequence(10, {1, 1, 2, 6, 24, 120}, 1);

	// Catalan numbers
	show_extended_sequence(10, {1, 1, 2, 5, 14, 42}, 1);

	// Subfactorials
	show_extended_sequence(10, {1, 0, 1, 2, 9, 44, 265}, 1);

	// Motzkin numbers
	show_extended_sequence(10, {1, 1, 2, 4, 9, 21, 51}, 1);

	// Large Schröder numbers
	show_extended_sequence(10, {1, 2, 6, 22, 90, 394, 1806}, 1);

	// Error: (n + 1) a_n \equiv 0 (mod 2)
	show_extended_sequence(10, {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, 1);

	// Hertzsprung's problem: order 4, degree 1
	show_extended_sequence(20, {
		1, 1, 0, 0, 2, 
		14, 90, 646, 5242, 47622, 
		479306, 5296790, 63779034, 831283558, 661506141
	}, 1);

	// yukicoder No.93: order 13, degree 2
	show_extended_sequence(100, {
		1, 1, 2, 2, 8, 
		28, 152, 952, 7208, 62296, 
		605864, 6522952, 76951496, 986411272, 647501133, 
		653303042, 170637030, 248109503, 700583494, 619914523, 
		682935856, 443753916, 423068688, 507501942, 315541972, 
		110825117, 848156395, 798418282, 920964362, 23823302, 
		114894774, 279365223, 992413784, 833179437, 785518302, 
		524368220, 42214454, 140345871, 188150268, 808714798, 
		718376249, 732000901, 955005007, 139255097, 484615744, 
		615066955, 726914809, 856989248, 460819998, 321277105, 
		536397091, 555447300, 597473569, 217709372, 24981477, 
		143561526, 171000806, 137649694, 749333590, 700935246, 
		916763337, 762367836, 296796066, 236278263, 398507715, 
	}, 2);

	// binom(3 * i, i) ** 2 + binom(2 * i, i + 1): order 8, degree 5
	show_extended_sequence(128, {
		1, 10, 229, 7071, 245081, 
		9018219, 344622888, 521041312, 917599501, 328470621, 
		920199271, 726809819, 712906773, 531692419, 688496750, 
		140388924, 514070772, 712606107, 333670208, 549905369, 
		504023887, 34217948, 890190161, 703909490, 6403597, 
		623962638, 685637246, 126160387, 956873888, 9766247, 
		864866393, 563563889, 613532405, 710746029, 182520210, 
		914377932, 648461424, 715143730, 918800735, 503145605, 
		27402642, 282029583, 635728688, 91880493, 896737996, 
		773282006, 625726102, 992524580, 494071629, 82874383, 
		536460288, 218839718, 406647024, 248185000, 360613817,
		546217158, 925224608, 482921337, 928327434, 372559325, 
		614987117, 601351833, 765504201, 230666863, 98348380, 
	}, 5);
	return 0;
}