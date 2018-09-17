/*
	return sum_{k=0~n-1} [ak/b]

	a>=0,b>0,n>=0
	O(log(max(a,b)))
	計算途中でmax(a,b,n)^2 くらいの大きさにはなるのでオーバーフローに注意

	verified at opencup/7836/F.cpp
*/
template<class D>
D sumFloor(D a,D b,D n){
	assert(b!=0);
	if(a==0 || n==0) return 0;
	D g = gcd(a,b);
	a/=g, b/=g;

	D res = 0;
	while(a!=0 && n!=0){
		if(a>=b){
			res += a/b * n*(n-1)/2;
			a %= b;
			if(a==0) break;
		}
		if(n>=b){
			res += (n/b)*(n/b-1)/2*a*b + (a-1)*(b-1)/2*(n/b) + (n/b)*a*(n%b);
			n %= b;
			if(n==0) break;
		}
		res += (b-1)*(a-1)/2 - (b-n)*(a*(n-1)/b);
		n = a-a*(n-1)/b;
		swap(a,b);
		res = -res;
	}
	res = abs(res);
	return res;
}
