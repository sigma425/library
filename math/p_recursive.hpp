/*
	P-recursive (holonomic) sequence の漸化式を求める
	とりあえず数列のはじめの方 terms を求めて、これが非自明な p-recurrence を持っているかを調べたい時
		find_p_recurrence(terms) を呼べば良い
	これが出力した配列を coef として埋め込んで、a[0], .., a[n] を求めるには
		extended(n, coeffs, terms) を呼べば良い

	n 項目を求めるのは愚直にやっている O(n * order * degree) が、実際は order^2 * sqrt(n) * log とかでできるらしい Nyaan 参照

	P-recursive:
		Berlekamp-Massey とかで扱う漸化式は a_n + 3a_{n-1} - 10a_{n-2} = 0 とかだったけど、P-recursive では、
		(-5n-3)a_n + (3n+4)a_{n-1} + (n^5)a_{n-2} = 0 みたいなのが扱える

		つまり係数にnの多項式を入れられる

		ここで、
		d := degree とは この多項式の次数のmaxのことで、 
		k := order  とは (何項間漸化式か)-1 を表す

		nを固定した一つの式に現れる変数の個数は (d+1)(k+1) なので、式をこれだけ用意すれば一意に定まる
		そのためには はじめの (d+1)(k+1) + k 項 が必要 な気がするけど式全体にx倍みたいなのの自由度があるから
		結局 (d+1)(k+1) + k - 1 項あれば十分

	使い方:
		- とりあえず数列の deg と ord を知りたい場合:
			この実装だとdegは固定なので、
			find_recurrence_relation(vector<mint> terms, int deg) を deg = 0~ 試していく
			計算量 O(n^2 * deg * ord)
			見つけられなかったらassert(0),
			見つかったらコメント付きでいろいろ教えてくれる

			!! なんかdegが無駄にでかいと変な解どころか見つけてくれなくなることがあるっぽいので、ちゃんと0から順に試す !!
		
		- reccurence relation が見つかったら
			n項目まで求めたいなら extended_terms(n,coefs,terms)

		- degree も order もわかってる場合
			coeff埋め込みとかができなくてしかも遅い場合
			V<mint> get_extended_sequence(int n, const vector<mint>& terms, int degree, int order) で呼べば最適

	
	verified at
		dwacon 2019 final E
*/

/*
	A_0, .., A_N を返す。必ず長さN+1
*/
vector<mint> extended(int n, const vector<vector<mint>>& coeffs, const vector<mint>& terms) {

	if(si(terms) >= n+1){
		return vector<mint>(terms.begin(), terms.begin() + n+1);
	}
	vector<mint> a(n+1);
	copy(terms.begin(), terms.end(), a.begin());
	const int order = coeffs.size() - 1;
	const int deg = coeffs[0].size() - 1;
	assert((int) terms.size() >= order);
	for (int m = terms.size(); m <= n; ++m) {
		mint s = 0;
		for (int i = 1; i <= order; ++i) {
			int k = m - i;
			mint t = a[k];
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
		a[m] = -s/denom;
	}
	return a;
}

template <class mint>
vector<vector<mint>> find_p_recurrence(const vector<mint>& terms){
	for(int deg = 0; ; deg++){
		auto A = find_p_recurrence(terms, deg);
		if(!A.empty()) return A;
	}
}

template <class mint>
vector<vector<mint>> find_p_recurrence(const vector<mint>& terms, int deg, bool verify = true){
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

	if (rank == C){
		error(B - 1, deg);
		return {};
	}

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
			if (terms[i] != extended_terms[i]){
				cerr << "Fail at verification: " << endl;
				error(B - 1, deg);
				return {};
			}
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
				fprintf(stderr, "%d", ret[k][d].v);
			}
			fprintf(stderr, "}%s\n", k == order ? "" : ",");
		}
		fprintf(stderr, "}\n\n");
	};
	verbose();

	int non_trivial = n - ((deg + 2) * (order + 1) - 2);

	if(non_trivial <= 0) return {};
	return ret;
}