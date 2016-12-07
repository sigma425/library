//1-indexed
struct segtree{
	static const int DEPTH=;
	static const int p2=1<<DEPTH;
	int seg[p2*2];
	void init(){
		rep(i,p2*2) seg[i]=0;
	}
	void add(int pos,int val){
		pos+=p2;
		while(pos>0){
			seg[pos]+=val;
			pos/=2;
		}
	}
	int sum(int a,int b,int l,int r,int k){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		return sum(a,b,l,(l+r)/2,k*2)+sum(a,b,(l+r)/2,r,k*2+1);
	}
	int sum(int a,int b){
		return sum(a,b,0,p2,1);
	}
};