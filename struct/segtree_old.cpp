//0-indexed
struct segtree{
	int p2=1,seg[MX];
	void init(int N){
		while(p2<N) p2*=2;
	}
	void add(int pos,int val){
		pos+=p2-1;
		while(true){
			seg[pos]+=val;
			if(pos==0) break;
			pos=(pos-1)/2;
		}
	}
	int sum(int a,int b,int l,int r,int k){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		return sum(a,b,l,(l+r)/2,k*2+1)+sum(a,b,(l+r)/2,r,k*2+2);
	}
};