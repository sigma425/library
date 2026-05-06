#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "template.hpp"
#include "ds/segtree/segbeats.hpp"

struct D{
	static const ll inf = TEN(13);
	ll sz=0,mx=-inf,mx2=-inf,mxn=0,mn=inf,mn2=inf,mnn=0,lz=0,sm=0;
	D(){}
	D(ll v){sz=1,mx=v,mxn=1,mn=v,mnn=1,sm=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz+r.sz;
		{
			z.mx = max(l.mx,r.mx);
			if(z.mx == l.mx) z.mxn += l.mxn;
			if(z.mx == r.mx) z.mxn += r.mxn;
			for(ll v:{l.mx,l.mx2,r.mx,r.mx2}){
				if(z.mx != v) chmax(z.mx2,v);
			}
		}
		{
			z.mn = min(l.mn,r.mn);
			if(z.mn == l.mn) z.mnn += l.mnn;
			if(z.mn == r.mn) z.mnn += r.mnn;
			for(ll v:{l.mn,l.mn2,r.mn,r.mn2}){
				if(z.mn != v) chmin(z.mn2,v);
			}
		}
		z.sm = l.sm+r.sm;
		return z;
	}
	void push(D& x,D& y){
		ll oldmx = max(x.mx,y.mx);
		ll oldmn = min(x.mn,y.mn);
		rep(_,2){
			D& z = (_ == 0 ? x : y);
			if(z.mn == z.mx){			//1
				if(z.mx == oldmx){
					z.sm += (mx-z.mx)*z.sz;
					z.mn = z.mx = mx;
				}else if(z.mn == oldmn){
					z.sm += (mn-z.mn)*z.sz;
					z.mn = z.mx = mn;
				}else{
					z.sm += lz*z.sz;
					z.mn = z.mx = z.mn+lz;
				}
			}else{
				if(z.mx == oldmx){
					z.sm += (mx-z.mx)*z.mxn;
					z.mx = mx;
				}else{
					z.sm += lz*z.mxn;
					z.mx += lz;
				}
				if(z.mn == oldmn){
					z.sm += (mn-z.mn)*z.mnn;
					z.mn = mn;
				}else{
					z.sm += lz*z.mnn;
					z.mn += lz;
				}
				ll others = z.sz - z.mxn - z.mnn;
				if(others){				// 3
					z.sm += lz * others;
					z.mx2 += lz; z.mn2 += lz;
				}else{					// 2
					z.mn2 = z.mx;
					z.mx2 = z.mn;
				}
			}
			z.lz += lz;
		}
		lz = 0;
	}
	bool changemin(ll v){
		if(v >= mx) return true;
		if(v > mx2){	//mx -> v
			ll oldmx = mx;
			sm += mxn * (v-mx);
			mx = v;
			if(oldmx == mn) mn = v;
			if(oldmx == mn2) mn2 = v;
			return true;
		}
		return false;
	}
	bool changemax(ll v){
		if(v <= mn) return true;
		if(v < mn2){	//mn -> v
			ll oldmn = mn;
			sm += mnn * (v-mn);
			mn = v;
			if(oldmn == mx) mx = v;
			if(oldmn == mx2) mx2 = v;
			return true;
		}
		return false;
	}
	bool add(ll v){
		mx += v;
		if(mx2 != -inf) mx2 += v;
		mn += v;
		if(mn2 != inf) mn2 += v;
		sm += v * sz;
		lz += v;
		return true;
	}
	ll getsum(){
		return sm;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<ll> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::changemin,v);
		}
		if(t == 1){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::changemax,v);
		}
		if(t == 2){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::add,v);
		}
		if(t == 3){
			int l,r; cin >> l >> r;
			cout << seg.get(l,r,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << endl;
		}
	}
}
