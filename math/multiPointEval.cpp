/*
    f: N次多項式
    a_1,..,a_Q : 値 のときに、
    f(a_i) をすべて求める O( NlogN + Qlog^2(Q) )

    f % (x-a)(x-b)(x-c)(x-d) % (x-c)(x-d) % (x-c) みたいな感じで再帰するだけ

    と思いきや本質は途中から愚直に代入して計算することだった、
    d次まで減らすとそっからは全体で O(dQ) で、fft/ntt が小さい n で遅いことを考えると
    O(dQ) が TL を許す限り d を増やすのがいい気がする

    ntt で N = 10^5 のときは 1024 が最善でした (2500ms -O3)

    verified at Petrozavodsk(19w)/1/I
*/
using P = pair<int,int>;
map<pair<int,int>,Poly<mint>> qs;
Poly<mint> calcq(int l,int r,V<mint>& a){
	if(r-l==1){
		return qs[P(l,r)] = Poly<mint>(V<mint>{-a[l],1});
	}
	return qs[P(l,r)] = calcq(l,(l+r)/2,a) * calcq((l+r)/2,r,a);
}
void calc(int l,int r,Poly<mint> f, V<mint>& a, V<mint>& res){
	f %= qs[P(l,r)];
	if(r-l<=1024){
		for(int i=l;i<r;i++) res[i] = f.eval(a[i]);
		return;
	}
	calc(l,(l+r)/2,f,a,res);
	calc((l+r)/2,r,f,a,res);
}
V<mint> multiPointEval(Poly<mint>& f,V<mint> a){    //return {f(a_i)}
    int N = a.size();
	V<mint> res(N);
	calcq(0,N,a);
	calc(0,N,f,a,res);
	return res;
}