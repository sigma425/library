// size k
int c=(1<<k)-1;
while(c<1<<n){
	// hoge
	int x=c&-c,y=c+x;
	c=(((c&~y)/x)>>1)|y;
}

//subset of b(descending)
int a=b;
do{
	//
	a=(a-1)&b;
}while(a!=b);