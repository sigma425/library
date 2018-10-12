/*
	rand
	Tは整数型ならなんでもいい
	実数ならuniform_real_distirbution
*/
template<class T>
T rnd(T l,T r){	//[l,r)
	using D = uniform_int_distribution<T>;
	static random_device rd;
	static mt19937 gen(rd());
	return D(l,r-1)(gen);
}
template<class T>
T rnd(T n){	//[0,n)
	return rnd(0,n);
}