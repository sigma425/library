template<class T>
T rand_int(T l,T r){	//[l,r)
	using D = uniform_int_distribution<T>;
	static random_device rd;
	static mt19937 gen(rd());
	return D(l,r-1)(gen);
}
template<class T>
ll rand_int(ll n){	//[0,n)
	return rand_int(0,n-1);
}