/*
range max, point assign
*/
int inf=1e9;
struct segtree{
	static const int N=1<<;
	int seg[N*2];
	segtree(){
		rep(i,N*2) seg[i]=-inf;
	}
	segtree(vector<int>& vi){
		rep(i,N*2) seg[i]=-inf;
		rep(i,vi.size()) seg[N+i]=vi[i];
		for(int i=N-1;i>0;i--) seg[i]=max(seg[i*2],seg[i*2+1]);
	}

	void update(int x,int v){
		x+=N;
		seg[x]=v;
		x/=2;
		while(x){
			seg[x]=max(seg[x*2],seg[x*2+1]);
			x/=2;
		}
	}
	int getmax(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return -inf;
		if(a<=l&&r<=b) return seg[k];
		return max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));
	}
};

/*
range min, point assign
*/
int inf=1e9;
struct segtree{
	static const int N=1<<;
	int seg[N*2];
	segtree(){
		rep(i,N*2) seg[i]=inf;
	}
	segtree(vector<int>& vi){
		rep(i,N*2) seg[i]=inf;
		rep(i,vi.size()) seg[N+i]=vi[i];
		for(int i=N-1;i>0;i--) seg[i]=min(seg[i*2],seg[i*2+1]);
	}

	void update(int x,int v){
		x+=N;
		seg[x]=v;
		x/=2;
		while(x){
			seg[x]=min(seg[x*2],seg[x*2+1]);
			x/=2;
		}
	}
	int getmin(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return inf;
		if(a<=l&&r<=b) return seg[k];
		return min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));
	}
};
