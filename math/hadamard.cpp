/*
	xor convolution
	rep(i,N) rep(j,N) h[i^j] += f[i]*g[j]
	rep(i,N) rep(j,N) h[i] += f[i^j]*g[j]	<-	これ一緒だけどわかりにくい

	hadamard変換に対応している
	xorなので逆元は自分自身、なので逆変換もただのtransform, ただしdet分のNで割る.

	verified: http://codeforces.com/problemset/problem/662/C
*/

using D = ll;
void transform(vector<D> &a, int l, int n) {
	if (n == 1) return;
	int m = l + n / 2;
	transform(a, l, n / 2);
	transform(a, m, n / 2);
	for (int i = 0; i < n / 2; i++) {
		D x = a[l + i], y = a[m + i];
		a[l + i] = x + y;
		a[m + i] = x - y;
	}
}

void transform(vector<D> &a) {	//size must be power of 2
	transform(a, 0, a.size());
}
vector<D> conv(vector<D> a,vector<D> b){
	assert(a.size()==b.size());
	int N = a.size();
	transform(a);
	transform(b);
	vector<D> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	transform(c);
	rep(i,N) c[i]/=N;
	return c;
}
