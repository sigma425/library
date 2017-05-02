/*
	range add,range min
//	verified by http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d(足ゲームII)
	Starry Sky

	leftmostnegativeid()とか使いたいわけではない限りあまりこれ使いたくないなあ
*/
struct starryskytree{
	int N;
	using D = ll;
	D id_ = 1e17;		//initialize	!!このあとaddクエリがきてもidを超えないようにする!!
	D id  = 1e18;		//id
	vector<D> mn,ad;
	starryskytree(){}
	starryskytree(int n){
		N=1;
		while(N<n) N*=2;
		mn.assign(N*2,id_);
		ad.assign(N*2,0);
	}
	starryskytree(vector<D>& vc){
		int n = vc.size();
		N=1;
		while(N<n) N*=2;
		mn.assign(N*2,id_);
		ad.assign(N*2,0);
		rep(i,n) mn[i+N]=vc[i];
		for(int i=N-1;i>0;i--) mn[i]=min(mn[i*2],mn[i*2+1]);
	}
	void add(int a,int b,D v){
		add(a,b,0,N,1,v);
	}
	void add(int a,int b,int l,int r,int k,D v){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,l,(l+r)/2,k*2,v);
		add(a,b,(l+r)/2,r,k*2+1,v);
		mn[k]=min(mn[k*2]+ad[k*2],mn[k*2+1]+ad[k*2+1]);
	}
	D getmin(int a,int b){
		return getmin(a,b,0,N,1);
	}
	D getmin(int a,int b,int l,int r,int k){
		if(b<=l||r<=a) return id;
		if(a<=l&&r<=b) return mn[k]+ad[k];
		return ad[k]+min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));
	}
	void assign(int x,ll v){
		add(x,x+1,v-getmin(x,x+1));
	}
	void changemin(int x,ll v){
		D dif = v - getmin(x,x+1);
		if(dif<0) add(x,x+1,dif);
	}

	bool hasnegative(int k,D acm){return acm+mn[k]+ad[k]<0;}
	int leftmostnegativeid(){
		D acm = 0;
		if(!hasnegative(1,acm)) return N;
		int k = 1;
		while(k<N){
			acm += ad[k];
			if(hasnegative(k*2,acm)) k=k*2;
			else k=k*2+1;
		}
		return k-N;
	}

};