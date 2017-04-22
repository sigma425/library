int sum(int a,int b){
	int ret=0;
	a+=p2,b+=p2;
	while(a<b){
		if(a&1) ret+=seg[a++];
		if(b&1) ret+=seg[--b];
		a/=2,b/=2;
	}
}