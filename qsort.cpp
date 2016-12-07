#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
const int MAX_N=8000000;
int l[MAX_N],r[MAX_N];
void my_qsort(int* a,int N){
	if(N<=1) return;
	int M=N/2,L=0,R=0;
	rep(i,N){
		if(i==M) continue;
		if(a[i]<a[M]||(a[i]==a[M]&&rand()%2)) l[L++]=a[i];
		else r[R++]=a[i];
	}
	l[L++]=a[M];
	rep(i,L) a[i]=l[i];
	rep(i,R) a[L+i]=r[i];
	my_qsort(a,L-1);
	my_qsort(a+L,R);
}
int x[MAX_N],Ns[4]={1e6,2e6,4e6,8e6};
int main(){
	srand((unsigned)time(NULL));
	rep(tt,4){
		int N=Ns[tt];
		rep(i,N) x[i]=rand()%1000000000;
	//	rep(i,N) cout<<x[i]<<" ";
	//	puts("");
		clock_t start=clock();
		my_qsort(x,N);
		clock_t end=clock();
		printf("N=%8d    time=%.0f ms\n",N,(end-start)/(double)CLOCKS_PER_SEC*1000);
	//	rep(i,N) cout<<x[i]<<" ";
	//	puts("");
	}	
}
