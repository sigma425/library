/*
	Walsh-Hadamard 変換
	A[i] = \sum_j p(j & i) * a[j]
		ここで、 p(x) は (-1)^popcount(x) のこと

	順変換では T: 可換群 までしか要求していない

	O(2^n * n)
*/
template<class T>
void hadamard(V<T>& a, bool inv = false){
	int n = si(a);
	assert(__builtin_popcount(n) == 1);
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i<<1){
			rep(k,i){
				T s = a[j+k], t = a[j+k+i];
				a[j+k] = s+t;
				a[j+k+i] = s-t;
			}
		}
	}
	if(inv){
		T in = T(1)/n;
		for(auto& x: a) x *= in;
	}
}

/*
	c[i] = \sum_j ( p(j & 1) == 1 ? a[i] : b[i] )

	上のコードを実行中の a に入っている値は、入力の a を使って、 + a[] + a[] - a[] - a[] 
	みたいに係数が-1,0,1 のいずれかで書けることがわかる
	ということは係数が1のa[]の和、-1のa[]の和、を分けて持てば、最終的に + なものの和と - なものの和がわかる

	T は逆元すら仮定せず可換モノイドでよい
	op() は a[j+k] = と a[j+k+1] = の行の 4箇所、わざわざ引数にするのも微妙なので直接書き換える
	verify: yukicoder 2990 https://yukicoder.me/submissions/1078866
*/
template<class T>
vector<T> hadamard2(const vector<T>& a, const vector<T>& b){
	assert(a.size() == b.size());
	int n = si(a);
	assert(__builtin_popcount(n) == 1);
	vector<pair<T,T>> c(n); rep(i,n) c[i] = {a[i], b[i]};
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i<<1){
			rep(k,i){
				auto s = c[j+k], t = c[j+k+i];
				c[j+k] = {s.fs+t.fs, s.sc+t.sc};
				c[j+k+i] = {s.fs+t.sc, s.sc+t.fs};
			}
		}
	}
	vector<T> res(n); rep(i,n) res[i] = c[i].fs;
	return res;
}