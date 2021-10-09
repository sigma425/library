
/*
	FirstHitMod(a,m,l,r)
	0%m, a%m, 2a%m, ... のうち、最初に [l,r] に含まれるもの(をa*xとしたときに、x)を返す
	ないなら-1
	m > 0
	a,m,l,r <= 10^18 くらいまでOK
	O(log m)
	verified: ストレステスト
*/

ll getAXmodB(ll a,ll b,ll lw,ll up){
	if(lw == 0) return 0;
	if(a == 0) return -1;
	ll p = (lw+a-1)/a*a;
	if(lw<=p && p<=up) return p;
	ll res = getAXmodB(b%a,a,p-up,p-lw);
	if(res == -1) return -1;
	return p-res;
}
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
	if(b == 0){
		if (a >= 0) return EG{a, 1, 0};
		else return EG{-a, -1, 0};
	}else{
		auto e = ext_gcd(b, a % b);
		return EG{e.g, e.y, e.x - a / b * e.y};
	}
}
ll inv_mod(ll x, ll md) {
	auto z = ext_gcd(x, md).x;
	return (z % md + md) % md;
}

ll FirstHitMod(ll a,ll m,ll l,ll r){
	chmax(l,0); chmin(r,m-1);
	if(l > r) return -1;
	assert(m > 0);
	a = ((a%m)+m)%m;
	
	ll ax = getAXmodB(a,m,l,r);
	if(ax == -1) return -1;
	auto e = ext_gcd(a,m);
	ll g = e.g;
	a/=g,ax/=g,m/=g;
	return __int128((e.x+m)%m)*ax%m;
}


// ll brute(ll a,ll m,ll l,ll r){
// 	for(int i=0;;i++){
// 		int v = (i*a%m+m)%m;
// 		if(i>0 && v==0) return -1;
// 		if(l<=v && v<=r) return i;
// 	}
// 	assert(0);
// }

// int main(){
// 	cin.tie(0);
// 	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
// 	cout << fixed << setprecision(20);

// 	int X; cin >> X;
// 	rep1(m,X){
// 		for(int a=-X;a<=X;a++){
// 			for(int l=-X;l<=X;l++){
// 				for(int r=-X;r<=X;r++){
// 					if(FirstHitMod(a,m,l,r) != brute(a,m,l,r)){
// 						shows(a,m,l,r);
// 						show(FirstHitMod(a,m,l,r));
// 						show(brute(a,m,l,r));
// 						assert(0);
// 					}
// 				}
// 			}
// 		}
// 	}
// }
