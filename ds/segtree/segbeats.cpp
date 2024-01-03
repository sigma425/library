/*
	！！！！！！！！！！雰囲気で関数を書くな！！！！！！！！！！
	lazyなら関数の合成をすることは絶対必要 ちゃんと "モノイドと作用を分けて" "各演算を考える" ことは必ず必要
	このライブラリだと直接そういう型を持ってるわけじゃないからなんかいい感じにかけてしまうことがあるけど、それは間違ってるからちゃんと閉じた演算をかけ
	特に、複雑な場合はもう型を作ってしまう(segtree_lazy) 方がいいケースが多々ある

	関数適用の閉じた形を作らなきゃいけないのは大前提で、その上でいちいち（呼び出し側が）適用したい関数をその型で書くのが面倒だからこういうふうになってるのであって
	合成を考えずに(lzをなんか適用した結果のモノイドの一部みたいに)扱っていいわけではない

	ちなみに点更新の関数は↑の閉じた形には含めなくて良い、それはlzではなく値を直接いじればいいから。特に ch(i,i+1,&D::hoge) 使っていい

	頭を壊してしまった例: https://atcoder.jp/contests/acl2/submissions/16994422

	verify: https://sigma425.github.io/library/data%20structure/segtree/segbeats.cpp

	ただのlazyで使い方忘れがち → https://sigma425.github.io/library/test_oj/beats/range_affine_range_sum.test.cpp
*/

/*
	simple,lazy,beats どれもこれで書ける

	コンストラクタ:
		segbeats(n)
		segbeats(vec) 型が違ってもキャストできればOK

	change クエリ:
		seg.ch(l,r,&D::set,x)

	get クエリ:
		seg.get(l,r,&D::getsum,[](ll x,ll y){return x+y;},0LL)
		型しっかりかかないと怒られるので注意

	findl クエリ:


	注意:
		point クエリも range と全く同じように書いていい、どうせ外から (i,i+1) でしか呼ばないなら関数が適用されるのもサイズ1のノードだけだから、好き勝手やっていい


	struct D{
		コンストラクタ:
			D() が単位元になる必要がある

		merge(l,r):
			l,rのlazy系はidだと仮定して良い
		
		push(x,y):
			this -> x
			this -> y
			this_lazy.clear()
			lazyをかけたタイミングでvalを正しい値に変える

		ch系:
			bool set(int x) とか
			early return していいなら true
			つまりbeatsじゃなければ全部true
		
		get系:
			取り出したい情報を取り出すだけ

		find系:
			このノード内にある → true
	}

	beats: https://yukicoder.me/submissions/386293
	findl: https://codeforces.com/contest/1037/submission/61831108
*/

template<class N>
struct segbeats{
	V<N> x;
	int s;

	segbeats(int n){
		s = 1;
		while(s<n) s *= 2;
		x.resize(s*2);
		for(int i=s-1;i>0;i--) upd(i);
	}
	template<class T>
	segbeats(const V<T>& a){
		int n = a.size();
		s = 1;
		while(s<n) s *= 2;
		x.resize(s*2);
		rep(i,n) x[s+i] = N(a[i]);
		for(int i=s-1;i>0;i--) upd(i);
	}

	template<class F,class... Args>
	void ch(int a,int b,F f,Args... args){
		ch_(a,b,0,s,1,f,args...);
	}

	template<class F,class G,class H>
	auto get(int a,int b,F f,G g,H h){
		return get_(a,b,0,s,1,f,g,h);
	}

	N getNode(int a,int b){
		return getNode_(a,b,0,s,1);
	}

	template<class F,class... Args>
	pair<int,N> findl(int a,int b,F f,Args&... args){
		return findl_(a,b,0,s,1,f,args...);
	}

	private:

	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i] = N::merge(x[i*2],x[i*2+1]);
	}

	template<class F,class... Args>
	void ch_(int a,int b,int l,int r,int i,F f,Args... args){
		if(b<=l || r<=a){
			return;
		}
		if(a<=l && r<=b && (x[i].*f)(args...)){    //f : put_tag, early_break
			return;
		}
		push(i);
		int m = (l+r)/2;
		ch_(a,b,l,m,i*2  ,f,args...);
		ch_(a,b,m,r,i*2+1,f,args...);
		upd(i);
	}
	template<class F,class G,class H>
	auto get_(int a,int b,int l,int r,int i,F f,G g,H h){
		if(b<=l || r<=a){
			return h;
		}
		if(a<=l && r<=b){
			return (x[i].*f)();
		}
		push(i);
		int m = (l+r)/2;
		return g(get_(a,b,l,m,i*2,f,g,h),get_(a,b,m,r,i*2+1,f,g,h));
	}
	N getNode_(int a,int b,int l,int r,int i){
		if(b<=l || r<=a){
			return N();
		}
		if(a<=l && r<=b){
			return x[i];
		}
		push(i);
		int m = (l+r)/2;
		return N::merge(getNode_(a,b,l,m,i*2),getNode_(a,b,m,r,i*2+1));
	}
	template<class F,class... Args>
	pair<int,N> findl_(int a,int b,int l,int r,int i,F f,Args&... args){
		if(b<=l || r<=a){
			return {b,N()};
		}
		if(a<=l && r<=b){
			if(!(x[i].*f)(args...)) return {b,N()};
			if(r-l == 1) return {l,x[i]};
		}
		push(i);
		int m = (l+r)/2;
		auto res = findl_(a,b,l,m,i*2,f,args...);
		if(res.fs < b) return res;
		return findl_(a,b,m,r,i*2+1,f,args...);
	}
	// template<class F,class... Args>
	// pair<int,N> findr_(int a,int b,int l,int r,int i,F f,Args&... args){
	// 	if(b<=l || r<=a){
	// 		return {a-1,N()};
	// 	}
	// 	if(a<=l && r<=b){
	// 		if(!(x[i].*f)(args...)) return {a-1,N()};
	// 		if(r-l == 1) return {l,x[i]};
	// 	}
	// 	push(i);
	// 	int m = (l+r)/2;
	// 	auto y = findr_(a,b,m,r,i*2+1,f,args...);
	// 	if(y.fs >= a) return y;
	// 	return findr_(a,b,l,m,i*2,f,args...);
	// }

};

/*
    yukicoder 880
    range x_i = a
    range x_i = gcd(x_i,a)
    range max
    range sum

struct D{
	int sz=1;
	ll sm=0,mx=-1;
	ll L=0;
	D(ll v=1){sm=mx=L=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz + r.sz;
		z.sm = l.sm + r.sm;
		z.mx = max(l.mx,r.mx);
		z.L = lcm(l.L,r.L);
		return z;
	}
	void push(D& x,D& y){
		if(mx * sz == sm){
			x.set(mx);
			y.set(mx);
		}
	}
	bool set(ll x){
		sm = x * sz;
		mx = L = x;
		return true;
	}
	bool gcd(ll x){
		if(x % L == 0) return true;	// break_condition
		if(mx * sz == sm){		// put_tag_condition
			set(__gcd(mx,x));
			return true;
		}
		return false;
	}
	ll getmax(){
		return mx;
	}
	ll getsum(){
		return sm;
	}
};


CF 1037 (Manthan 18) H
struct D{
	int x,y,z;	// min sa, min lcp, min sa+lcp
	D(int l=inf):x(inf),y(l),z(inf){}
	static D merge(D l,D r){
		D m;
		m.x = min(l.x,r.x);
		m.y = min(l.y,r.y);
		m.z = min({l.z,r.z,l.y+r.x});
		return m;
	}
	void push(D& x,D& y){
	}
	bool set(int v){
		x = v;
		return true;
	}
	bool find(int& mn, int r){
		if(z < r) return true;
		if(mn+x < r) return true;
		chmin(mn,y);
		return false;
	}
};

*/