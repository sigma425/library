/*
FFT
FFTした後の配列に入っている値は、本来入るべき値との相対誤差が2^-53 * log2(配列長)ぐらいらしい
配列長N,値Xとすると, NXX >= 2^53 くらいになると絶対誤差が1くらいになりまずい
なので, X=10^9 -> 死
そこで, 値を3桁の1024進法との数みなして分割して筆算をする.筆算の各かけざんがFFTで,あとは普通に筆算のように足し算する.
multiply_fft3 -> 3分割 1024進法		N*1024*1024 >= 2^53   <=>   N>=2^30 なので絶対大丈夫
multiply_fft2 -> 2分割 2^15進法		N*(2^15)^2 >= 2^53   <=>   N>=2^23 なのでまあ大丈夫?

フィボナッチで試したら なんか2にしてもそんな速くならなかったんだがなんでだろう ← 元々の計算量がが小さいのでボトルネックじゃなかっただけでは
*/


int bsr(int x) { return 31 - __builtin_clz(x); }
using D = double;
const D pi = acos(-1);
using Pc = complex<D>;

void fft(bool type, vector<Pc> &c){	//multiply : false -> mult -> true
	static vector<Pc> buf[30];
	int N = c.size();
	int s = bsr(N);
	assert(1<<s == N);
	if(buf[s].empty()){
		buf[s]=vector<Pc>(N);
		rep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);
	}
	vector<Pc> a(N),b(N);
	copy(begin(c),end(c),begin(a));
	rep1(i,s){
		int W = 1<<(s-i);
		for(int y=0;y<N/2;y+=W){
			Pc now = buf[s][y];
			if(type) now = conj(now);
			rep(x,W){
				auto l =       a[y<<1 | x];
				auto r = now * a[y<<1 | x | W];
				b[y | x]        = l+r;
				b[y | x | N>>1] = l-r;
			}
		}
		swap(a,b);
	}
	copy(begin(a),end(a),begin(c));
}


/*
	double 用
	かけざん
*/
template<class D>
vector<D> multiply_fft(const vector<D>& x,const vector<D>& y){
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a(N),b(N);
	rep(i,x.size()) a[i] = Pc( x[i] , 0 );
	rep(i,y.size()) b[i] = Pc( y[i] , 0 );
	fft(false,a);
	fft(false,b);

	vector<D> z(S);
	vector<Pc> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	fft(true,c);
	rep(i,S){
		c[i] *= 1.0/N;
		z[i] = c[i].real();
	}
	return z;
}


/*
	long long/mint 用
	最後roundしてキャストする
*/

template<class Mint>
vector<Mint> multiply_fft3(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 10;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[3],b[3];
	rep(t,3){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,5){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-2,0); xt<=min(2,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 15;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[2],b[2];
	rep(t,2){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,3){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-1,0); xt<=min(1,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft1(const vector<Mint>& x,const vector<Mint>& y){
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a(N),b(N);
	rep(i,x.size()) a[i] = Pc( x[i].v , 0 );
	rep(i,y.size()) b[i] = Pc( y[i].v , 0 );
	fft(false,a);
	fft(false,b);

	vector<Mint> z(S);
	vector<Pc> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	fft(true,c);
	rep(i,S){
		c[i] *= 1.0/N;
		z[i] = Mint(ll(round(c[i].real())));
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	return multiply_fft2(x,y);
}