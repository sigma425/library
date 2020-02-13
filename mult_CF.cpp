/*
    int128が入ってないやん！用
     - md が小さい時商が long double で求められるか？
    など、不明点が多いですね
    https://codeforces.com/blog/entry/70247
    gym102361 H.cpp
*/
inline ll mul(ll a,ll b,ll md){
	ll s=a*b-ll((long double)a/md*b+0.5)*md;
	return (s<0) ? (s+md) : (s>=md ? s-md : s);
}