ll rand_int(ll l,ll r){	//[l,r]
	using D = uniform_int_distribution<ll>;
	static random_device rd;
	static mt19937 gen(rd());
	return D(l,r)(gen);
}
ll rand_int(ll n){	//[0,n)
	return rand_int(0,n-1);
}