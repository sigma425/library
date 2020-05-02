---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/period_substr.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/period_substr.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	文字列sが与えられる. クエリとして[l,r) が来るので、 s[l,r) の最小周期を求める

	最小周期だけじゃなくて周期の集合を求めることもできる(log個程度の等差数列で表せる)

	構築O(NlogN), クエリO(log^2 N)
*/

const bool submit = 0;
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) if(!submit) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

/*
x       0  1  2  3  4  5  6  7  8  9
bsr(x) -1  0  1  1  2  2  2  2  3  3
最上位bit
*/
int bsr(int x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
int bsf(int x){return __builtin_ctz(x);}
int gcd(int a, int b){
	a = abs(a), b = abs(b);
	if(a==0) return b;
	if(b==0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do{
		b >>= bsf(b);
		if(a>b) swap(a,b);
		b -= a;
	}while(b);
	return a<<shift;
}

struct Period_Substr{

	/*
		Arithmetic Progression
		a, a+d, .., a+d(n-1)

		n may be 0 (empty)
		!!! if n>=2 , then d MUST be POSITIVE !!!
	*/
	struct Arith{
		int a,d,n;
		Arith(int a,int d,int n):a(a),d(d),n(n){}
		int getmax(){
			if(n==0) return -1;
			return a+d*(n-1);
		}
		bool hasx(int x){
			if(n==0) return 0;
			if(n==1) return a == x;
			return a<=x && x<=getmax() && (x-a)%d == 0;
		}
		friend ostream& operator<<(ostream &o,const Arith& x){
			o << "[ ";
			rep(i,x.n) o << x.a+i*x.d << " ";
			o<<"]";
			return o;
		}
	};
	Arith Add(int x, Arith f){	// x + f
		return Arith(f.a+x,f.d,f.n);
	}
	Arith Sub(int x, Arith f){	// x - f
		int a = x - f.getmax();
		return Arith(a,f.d,f.n);
	}

	/*
		Assumption: f.n , g.n >= 3
					f.d == g.d
	*/
	Arith Inter(Arith f, Arith g){
		
		assert(f.d == g.d);

		int d = f.d;

		if((f.a-g.a)%d != 0){
			return Arith(0,0,0);
		}

		int a = max(f.a,g.a);
		int e = min(f.getmax(),g.getmax());
		int n = (e-a)/d + 1;

		if(n <= 0){
			return Arith(0,0,0);
		}

		return Arith(a,d,n);

		//brute
		// map<int,int> cnt;
		// rep(i,f.n) cnt[f.a+i*f.d]++;
		// rep(i,g.n) cnt[g.a+i*g.d]++;

		// int a = 0;
		// int d = 0;
		// int n = 0;
		// for(auto it:cnt) if(it.sc==2){
		// 	if(n==0) a = it.fs;
		// 	if(n==1) d = it.fs - a;
		// 	n++;
		// }
		// return Arith(a,d,n);
	}

	string s;
	int N;
	vector<vector<int>> type;
	vector<vector<vector<int>>> kt2xs;

	Period_Substr(string s):s(s),N(s.size()){
		int K = bsr(N) + 1;
		type.resize(K);
		kt2xs.resize(K);

		/*
			TODO
			construct kt2xs
			with SA-IS + LCP !!
		*/


		/*
			by hash (2^64) <- ha?
		*/
		using ull = unsigned long long;
		const ull base = 1e9+7;
		ull bex = base;
		rep(k,K){
			map<ull,vector<int>> mp;
			ull h = 0;
			int len = 1<<k;
			
			rep(i,N){
				h = h*base + s[i];
				if(i-len >= 0) h -= bex * s[i-len];

				if(i >= len-1){
					mp[h].pb(i-(len-1));
				}
			}
			int T = mp.size();

			type[k].resize(N-len+1);
			kt2xs[k].resize(T);

			int t = 0;
			for(const auto& it:mp){
				for(int v: it.sc){
					type[k][v] = t;
					kt2xs[k][t].pb(v);
				}
				t++;
			}
			bex = bex * bex;
		}

	}

	/*
		min period of s[l,r)
	*/
	int period_min(int l,int r){
		int n = r-l;
		int K = bsr(n);
		int res = n;

		rep(k,K+1){
			Arith f = LargePS(k,l,r-(1<<k));
			int p = f.getmax();
			if(p == n){
				if(f.n <=1) continue;
				p -= f.d;
			}
			chmin(res,n-p);
		}

//		Arith f = BordersLarger(l,r);
		Arith f = PeriodsSmaller(l,r);
		if(f.n != 0){
			chmin(res,f.a);
		}

		return res;
	}

	/*
		all period of s[l,r)
		as a DISJOINT union of arithmetic progression
		INCREASING order
	*/
	vector<Arith> period_all(int l,int r){
		vector<Arith> res;

		int n = r-l;
		int K = bsr(n);

		Arith f = PeriodsSmaller(l,r);
		if(f.n != 0){
			res.pb(f);
		}

		for(int k=K;k>=0;k--){
			Arith f = LargePS(k,l,r-(1<<k));
			if(f.n == 0) continue;

			int p = f.getmax();
			if(p == n){
				if(f.n <=1) continue;
				f.n--;
			}
			f = Sub(n,f);
			res.pb(f);
		}
		res.pb(Arith(n,0,1));

		return res;
	}

	int period_min_brute(int l,int r){
		rep1(t,r-l){
			bool ok = 1;
			rep(j,r-l-t){
				if(s[l+j]!=s[l+j+t]) ok = 0;
			}
			if(ok) return t;
		}
		return -1;
	}

	vector<int> period_all_brute(int l,int r){
		vector<int> res;
		rep1(t,r-l){
			bool ok = 1;
			rep(j,r-l-t){
				if(s[l+j]!=s[l+j+t]) ok = 0;
			}
			if(ok) res.pb(t);
		}
		return res;
	}

	/*
		return the set of length of LARGE prefix-suffix of (X,Y)
		X = [x,x+1<<k) , Y = [y,y+1<<k)
		LARGE means length > X.size()/2
	*/
	Arith LargePS(int k,int x,int y){
		if(k==0){
			if(s[x]==s[y]){
				return Arith(1,0,1);
			}else{
				return Arith(0,0,0);
			}
		}
		int d = 1<<(k-1);
		Arith S1 = Sub(2*d,Occ(x,y,k-1));
		Arith S2 = Add(d  ,Occ(y+d,x,k-1));

		Arith S(0,0,0);

		if(S1.n > S2.n) swap(S1,S2);
		if(S1.n < 3){
			if(S1.n == 0){
			}else if(S1.n == 1){
				int a = S1.a;
				if(S2.hasx(a)){
					S = Arith(a,0,1);
				}else{
				}
			}else if(S1.n == 2){
				int a = S1.a;
				int b = S1.a + S1.d;

				bool A = S2.hasx(a) , B = S2.hasx(b);

				if(A && B){
					S = S1;
				}else if(A){
					S = Arith(a,0,1);
				}else if(B){
					S = Arith(b,0,1);
				}else{
				}
			}
		}else{
			S = Inter(S1,S2);
		}

		if(S.n!=0 && S.a == d){	// elim d
			S.a += S.d, S.n--;
		}
		return S;
	}

	/*
		BordersLarger:
		return the set of length of borders of s[l,r) whose length is greater than K

		PeriodsSmaller:
		return (r-l) - BordersLarger
	*/
	Arith PeriodsSmaller(int l,int r){
		int K = bsr(r-l);
		int M = 1<<K;
		int len = r-l;

		int nl = Succ(K,l,l+1);
		if(nl == -1 || nl+M > r){
			return Arith(0,0,0);
		}
		int dl = nl - l;

		int nr = Pred(K,r-M,r-M-1);
		if(nr == -1 || nr<l){
			return Arith(0,0,0);
		}
		int dr = r - M - nr;

		if(dl != dr) return Arith(0,0,0);


		int d = dl;	//period: d,2d,3d,..,nd (border: len-d, .., len-nd>M)

		int n = (len-M-1)/d;

		return Arith(d,d,n);
	}

	/*
		occurence of [x,x+1<<k) in [y,y+1<<(k+1))
		0-indexed
	*/
	Arith Occ(int x,int y,int k){
		int a = Succ(k,x,y);
		if(a == -1 || a > y+(1<<k)){
			return Arith(0,0,0);
		}
		int b = Succ(k,x,a+1);
		if(b == -1 || b > y+(1<<k)){
			return Arith(a-y,0,1);
		}
		int e = Pred(k,x,y+(1<<k));
		assert(e != -1);

		int d = b-a;
		int n = (e-a)/d + 1;

		return Arith(a-y,d,n);
	}

	/*
		return min j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j>=i
		if no, return -1
	*/
	int Succ(int k,int x,int i){
		int t = type[k][x];
		const auto& vc = kt2xs[k][t];
		int id = lower_bound(all(vc),i) - vc.begin();
		if(id == (int)vc.size()) return -1;
		return vc[id];
	}

	/*
		return max j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j<=i
		if no, return -1
	*/
	int Pred(int k,int x,int i){
		int t = type[k][x];
		const auto& vc = kt2xs[k][t];
		int id = upper_bound(all(vc),i) - vc.begin();
		if(id == 0) return -1;
		return vc[id-1];
	}

};

void validate(string s){
	int N = s.size();
	Period_Substr PS(s);
	for(int l=0;l<N;l++) for(int r=l+1;r<=N;r++){		//min
		int a = PS.period_min(l,r);
		int b = PS.period_min_brute(l,r);
		if(a!=b){
			printf("s[%d,%d) = ",l,r);
			cout<<s.substr(l,r-l)<<endl;
			show(a);
			show(b);
			assert(0);
		}
	}

	for(int l=0;l<N;l++) for(int r=l+1;r<=N;r++){		//all
		auto a_ = PS.period_all(l,r);
		vector<int> a;
		for(auto x:a_){
			rep(i,x.n) a.pb(x.a+i*x.d);
		}
		vector<int> b = PS.period_all_brute(l,r);
		if(a!=b){
			printf("s[%d,%d) = ",l,r);
			cout<<s.substr(l,r-l)<<endl;
			show(a);
			show(b);
			assert(0);
		}
	}
//	show(PS.period_all(0,3));
}

int main(){
	srand(unsigned(time(NULL)));
	rep(t,1000){
		cout<<"t="<<t<<endl;
		int N = rand()%100 + 1;
		string s(N,'.');
		rep(i,N) s[i] = 'a' + rand()%26;
		// string s;
		// cin>>s;
		validate(s);
	}
//	validate(string("aba"));
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/period_substr.cpp"
/*
	文字列sが与えられる. クエリとして[l,r) が来るので、 s[l,r) の最小周期を求める

	最小周期だけじゃなくて周期の集合を求めることもできる(log個程度の等差数列で表せる)

	構築O(NlogN), クエリO(log^2 N)
*/

const bool submit = 0;
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) if(!submit) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

/*
x       0  1  2  3  4  5  6  7  8  9
bsr(x) -1  0  1  1  2  2  2  2  3  3
最上位bit
*/
int bsr(int x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
int bsf(int x){return __builtin_ctz(x);}
int gcd(int a, int b){
	a = abs(a), b = abs(b);
	if(a==0) return b;
	if(b==0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do{
		b >>= bsf(b);
		if(a>b) swap(a,b);
		b -= a;
	}while(b);
	return a<<shift;
}

struct Period_Substr{

	/*
		Arithmetic Progression
		a, a+d, .., a+d(n-1)

		n may be 0 (empty)
		!!! if n>=2 , then d MUST be POSITIVE !!!
	*/
	struct Arith{
		int a,d,n;
		Arith(int a,int d,int n):a(a),d(d),n(n){}
		int getmax(){
			if(n==0) return -1;
			return a+d*(n-1);
		}
		bool hasx(int x){
			if(n==0) return 0;
			if(n==1) return a == x;
			return a<=x && x<=getmax() && (x-a)%d == 0;
		}
		friend ostream& operator<<(ostream &o,const Arith& x){
			o << "[ ";
			rep(i,x.n) o << x.a+i*x.d << " ";
			o<<"]";
			return o;
		}
	};
	Arith Add(int x, Arith f){	// x + f
		return Arith(f.a+x,f.d,f.n);
	}
	Arith Sub(int x, Arith f){	// x - f
		int a = x - f.getmax();
		return Arith(a,f.d,f.n);
	}

	/*
		Assumption: f.n , g.n >= 3
					f.d == g.d
	*/
	Arith Inter(Arith f, Arith g){
		
		assert(f.d == g.d);

		int d = f.d;

		if((f.a-g.a)%d != 0){
			return Arith(0,0,0);
		}

		int a = max(f.a,g.a);
		int e = min(f.getmax(),g.getmax());
		int n = (e-a)/d + 1;

		if(n <= 0){
			return Arith(0,0,0);
		}

		return Arith(a,d,n);

		//brute
		// map<int,int> cnt;
		// rep(i,f.n) cnt[f.a+i*f.d]++;
		// rep(i,g.n) cnt[g.a+i*g.d]++;

		// int a = 0;
		// int d = 0;
		// int n = 0;
		// for(auto it:cnt) if(it.sc==2){
		// 	if(n==0) a = it.fs;
		// 	if(n==1) d = it.fs - a;
		// 	n++;
		// }
		// return Arith(a,d,n);
	}

	string s;
	int N;
	vector<vector<int>> type;
	vector<vector<vector<int>>> kt2xs;

	Period_Substr(string s):s(s),N(s.size()){
		int K = bsr(N) + 1;
		type.resize(K);
		kt2xs.resize(K);

		/*
			TODO
			construct kt2xs
			with SA-IS + LCP !!
		*/


		/*
			by hash (2^64) <- ha?
		*/
		using ull = unsigned long long;
		const ull base = 1e9+7;
		ull bex = base;
		rep(k,K){
			map<ull,vector<int>> mp;
			ull h = 0;
			int len = 1<<k;
			
			rep(i,N){
				h = h*base + s[i];
				if(i-len >= 0) h -= bex * s[i-len];

				if(i >= len-1){
					mp[h].pb(i-(len-1));
				}
			}
			int T = mp.size();

			type[k].resize(N-len+1);
			kt2xs[k].resize(T);

			int t = 0;
			for(const auto& it:mp){
				for(int v: it.sc){
					type[k][v] = t;
					kt2xs[k][t].pb(v);
				}
				t++;
			}
			bex = bex * bex;
		}

	}

	/*
		min period of s[l,r)
	*/
	int period_min(int l,int r){
		int n = r-l;
		int K = bsr(n);
		int res = n;

		rep(k,K+1){
			Arith f = LargePS(k,l,r-(1<<k));
			int p = f.getmax();
			if(p == n){
				if(f.n <=1) continue;
				p -= f.d;
			}
			chmin(res,n-p);
		}

//		Arith f = BordersLarger(l,r);
		Arith f = PeriodsSmaller(l,r);
		if(f.n != 0){
			chmin(res,f.a);
		}

		return res;
	}

	/*
		all period of s[l,r)
		as a DISJOINT union of arithmetic progression
		INCREASING order
	*/
	vector<Arith> period_all(int l,int r){
		vector<Arith> res;

		int n = r-l;
		int K = bsr(n);

		Arith f = PeriodsSmaller(l,r);
		if(f.n != 0){
			res.pb(f);
		}

		for(int k=K;k>=0;k--){
			Arith f = LargePS(k,l,r-(1<<k));
			if(f.n == 0) continue;

			int p = f.getmax();
			if(p == n){
				if(f.n <=1) continue;
				f.n--;
			}
			f = Sub(n,f);
			res.pb(f);
		}
		res.pb(Arith(n,0,1));

		return res;
	}

	int period_min_brute(int l,int r){
		rep1(t,r-l){
			bool ok = 1;
			rep(j,r-l-t){
				if(s[l+j]!=s[l+j+t]) ok = 0;
			}
			if(ok) return t;
		}
		return -1;
	}

	vector<int> period_all_brute(int l,int r){
		vector<int> res;
		rep1(t,r-l){
			bool ok = 1;
			rep(j,r-l-t){
				if(s[l+j]!=s[l+j+t]) ok = 0;
			}
			if(ok) res.pb(t);
		}
		return res;
	}

	/*
		return the set of length of LARGE prefix-suffix of (X,Y)
		X = [x,x+1<<k) , Y = [y,y+1<<k)
		LARGE means length > X.size()/2
	*/
	Arith LargePS(int k,int x,int y){
		if(k==0){
			if(s[x]==s[y]){
				return Arith(1,0,1);
			}else{
				return Arith(0,0,0);
			}
		}
		int d = 1<<(k-1);
		Arith S1 = Sub(2*d,Occ(x,y,k-1));
		Arith S2 = Add(d  ,Occ(y+d,x,k-1));

		Arith S(0,0,0);

		if(S1.n > S2.n) swap(S1,S2);
		if(S1.n < 3){
			if(S1.n == 0){
			}else if(S1.n == 1){
				int a = S1.a;
				if(S2.hasx(a)){
					S = Arith(a,0,1);
				}else{
				}
			}else if(S1.n == 2){
				int a = S1.a;
				int b = S1.a + S1.d;

				bool A = S2.hasx(a) , B = S2.hasx(b);

				if(A && B){
					S = S1;
				}else if(A){
					S = Arith(a,0,1);
				}else if(B){
					S = Arith(b,0,1);
				}else{
				}
			}
		}else{
			S = Inter(S1,S2);
		}

		if(S.n!=0 && S.a == d){	// elim d
			S.a += S.d, S.n--;
		}
		return S;
	}

	/*
		BordersLarger:
		return the set of length of borders of s[l,r) whose length is greater than K

		PeriodsSmaller:
		return (r-l) - BordersLarger
	*/
	Arith PeriodsSmaller(int l,int r){
		int K = bsr(r-l);
		int M = 1<<K;
		int len = r-l;

		int nl = Succ(K,l,l+1);
		if(nl == -1 || nl+M > r){
			return Arith(0,0,0);
		}
		int dl = nl - l;

		int nr = Pred(K,r-M,r-M-1);
		if(nr == -1 || nr<l){
			return Arith(0,0,0);
		}
		int dr = r - M - nr;

		if(dl != dr) return Arith(0,0,0);


		int d = dl;	//period: d,2d,3d,..,nd (border: len-d, .., len-nd>M)

		int n = (len-M-1)/d;

		return Arith(d,d,n);
	}

	/*
		occurence of [x,x+1<<k) in [y,y+1<<(k+1))
		0-indexed
	*/
	Arith Occ(int x,int y,int k){
		int a = Succ(k,x,y);
		if(a == -1 || a > y+(1<<k)){
			return Arith(0,0,0);
		}
		int b = Succ(k,x,a+1);
		if(b == -1 || b > y+(1<<k)){
			return Arith(a-y,0,1);
		}
		int e = Pred(k,x,y+(1<<k));
		assert(e != -1);

		int d = b-a;
		int n = (e-a)/d + 1;

		return Arith(a-y,d,n);
	}

	/*
		return min j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j>=i
		if no, return -1
	*/
	int Succ(int k,int x,int i){
		int t = type[k][x];
		const auto& vc = kt2xs[k][t];
		int id = lower_bound(all(vc),i) - vc.begin();
		if(id == (int)vc.size()) return -1;
		return vc[id];
	}

	/*
		return max j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j<=i
		if no, return -1
	*/
	int Pred(int k,int x,int i){
		int t = type[k][x];
		const auto& vc = kt2xs[k][t];
		int id = upper_bound(all(vc),i) - vc.begin();
		if(id == 0) return -1;
		return vc[id-1];
	}

};

void validate(string s){
	int N = s.size();
	Period_Substr PS(s);
	for(int l=0;l<N;l++) for(int r=l+1;r<=N;r++){		//min
		int a = PS.period_min(l,r);
		int b = PS.period_min_brute(l,r);
		if(a!=b){
			printf("s[%d,%d) = ",l,r);
			cout<<s.substr(l,r-l)<<endl;
			show(a);
			show(b);
			assert(0);
		}
	}

	for(int l=0;l<N;l++) for(int r=l+1;r<=N;r++){		//all
		auto a_ = PS.period_all(l,r);
		vector<int> a;
		for(auto x:a_){
			rep(i,x.n) a.pb(x.a+i*x.d);
		}
		vector<int> b = PS.period_all_brute(l,r);
		if(a!=b){
			printf("s[%d,%d) = ",l,r);
			cout<<s.substr(l,r-l)<<endl;
			show(a);
			show(b);
			assert(0);
		}
	}
//	show(PS.period_all(0,3));
}

int main(){
	srand(unsigned(time(NULL)));
	rep(t,1000){
		cout<<"t="<<t<<endl;
		int N = rand()%100 + 1;
		string s(N,'.');
		rep(i,N) s[i] = 'a' + rand()%26;
		// string s;
		// cin>>s;
		validate(s);
	}
//	validate(string("aba"));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

