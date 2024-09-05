/*
	x       0  1  2  3  4  5  6  7  8  9
	msb(x) -1  0  1  1  2  2  2  2  3  3
	最上位bit
*/
int highbit(int x){
	return 31 - countl_zero<uint>(x);
}
int highbit(uint x){
	return 31 - countl_zero<uint>(x);
}
int highbit(ll x){
	return 63 - countl_zero<ull>(x);
}
int highbit(ull x){
	return 63 - countl_zero<ull>(x);
}

/*
	x       0  1  2  3  4  5  6  7  8  9
	lsb(x) 32  0  1  0  2  0  1  0  3  0
	最下位bit
*/
int lowbit(int x){
	return countr_zero<uint>(x);
}
int lowbit(uint x){
	return countr_zero<uint>(x);
}
int lowbit(ll x){
	return countr_zero<ull>(x);
}
int lowbit(ull x){
	return countr_zero<ull>(x);
}