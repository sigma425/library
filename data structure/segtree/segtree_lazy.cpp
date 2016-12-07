template<typeneme Handler>
struct segtree_lazy{
	typedef typename Handler::val_t val_t;
	typedef typename Handler::opr_t opr_t;
	Handler hdl;
	int N;
	vector<val_t> val;
	vector<opr_t> lazy;
	segtree_lazy(){

	}
	void update(int a,int b,opr_t x,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			cmpsit(lazy[k],x);
			return;
		}
		prop(lazy[k*2],lazy[k]);
		prop(lazy[k*2+1],lazy[k]);
		update(a,b,x,k*2,l,(l+r)/2,k*2);
		update(a,b,x,k*2+1,(l+r)/2,r,k*2+1);
		
	}
};
struct handler{
	struct val_t{

	};
	struct opr_t{

	};
	static void cmpsit(opr_t &x,const opr_t &y){		//opr_tの関数合成		これpropでよくない???

	}
	static void prop(opr_t &x,const opr_t &y){			//k->子への遅延評価,他の情報(左か右か,長さとか)が必要になることもあるので適宜変える
		
	}
}