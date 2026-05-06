/*
	range x_i = a
	range x_i = gcd(x_i,a)
	range max
	range sum
*/

#define PROBLEM "https://yukicoder.me/problems/no/880"

#include "template.hpp"
#include "ds/segtree/segbeats.hpp"

const ll inf = TEN(9)+1;
ll my_lcm(ll x,ll y){
	return min(x / __gcd(x,y) * y, inf);
}

struct D{
	int sz=1;
	ll sm=0,mx=-1;
	ll L=0;
	D(ll v=1){sm=mx=L=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz + r.sz;
		z.sm = l.sm + r.sm;
		z.mx = max(l.mx,r.mx);
		z.L = my_lcm(l.L,r.L);
		return z;
	}
	void push(D& x,D& y){
		if(mx * sz == sm){
			x.set(mx);
			y.set(mx);
		}
	}
	bool set(ll x){
		sm = x * sz;
		mx = L = x;
		return true;
	}
	bool gcd(ll x){
		if(x % L == 0) return true;
		if(mx * sz == sm){
			set(__gcd(mx,x));
			return true;
		}
		return false;
	}
	ll getmax(){
		return mx;
	}
	ll getsum(){
		return sm;
	}
};

int main(){
	int N,Q;
	cin >> N >> Q;
	V<ll> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);

	rep(_,Q){
		int t;
		cin >> t;
		if(t == 1){
			int l,r,x;
			cin >> l >> r >> x; l--;
			seg.ch(l,r,&D::set,x);
		}
		if(t == 2){
			int l,r,x;
			cin >> l >> r >> x; l--;
			seg.ch(l,r,&D::gcd,x);
		}
		if(t == 3){
			int l,r;
			cin >> l >> r; l--;
			cout << seg.get(l,r,&D::getmax,[](ll x,ll y){return max(x,y);},-1LL) << endl;
		}
		if(t == 4){
			int l,r;
			cin >> l >> r; l--;
			cout << seg.get(l,r,&D::getsum,[](ll x,ll y){return x+y;},0LL) << endl;
		}
	}
}