/*
	range add,range min
	verified by http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d(足ゲームII)
	Starry Sky
*/
struct starryskytree{
	static const int N=1<<;
	int mn[N*2],ad[N*2];
	starryskytree(vector<int>& vc){
		rep(i,N*2) mn[i]=inf,ad[i]=0;
		rep(i,vc.size()) mn[i+N]=vc[i];
		for(int i=N-1;i>0;i--) mn[i]=min(mn[i*2],mn[i*2+1]);
	}
	void add(int a,int b,int v,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,v,l,(l+r)/2,k*2);
		add(a,b,v,(l+r)/2,r,k*2+1);
		mn[k]=min(mn[k*2]+ad[k*2],mn[k*2+1]+ad[k*2+1]);
	}
	int getmin(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return inf;
		if(a<=l&&r<=b) return mn[k]+ad[k];
		return ad[k]+min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));
	}
};
