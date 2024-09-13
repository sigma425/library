/*
	clear が O(1) で可能な vector<bool>

	初期化 や clear() 後は全て false

	- VecBool a(n);
	- a[i] で true/false を得られる
	- set は a[i] = true とはかけなくて、a.set(i,true) とかく

	verify: https://contest.ucup.ac/submission/554285
*/
struct VecBool {
	int tm;
	vector<int> a;
	
	VecBool(int n):tm(1),a(n){}
	void clear(){ tm++; }
	bool operator[](int i) const { return a[i] == tm; }
	void set(int i, bool val){
		a[i] = val ? tm : 0;
	}
};

// 2次元
struct VVecBool {
	int tm;
	vector<vector<int>> a;
	
	VVecBool(int h, int w):tm(1),a(h,vector<int>(w)){}
	void clear(){ tm++; }
	bool get(int i, int j) const { return a[i][j] == tm; }
	void set(int i, int j, bool val){
		a[i][j] = val ? tm : 0;
	}
};