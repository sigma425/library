/*
    F2 ^ Dの基底持つ / 更新するやつ
    add が O(D)
    merge は add を D回、 O(D^2)

    given a に対し、 min(max){a^v | v \in space} は上の桁からxorするかしないか貪欲に選べばいい

    (normalize)
        部分空間を状態として持ちたいときはBを正規化する必要がある
        上の桁から見て辞書順最小にする
        O(D^2)
    
    subspace の数は {1, 2, 5, 16, 67, 374, 2825, 29212, 417199, 8283458}
    そもそも個数が少ないのでN回dpを更新する代わりに同じsubspaceになるやつはまとめて、とかもありうる
        https://codeforces.com/contest/1299/problem/D

    D <= 6 なら貼る空間を 2^D bit で持った方が楽か? 計算量悪くなるが

    とにかく状態が少なくて計算する回数が多いなら、はじめに全部生成してから演算表(merge,add)を作りましょう
    1299/D.cpp 参照

	正規化について (上三角)
		前提なしでやると掃き出し法なのでワードサイズをO(1)とみなしてもO(D^2)
		ただ、もともと上三角なところに add するのは実は O(D) でできる
		add_and_normalize を追加しました
		https://contest.ucup.ac/submission/2310974
*/

template<int D> struct XorBasis {
	V<ull> B;

	XorBasis() : B(D,0) {}

	// add x, add したら true
	// O(D)
	bool add(ull x){
		for(int i=D-1;i>=0;i--){
			if(B[i] == 0 && x&1ULL<<i){ // add to base
				B[i] = x;
				return true;
			}else if(x&1ULL<<i){
				x ^= B[i];
			}
		}
		// dependent, don't add to base
		return false;
	}

	// add x, add したら true
	// 元々正規化されていれば、追加後も正規化されていることが保証される
	// O(D)
	bool add_and_normalize(ull x)
		per(i,D) chmin(x, x^B[i]);
		per(i,D) if(B[i] == 0 && x&1ULL<<i){ // add to base
			B[i] = x;
			for(int j=i+1;j<D;j++) chmin(B[j], B[j]^B[i]);
			return true;
		}
		// dependent, don't add to base
		return false;
	}

	// x が空間に含まれるか
	// 係数もコードを見ればわかる、が B 自身が変化するのであんま意味ないか？
	// O(D)
	bool contains(ull x){
		for(int i=D-1;i>=0;i--){
			if(x&1ULL<<i){
				if(B[i] == 0) return false;
				x ^= B[i];
			}
		}
		return true;
	}

	// 同じ空間が同じ B になるように正規化
	// O(D^2)
	void normalize(){
		for(int i=D-1;i>=0;i--) if(B[i]){
			for(int j=i-1;j>=0;j--) chmin(B[i],B[i]^B[j]);
		}
	}

	// 空間に含まれる要素の最大値
	// O(D)
	ull get_max(){
		ull res = 0;
		for(int i=D-1;i>=0;i--) chmax(res, res ^ B[i]);
		return res;
	}

	void clear(){
		rep(i,D) B[i] = 0;
	}
};