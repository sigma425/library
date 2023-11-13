/*
	約数包除 / 倍数包除
	O(NloglogN)
	[0] には一切触らない
*/

// b[6] = a[1] + a[2] + a[3] + a[6]
template <class T> void div_zeta(vector<T>& a){
	int N = si(a);
	vector<bool> sieve(N,true);
	for(int p=2;p<N;p++) if(sieve[p]){
		for(int k=1;k*p<N;k++){
			sieve[k*p] = false;
			a[k*p] += a[k];
		}
	}
}
// inversion of div_zeta
// a[6] = b[6] - b[3] - b[2] + b[1]
template <class T> void div_mobius(vector<T>& b){
	int N = si(b);
	vector<bool> sieve(N,true);
	for(int p=2;p<N;p++) if(sieve[p]){
		for(int k=(N-1)/p;k>0;k--){
			sieve[k*p] = false;
			b[k*p] -= b[k];
		}
	}
}

// b[6] = a[6] + a[12] + a[18] + ...
template <class T> void mult_zeta(vector<T>& a){
	int N = si(a);
	vector<bool> sieve(N,true);
	for(int p=2;p<N;p++) if(sieve[p]){
		for(int k=(N-1)/p;k>0;k--){
			sieve[k*p] = false;
			a[k] += a[k*p];
		}
	}
}

// inversion of mult_zeta
// a[6] = b[6] - b[6*p] + b[6*p*q] - ...
template <class T> void mult_mobius(vector<T>& b){
	int N = si(b);
	vector<bool> sieve(N,true);
	for(int p=2;p<N;p++) if(sieve[p]){
		for(int k=1;k*p<N;k++){
			sieve[k*p] = false;
			b[k] -= b[k*p];
		}
	}
}
