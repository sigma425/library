/*
Nは2べき
tは+-2pi/n
aの中でin spaceにFFTを行う
*/
typedef double D;
typedef complex<D> P;
D pi=acos(-1);
void FFT(vector<P>& a,int N,double t){
	for(int m=N;m>=2;m/=2){
		int mh=m/2;
		rep(i,mh){
			P w=polar(1.0,t*i);
			for(int j=i;j<N;j+=m){
				int k=j+mh;
				P x=a[j]-a[k];
				a[j]+=a[k];
				a[k]=w*x;
			}
		}
		t*=2;
	}
	int i=0;
	rep1(j,N-2){
		for(int k=N/2;k>(i^=k);k/=2);
		if(j<i) swap(a[i],a[j]);
	}
}
vector<P> conv(vector<P> a,vector<P> b){
	int n=a.size()+b.size();
	int N=1;
	while(N<n) N*=2;
	a.resize(N);
	b.resize(N);
	FFT(a,N,2*pi/N);
	FFT(b,N,2*pi/N);
	rep(i,N) a[i]*=b[i];
	FFT(a,N,-2*pi/N);
	rep(i,N) a[i]/=N;
	return a;
}