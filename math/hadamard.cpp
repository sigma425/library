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