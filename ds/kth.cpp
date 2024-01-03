ll sum(int a,int b,int l,int r,int k){
	if(r<=a||b<=l) return 0;
	if(a<=l&&r<=b) return seg[k];
	return sum(a,b,l,(l+r)/2,k*2+1,seg)+sum(a,b,(l+r)/2,r,k*2+2,seg);
}
void add(int x,int v){
	while(true){
		seg[x]+=v;
		if(x==0) break;
		x=(x-1)/2;
	}
}
int kth(int l,int r,int id,int k){
	if(l+1==r) return l;
	if(seg[2*id+1]>=k) return kth(l,(l+r)/2,id*2+1,k);
	else return kth((l+r)/2,r,id*2+2,k-seg[2*id+1]);
}
