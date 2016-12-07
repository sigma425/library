/*
range sum, point add
*/
struct segtree{
	static const int N=1<<;
	int seg[N*2];
	
	segtree(){
		rep(i,N*2) seg[i]=0;
	}
	segtree(vector<int>& vi){
		rep(i,N*2) seg[i]=0;
		rep(i,vi.size()) seg[N+i]=vi[i];
		for(int i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
	}
	void add(int x,int v){
		x+=N;
		while(x){
			seg[x]+=v;
			x/=2;
		}
	}
	int sum(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		return sum(a,b,l,(l+r)/2,k*2)+sum(a,b,(l+r)/2,r,k*2+1);
	}
};
