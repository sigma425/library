/*
	linear_reccurence, Berlekamp-Massey

	入力した数列 a が満たす線形漸化式 c を返す。具体的には c は次の式を満たす
		c_0 * a_j + c_1 * a_{j-1} + .. + c_K * a_{j-K} = 0			(K <= j < N)
		c_0 = 1
		なので、 a[n] = -c_1 * a[n-1] - c_2 * a[n-2] - .. - c_K * a[n-K] となる

	実際 a が K+1 項間漸化式を満たすなら、c_1,..,c_K を求めるのに式が K 個必要なので、2K 項あれば十分

	complexity: O(n^2)

	これで見つけた線形漸化式を使って a の n 項目を求めたかったら x^K をこれで割る、みたいなのが必要
	polyライブラリにある: linearReccurenceAt
*/

template<class Mint>
vector<Mint> find_linear_reccurence(const vector<Mint>& a){
	int N = a.size();
	vector<Mint> b = {1}, c = {1};
	Mint y = 1;
	rep1(n,N){
		int L = c.size(), M = b.size();
		Mint x = 0; rep(i,L) x += c[i] * a[n-L+i];
		b.emplace_back(0);
		M++;
		if(!x) continue;
		Mint coef = x/y;
		if(L < M){
			auto tmp = c;
			c.insert(begin(c), M-L, 0);
			rep(i,M) c[M-1-i] -= coef * b[M-1-i];
			b = tmp;
			y = x;
		}else{
			rep(i,M) c[L-1-i] -= coef * b[M-1-i];
		}
	}
	reverse(all(c));
	return c;
}