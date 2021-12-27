/*
	線形代数いろいろ
	verified: yosupo
*/

template<class T>
T det(vector<vector<T>> a){
	assert(a.size() == a[0].size());
	int n = a.size();
	T ans = 1;
	rep(i,n){
		for(int j=i+1;j<n;j++) if(a[j][i]){
			ans = -ans;
			swap(a[j],a[i]);
			break;
		}
		if(!a[i][i]) return T(0);
		ans *= a[i][i];
		for(int j=i+1;j<n;j++){
			T w = -a[j][i]/a[i][i];
			for(int k=i;k<n;k++) a[j][k] += a[i][k]*w;
		}
	}
	return ans;	
}
/*
	左c列をsweep 指定しないとc = w
	行のswapはする
	掃き出しに使った列の集合を返す
*/
template<class T>
vector<int> sweep(vector<vector<T>>& a, int c = -1){
	if(a.empty()) return {};
	if(c == -1) c = a[0].size();
	int h = a.size(), w = a[0].size(), r = 0;
	vector<int> used_col;
	rep(i,c){
		if(r == h) break;
		for(int j=r;j<h;j++) if(a[j][i]){
			swap(a[r],a[j]); break;
		}
		if(!a[r][i]) continue;
		rep(j,h) if(j != r){
			const T t = -a[j][i]/a[r][i];
			for(int k=i;k<w;k++) a[j][k] += a[r][k]*t;
		}
		used_col.pb(i);
		r++;
	}
	return used_col;
}

/*
	ax = b の解のひとつを出力
	解空間は (output) + ker(a)
	解が存在しないなら {}

	式が0個(si(a) == 0) で壊れないように変数の個数 ( = si(a[0]) ) w を与える
*/
template<class T>
vector<T> linearEquation(vector<vector<T>> a, int w, vector<T> b){
	assert(a.size() == b.size());
	int h = a.size();
	rep(i,h) a[i].pb(b[i]);
	vector<int> idx = sweep(a,w);
	for(int i = idx.size();i<h;i++) if(a[i][w]) return {};
	vector<T> x(w);
	rep(i,idx.size()) x[idx[i]] = a[i][w] / a[i][idx[i]];
	return x;
}
/*
	{x | ax = 0} のある基底を出力
	式が0個(si(a) == 0) で壊れないように変数の個数 ( = si(a[0]) ) w を与える
	si(kernel) + rank(a) == w
*/
template<class T>
vector<vector<T>> kernel(vector<vector<T>> a, int w){
	int h = a.size();
	vector<vector<T>> b(w,vector<T>(h+w));
	rep(i,h) rep(j,w) b[j][i] = a[i][j];
	rep(i,w) b[i][h+i] = 1;
	int r = sweep(b,h).size();
	vector<vector<T>> res;
	for(int i=r;i<w;i++) res.eb(b[i].begin()+h,b[i].end());
	return res;
}



/*
	inversion
	なければ {{}}
*/
template<class T>
vector<vector<T>> inv(vector<vector<T>> a){
	assert(a.size() == a[0].size());
	vector<vector<T>> no;
	int n = a.size();
	vector<int> ih(n,-1), jh(n,-1);
	rep(k,n){
		for(int i=k;i<n;i++) if(ih[k] == -1){
			for(int j=k;j<n;j++) if(a[i][j]){
				ih[k] = i, jh[k] = j; break;
			}
		}
		if(ih[k] == -1) return no;
		rep(j,n) swap(a[k][j],a[ih[k]][j]);
		rep(i,n) swap(a[i][k],a[i][jh[k]]);
		if(!a[k][k]) return no;
		a[k][k] = a[k][k].inv();
		rep(i,n) if(i != k) a[k][i] *= a[k][k];
		rep(i,n) if(i != k){
			rep(j,n) if(j != k){
				a[i][j] -= a[i][k]*a[k][j];
			}
		}
		rep(i,n) if(i != k) a[i][k] *= -a[k][k];
	}
	per(k,n){
		rep(j,n) swap(a[k][j],a[jh[k]][j]);
		rep(i,n) swap(a[i][k],a[i][ih[k]]);
	}
	return a;
}