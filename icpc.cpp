//wo Geometry
Real normalize(Real x){
	while(x>PI) x-=PI*2;
	while(x<-PI) x+=PI*2;
	return x;
}
struct Circle:vector<P>{
	Point c;
	Real r;
	Circle(){}
	Circle(Point c_,Real r_){
		c=c_;
		r=r_;
	}
	Point getPoint(Real ang){
		return c+r*Point(cos(ang),sin(ang));
	}
};
Real doP(Vector a,Vector b){return (conj(a)*b).real();}
Real crP(Vector a,Vector b){return (conj(a)*b).imag();}
Vector proj(Vector p,Vector b){return b*doP(p,b)/norm(b);}
Point perp(Line l,Point a){
	Point p=l.first,q=l.second;
	return p+proj(a-p,q-p);
}
Vector toVec(Line l){return l.second-l.first;}
bool isPara_(Line l1,Line l2){return eq_((Real)0,crP(toVec(l1),toVec(l2)));}
Point refl(Line l,Point p){
    Point h=perp(l,p);
    return h*(Real)2-p;
} 
 Polygon convCut(Polygon poly,Point a,Point b){
    Polygon res;
    Line l=Line(a,b);
    if(poly.size()==0) return res;
    for(int i=0;i+1<poly.size();i++){
        if(sgn(crP(b-a,poly[i]-a))>=0) res.push_back(poly[i]);
        Segment seg=Segment(poly[i],poly[i+1]);
        if(iLS_(l,seg)){
            Point p=iLL(l,seg);
            if(eq(p,poly[i])) continue;
            if(eq(p,poly[i+1])) continue;
            res.push_back(iLL(l,seg));
        }
    }
    if(res.size()==0) return res;
    if(res.size()<=2){
        res.clear();
        return res;
    }
    res.push_back(res[0]);
    return res;
}
Polygon convCut(Polygon p1,Polygon p2){
    Polygon res=p1;
    for(int i=0;i+1<p2.size();i++){
        if(eq(p2[i],p2[i+1])) continue;
        res=convCut(res,p2[i],p2[i+1]);
    }
    return res;
}
Segment iLPoly(Line l,Polygon poly){
	//attention to the case when intersect at one point!!
    Segment seg=NSeg;
    for(int i=0;i+1<poly.size();i++){
        Segment e=Segment(poly[i],poly[i+1]);
        Point p=iLS(l,e);
        if(isnan(p.real())) continue;
        if(eq(p,poly[i+1])) continue;
        if(isnan(seg.first.real())) seg.first=p;
        else seg.second=p;
    }
    return seg;
} 
bool inPoly_(Polygon poly,Point p){//ON is OUT
    bool in=false;
    for(int i=0;i+1<poly.size();i++){
        Point a=poly[i],b=poly[i+1];
        if(onSeg(a,b,p)) return false;
        a-=p,b-=p;
        if(sgn(a.imag()-b.imag())>0) swap(a,b);
        if(sgn(a.imag())<=0&&sgn(b.imag())>0){
            int s=sgn(crP(a,b));
            if(s==-1) in=!in;
        }
    }
    return in;
}
Real dLP(Line l,Point p){
    Point h=perp(l,p);
    return abs(h-p);
}
 Real dPS(Point p,Segment s){
    Point h=perp(s,p);
    if(onSeg(s,h)) return abs(h-p);
    return min(abs(s.first-p),abs(s.second-p));
}
void iCL(Circle &c,Line l){//attention to the case when l passes center!
    Point h=perp(l,c.c);
    Real d=abs(h-c.c);
    if(sgn(d)==0){
        Point p=l.first;
        if(eq(p,c.c)) p=l.second;
        Real ang=arg(p-c.c);
        c.push_back(normalize(ang));
        c.push_back(normalize(ang+PI));
        return;
    }
    if(sgn(d-c.r)>0) return;
    else if(sgn(d-c.r)==0){
        c.push_back(arg(h-c.c));
    }else{
        Real ang=arg(h-c.c);
        Real ang2=acos(d/c.r);
        c.push_back(normalize(ang+ang2));
        c.push_back(normalize(ang-ang2));
    }
}
Point iLL(Line la,Line lb){
	if(isPara_(la,lb)) return NPoint;
	Point a1=la.first,a2=la.second;
	Point b1=lb.first,b2=lb.second;
	Real num=crP(b1-a1,a2-a1);
	Real den=crP(a2-a1,b2-b1);
	return b1+(b2-b1)*(num/den);
}
void iCC(Circle &c, Circle &c2){
	if(eq_(c.c, c2.c)) return; //same center
	Real d = abs(c.c - c2.c);
	Real r = c.r, r2 = c2.r;
	if(lt_(ZERO, d - (r + r2))) return; //not touch
	else if(eq_(ZERO, d - (r + r2))){ //out tan
		Real ang = normalize(arg(c2.c - c.c));
		c.push_back(ang);
		return;
	}else if(lt_(ZERO, d - abs(r - r2))){ //intersect at two points
		Real ang = arg(c2.c - c.c);
		Real ang2 = acos((r * r + d * d - r2 * r2) / (2.0 * r * d));
		c.push_back(normalize(ang - ang2));
		c.push_back(normalize(ang + ang2));
	}else if(eq_(ZERO, d - abs(r - r2))){ //in tan
		if(r > r2){
			c.push_back(normalize(arg(c2.c - c.c)));
		}else{
			c.push_back(normalize(-arg(c2.c - c.c)));
		}
	}else return; //contained
}
bool iLS_(Line l,Segment s){
    if(isPara_(l.second-l.first,s.second-s.first)) return false;
    Point p=iLL(l,s);
    if(onSeg(s.first,s.second,p)) return true;
    return false;
}
 Point iLS(Line l,Segment s){//重なるときは考えなくてよい 
    Point p=iLL(l,s);
    if(isnan(p.real())) return p;
    if(onSeg(s.first,s.second,p)) return p;
    return NPoint;
}
bool iSS_(Segment s1,Segment s2){
    Point p=iLL(s1,s2);
    if(isnan(p.real())) return false;
    if(!onSeg(s1.first,s1.second,p)) return false;
    if(!onSeg(s2.first,s2.second,p)) return false;
    return true;
} 
Point iSS(Segment s1,Segment s2){
    if(iSS_(s1,s2)) return NPoint;
    return iLL(s1,s2);
}
void tCP(Circle &c, Point p){
	Real d = abs(p - c.c);
	if(le_(ZERO, c.r - d)) return; //ignore ON case
	Real r = c.r;
	Real ang = arg(p - c.c);
	Real ang2 = acos(r / d);
	c.push_back(normalize(ang - ang2));
	c.push_back(normalize(ang + ang2));
}
//wo Number Theory
long long extgcd(long long a,long long b,long long &x,long long &y){
	if(a<b){return extgcd(b,a,y,x);}
	if(b!=0){
		long long d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
		return d;
	}else{x=1;y=0;return a;}
}
long long chinese_(long long p,long long q,long long k){
	//x = 0 mod p
	//x = k mod q
	printf("chinese_(%lld %lld %lld)\n",p,q,k);
	long long a,b;
	long long d=extgcd(p,q,a,b);
	/*
	ap+bq=d
	a'p+b'q=k
	a'p=k-b'q
	x=a'p*/
	printf("d=%lld a=%lld b=%lld\n",d,a,b);
	if(k%d!=0) return -1;
	long long coe=k/d;
	a*=coe;
	b*=coe;
	long long res=a*p;
	long long lcm=p/d*q;
	res%=lcm;
	if(res<0) res+=lcm;
	return res;
}
long long chinese(long long p,long long a,long long q,long long b){
	//x = a mod p
	//x = b mod q
	a%=p;
	if(a<0) a+=p;
	b%=q;
	if(b<0) b+=q;
	if(a>=b){
		long long tmp=chinese_(q,p,a-b);
		if(tmp==-1) return -1;
		tmp+=b;
		long long x,y;
		long long d=extgcd(p,q,x,y);
		long long lcm=p/d*q;
		tmp%=lcm;
		return tmp;
	}else{
		return chinese(q,b,p,a);
	}
}

//sigma
template<class Handler>
struct segtree_lazy{
	using val_t = typename Handler::val_t;
	using opr_t = typename Handler::opr_t;
	int N;
	vector<val_t> val;
	vector<opr_t> lazy;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	segtree_lazy(const vector<val_t>& vc){init(vc);}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		lazy.assign(N*2,opr_t::e());
	}
	void init(const vector<val_t>& vc){
		int n = vc.size();
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		rep(i,n) val[i+N] = vc[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
		lazy.assign(N*2,opr_t::e());
	}
	val_t realvalue(int k,int l,int r){
//		return Handler::act(lazy[k],val[k]);
		return Handler::act(lazy[k],val[k],k,l,r);
	}

	val_t query(int a,int b,int l=0,int r=-1,int k=1){	//query_calc
		if(r==-1) r=N;
		if(b<=l||r<=a) return val_t::e();
		if(a<=l&&r<=b) return realvalue(k,l,r);
		propagate(l,r,k);
		val_t ret = query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);
		val[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);
		return ret;

	}
//	val_t query_leftassoc(){}
	void update(int a,int b,const opr_t &x,int l=0,int r=-1,int k=1){	//query_update
		if(r==-1) r=N;
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			Handler::setg2fg(x,lazy[k]);
			return;
		}
		propagate(l,r,k);
		update(a,b,x,l,(l+r)/2,k*2);
		update(a,b,x,(l+r)/2,r,k*2+1);
		val[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);
	}
	void propagate(int l,int r,int k){	//opr_child -> opr_parent * opr_child		parent after child
		Handler::setg2fg(lazy[k],lazy[k*2  ]);
		Handler::setg2fg(lazy[k],lazy[k*2+1]);
		lazy[k] = opr_t::e();
	}
};
struct handler1{
	/*
		range assign 0以上
		range max

		val_t = int,max			val[k]=max
		opr_t(x) : y -> x		lazy[k]=assign

		今回の場合opr_t::eはない(assignに単位元はない)
		このようなときは、適当な値を単位元に設定にしておき、getfg/setg2fg/ act!! で合成しないよう処理しておけば良い
		考えにくいけどval_tも同様.
		最悪option型みたいにbool値をもたせれば良さそう
	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x));
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){		//maxがv っていう状態のところにfを作用させるとmaxは何になりますか?
		if(f.x == -1) return v;
		return val_t(f.x);
	}
};

template<class D>
struct SplayTree{
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;
		int sz;
		D v;
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}		//!!!
		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			NP pp=p->p;
			int pps=p->pos();
			if(p->l==this){
				p->l=r,r->p=p,r=p,p->p=this;
			}else{
				p->r=l,l->p=p,l=p,p->p=this;
			}
			p->update();
			p=pp;
			if(pps==0) return;
			if(pps==-1) pp->l=this;
			else pp->r=this;
		}
		void splay(){			//thisをrootにもってくる
			while(true){
				int ps=pos();
				if(ps==0) break;
				int pps=p->pos();
				if(pps==0){		//zig
					rot();
				}else if(ps==pps){		//zigzig
					p->rot();rot();
				}else{					//zigzag
					rot();rot();
				}
			}
			update();			//merge/split以外から呼ばれるかもしれないので一応つけておく
		}
		NP splay(int k){			//この区間の左からkth(0-indexed)をrootにもってきてそのポインタを返す
			assert(0<=k&&k<sz);
			if(k<l->sz){
				return l->splay(k);
			}else if(k==l->sz){
				splay();
				return this;
			}else{
				return r->splay(k-(l->sz+1));
			}
		}
		NP update(){		//情報更新(子が正しい時に呼ばないとダメ) (最後にupdateしてreturnするのに楽なのでNPを返す)
			sz=1+l->sz+r->sz;
			return this;
		}
		void showtree(){
			cout<<"[";
			if(l->sz) l->showtree();
			cout<<v;
			if(r->sz) r->showtree();
			cout<<"]";
		}
	};
	NP n;
	static NP merge(NP l,NP r){
		if(r==nil) return l;
		r=r->splay(0);
		r->l=l;
		l->p=r;
		return r->update();
	}
	static pair<NP,NP> split(NP x,int k){
		assert(0<=k&&k<=x->sz);
		if(k==x->sz) return {x,nil};
		x=x->splay(k);
		NP l=x->l;
		l->p = nullptr;
		x->l = nil;
		return {l,x->update()};
	}
	static NP build(int sz,D vs[]){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[md]);
		x->l = build(md,vs);
		x->l->p=x;
		x->r=build(sz-(md+1),vs+md+1);
		x->r->p=x;
		return x->update();
	}
	static NP build(const vector<D>& vs){
		return build(vs.size(),vs,0);
	}
	static NP build(int sz,const vector<D>& vs,int off){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[off+md]);
		x->l = build(md,vs,off);
		x->l->p=x;
		x->r=build(sz-(md+1),vs,off+md+1);
		x->r->p=x;
		return x->update();
	}
	SplayTree() : n(nil){}
	SplayTree(NP n) : n(n){}
	SplayTree(int sz,D vs[]){n=build(sz,vs);}
	SplayTree(vector<D> vs){n=build(vs);}
	void insert(int k,D v){
		auto u=split(n,k);
		n=merge(merge(u.fs,new Node(v)),u.sc);
	}
	void erase(int k){
		auto u=split(n,k);
		n=merge(u.fs,split(u.sc,1).sc);
	}
	void merge(SplayTree t){n=merge(n,t.n);}
	int sz(){return n->sz;}
	D get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		D ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
		return ret;
	}
	void assign(int k,D d){
		auto a = split(n,k);
		auto b = split(a.sc,1);
		n = merge(merge(a.fs,new Node(d)),b.sc);
	}
	int lower_bound(D x){		//x以上で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<=p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
	int upper_bound(D x){		//xより大で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
	void showtree(){
		n->showtree();
		cout<<endl;
	}
};

template<>
SplayTree<int>::NP SplayTree<int>::nil = new SplayTree<int>::Node();

struct segtree{
	using D = long long;

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D sum(int a,int b){		//non-commutative & unrecursive
		D res = 0;
		a+=N,b+=N;
		while(a<b){
			if(a&1) res += val[a++];
			if(b&1) res += val[--b];
			a/=2,b/=2;
		}
		return res;
	}
};

struct BIT{
	int N;
	vector<int> bit;
	BIT(int n){		//nは区間幅!!!
		N=n;
		bit.assign(n+1,0);
	}
	BIT(){}
	void init(int n){
		N=n;
		bit.assign(n+1,0);
	}
	int sum(int i){		//i個の和a[0]+..a[i-1]
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	void add(int i,int x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
	/*
	!!!a[i] SHOULD be non-negative!!!
	return min i s.t. sum(i+1)>=s
	a[0]+..a[i] >= s なる最小のiを返す
	s=0 なら-1を返す
	a[i]=1 or 0の時は,s番目(1-INDEXED)が何かを返す(0-indexed) 
	e.g
	a:0 1 1 0 1
	kth(0)=-1,kth(1)=1,kth(2)=2,kth(3)=4,kth(4>=)=5
	*/
	int kth(int s){
		if(s==0) return -1;
		int p=1;
		while(p<=N) p<<=1;
		p>>=1;
		int i=0;
		while(p){
			if(i+p<=N&&s>bit[i+p]) s-=bit[i+p],i|=p;
			p>>=1;
		}
		return i;
	}
}bit;

template<class D>
struct SparseTable{
	vector<vector<D>> d;
	int lg;

	SparseTable(){}
	SparseTable(const vector<D>& v){
		int N = v.size();
		assert(N > 0);

		lg = bsr(N)+1;
		d.resize(lg);
		d[0] = v;
		for(int t=1;t<lg;t++){
			int len = 1<<(t-1);
			d[t].resize(N-len);
			rep(i,N-len){
				d[t][i] = d[t-1][i] + d[t-1][i+len];
			}
		}
	}
	D query(int l, int r) const {
		if(l>=r) return D::e();
		int u = bsr(r-l);
		return d[u][l]+d[u][r-(1<<u)];
	}
};

struct FastSet{	//[0,N)
	using ull = unsigned long long;
	int N,D;
	vector<vector<ull>> seg;
	FastSet(int N):N(N){
		while(N>1){
			N = (N+63)>>6;
			seg.pb(vector<ull>(N));
		}
		D = seg.size();
	}
	void insert(int x){
		rep(d,D){
			ull b = 1ull<<(x&63);
			x >>= 6;
			seg[d][x] |= b;
		}
	}
	void erase(int x){	//なくてもよんでいい
		rep(d,D){
			ull b = 1ull<<(x&63);
			x >>= 6;
			seg[d][x] &= ~b;
			if(seg[d][x]) break;
		}
	}
	int geq(int x){		//x<=res
		rep(d,D){
			int i = x>>6, r = x&63;
			if(i == (int)seg[d].size()) break;
			ull b = seg[d][i]>>r;
			if(b){
				x += bsf(b);
				while(d--){
					x = (x<<6)|bsf(seg[d][x]);
				}
				return x;
			}else{
				x = (x>>6)+1;
			}
		}
		return N;
	}
	int leq(int x){		//res<=x
		rep(d,D){
			if(x == -1) break;
			int i = x>>6, r = x&63;
			ull b = seg[d][i]<<(r^63);
			if(b){
				x -= bsr(b)^63;
				while(d--){
					x = (x<<6)|bsr(seg[d][x]);
				}
				return x;
			}
			x = (x>>6)-1;
		}
		return -1;
	}
	int bsr(ull x){return __builtin_clzll(x)^63;}
	int bsf(ull x){return __builtin_ctzll(x);}
};

const int B = 320;	//MO algo ([l,r),id)
bool cmp(const PP& a,const PP& b){
	if(a.fs.fs/B != b.fs.fs/B) return a.fs.fs/B < b.fs.fs/B;
	return a.fs.sc < b.fs.sc;
}
sort(qs,qs+Q,cmp);
int L=0,R=0;
rep(t,Q){
	int l=qs[t].fs.fs,r=qs[t].fs.sc,id=qs[t].sc;
	for(;l<L;) add(a[--L]);
	for(;r>R;) add(a[R++]);
	for(;l>L;) erase(a[L++]);
	for(;r<R;) erase(a[--R]);
}

struct CHT{
	using D = ll;
	typedef pair<D,D> P;
	vector<P> deq;
	int s,sd,t;
	void init(int N){
		deq.resize(N);
		s=0,sd=0,t=0;
	}
	void add(D a,D b){		//add ax+b     a:(広義)単調減少!!!
		P p(a,b);
		while(s+1<t&&check(deq[t-2],deq[t-1],p)) t--;
		deq[t++]=p;
	}
	D incr_query(D x){		//x:単調増加の時,これを繰り返し呼ぶ(間にaddが挟まるのはOK)
		while(s+1<t&&f(deq[s],x)>=f(deq[s+1],x)) s++;
		return f(deq[s],x);
	}
	D decr_query(D x){		//x:単調減少の時,これを繰り返し呼ぶ(間にaddが挟まるのはOK)
		if(sd>=t) sd=t-1;
		while(sd+1<t&&f(deq[sd],x)>=f(deq[sd+1],x)) sd++;
		while(sd>0&&f(deq[sd],x)<f(deq[sd-1],x)) sd--;
		return f(deq[sd],x);
	}
	D query(D x){
		int lb=s-1,ub=t-1;
		while(ub-lb>1){
			int m=(lb+ub)/2;
			if(isright(deq[m],deq[m+1],x)) lb=m;
			else ub=m;
		}
		return f(deq[ub],x);
	}
	bool isright(P& a,P& b,D x){
		return f(a,x)>=f(b,x);
	}
	bool check(P& a,P& b,P& c){
		return (b.fs-a.fs)*(c.sc-b.sc)>=(b.sc-a.sc)*(c.fs-b.fs);
	}
	D f(P &p,int x){
		return p.fs*x+p.sc;
	}
}cht;

typedef long long ll;
ll INF=LLONG_MAX;
struct CHT2 {  
  CHT2() {
    S.insert({L(INF,0), L(-INF,0)});
    C.insert(cp(L(INF,0),L(-INF,0)));
  }
  void print() {
    cout << "S : "; for (auto it : S) printf("(%lld,%lld)", it.a, it.b); puts("");
    cout << "C : "; for (auto it : C) printf("(%lld,%lld)", it.n, it.d); puts("");
  }
  // |ab| < LLONG_MAX/4 ???
  void add(ll a, ll b) {
    const L p(a,b);
    It pos = S.insert(p).first;
    if (check(*it_m1(pos), p, *it_p1(pos))) {
      S.erase(pos);
      return;
    }
    C.erase(cp(*it_m1(pos), *it_p1(pos)));
    {
      It it = it_m1(pos);
      while(it!=S.begin() && check(*it_m1(it), *it, p)) --it;
      C_erase(it, it_m1(pos));
      S.erase(++it,pos);
      pos = S.find(p);
    }
    {
      It it = it_p1(pos);
      while(it_p1(it)!=S.end() && check(p,*it, *it_p1(it))) ++it;
      C_erase(++pos, it);
      S.erase(pos, it);
      pos = S.find(p);
    }
    C.insert(cp(*it_m1(pos), *pos));
    C.insert(cp(*pos, *it_p1(pos)));
  }
  ll query(ll x) {
    const L &p = (--C.lower_bound(CP(x,1,L(0,0))))->p;
    return p.a*x + p.b;
  } 
private:
  template<class T> T it_p1(T a) { return ++a; }
  template<class T> T it_m1(T a) { return --a; }  
  struct L {
    ll a, b;
    L(ll a, ll b) : a(a),b(b) {}
    bool operator<(const L &rhs) const {
      return a != rhs.a ? a > rhs.a : b < rhs.b;
    }
  };
  struct CP {
    ll n,d;
    L p;
    CP(ll _n, ll _d, const L &p) : n(_n),d(_d),p(p) {
      if (d < 0) { n *= -1; d *= -1; }
    };
    bool operator<(const CP &rhs) const {
      if (n == INF || rhs.n == -INF) return 0;
      if (n == -INF || rhs.n == INF) return 1;      
      return n * rhs.d < rhs.n * d;
    }
  };
  set<L> S;
  set<CP> C;
  typedef set<L>::iterator It;  
  void C_erase(It a, It b) {
    for (It it=a; it!=b; ++it)
      C.erase(cp(*it, *it_p1(it)));
  }
  CP cp(const L &p1, const L &p2) {
    if (p1.a == INF) return CP(-INF,1,p2);
    if (p2.a == -INF) return CP(INF,1,p2);
    return CP(p1.b-p2.b, p2.a-p1.a, p2);
  }
  bool check(const L &p1, const L &p2, const L &p3) {
    if (p1.a==p2.a && p1.b <= p2.b) return 1;
    if (p1.a == INF || p3.a == -INF) return 0;
    return (p2.a-p1.a)*(p3.b-p2.b) >= (p2.b-p1.b)*(p3.a-p2.a);
  }
};

/*
monotone minima
H*W の配列aがあって, a[0] の最小を取る場所 <= a[1] の最小を取る場所 .. a[H-1] の最小を取る場所
となっている時に、これらの場所をすべて求める
O(W log H)

dp[k][x]: k回切って今場所x
rep(k,K){
	rep(x,N+1){
		rep(y,x) chmin(dp[k+1][x],dp[k][y] + cost(y,x));
	}
}
っていうのがある時に、k,xでの最適yをA[k][x] とおいた時に A[k][x] <= A[k][x+1] が成り立つなら、これが適用できる
(kがないと、xを順番に計算せざるを得ないので無理?)

rep(k,K){
	minima(0,N+1,0,N+1); (内側でdp[k-1]を使う)
}
*/
using D = ll;
void minima(int lx,int rx,int ly,int ry){	//[lx,rx) について bestpos[x] を求める 調べる範囲は[ly,ry)でよい
	if(lx >= rx) return;
	int m = (lx+rx)/2;
	D best = 1e18;
	int bestpos = -1;
	for(int y = ly; y<ry; y++){
//		D val = f(x,y)
//		D val = dp[k-1][y] + cost(y,m);
		if(best>val){
			best = val;
			bestpos = y;
		}
	}
	dp[k][m] = best;	
	minima(k,lx,m,ly,bestpos+1);
	minima(k,m+1,rx,bestpos,ry);
}

template<class E>
struct Articulation{
	using P = pair<int,E>;
	using VP = vector<P>;
	vector<vector<E>> G;
	vector<int> arts;
	vector<VP> biedges;
	vector<vector<int>> GraphAB;
	vector<int> ord,low;
	int I;
	stack<P> st;
	Articulation(const vector<vector<E>>& G):G(G){	//calc arts,biedges
		int N = G.size();
		ord.assign(N,0);
		low.assign(N,0);
		I = 0;
		rep(i,N) if(ord[i]==0){
			while(!st.empty()) st.pop();
			dfs(i);
		}
	}

	void ConstructGraphAB(){
		int A = arts.size();		//[0,A)
		int B = biedges.size();		//[A,A+B)
		GraphAB.resize(A+B);
		int N = G.size();
		vector<int> a2id(N,-1);
		rep(i,A) a2id[arts[i]] = i;
		rep(b,B){
			vector<int> vc;
			for(P p:biedges[b]){
				int from = p.fs;
				int to = p.sc.to;
				if(a2id[from]!=-1) vc.pb(a2id[from]);
				if(a2id[to]!=-1) vc.pb(a2id[to]);
			}
			sort(all(vc));
			vc.erase(unique(vc.begin(),vc.end()),vc.end());
			for(int v:vc){
				GraphAB[A+b].pb(v);
				GraphAB[v].pb(A+b);
			}
		}
	}
	void dfs(int v,int p = -1){
		ord[v]=++I;
		low[v]=ord[v];
		int c=0;
		bool isart=0;
		for(auto& e:G[v]) if(e.to!=p){
			int u = e.to;
			if(ord[u]<ord[v]) st.push(P(v,e));
			if(ord[u]) chmin(low[v],ord[u]);	//back edge
			else{
				dfs(u,v);
				c++;
				chmin(low[v],low[u]);
				if(low[u]>=ord[v]){
					isart = 1;
					vector<P> vp;
					while(true){
						P p=st.top();st.pop();
						vp.pb(p);
						if(p.fs==v && p.sc.to==u) break;
					}
					biedges.pb(vp);
				}
			}
		}
		if(p<0) isart=(c>1);
		if(isart) arts.pb(v);
	}	
};
int main(){
	vector<vector<Edge>> G(N);
	rep(i,M) G[a].pb({b});G[b].pb({a});
	Articulation<Edge> art(G);
	art.ConstructGraphAB();
}

/*
biedge connected component
bsにbridge,ccに二重辺連結成分が入る
!!! 多重辺があるときはelse if(u!=p) のとこで u-pに多重辺があるなら戻っても良い
else if( (u!=p&&inS[u]) || (u==p&&mp[P(min(v,p),max(v,p)]>=2) )
mpはmultimapじゃなくてmap<P,int>
*/
vector<int> G[MN];
int ord[MN];
bool inS[MN];
stack<int> roots,S;
vector<vi> cc;
vector<P> bs;
int cnt;
int cmp[MN];
vector<int> cG[MN];
void vis(int v,int p){
	ord[v]=++cnt;
	S.push(v);
	inS[v]=true;
	roots.push(v);
	for(int u:G[v]){
		if(ord[u]==0){
			vis(u,v);
		}else if(u!=p&&inS[u]){
			while(ord[roots.top()]>ord[u]) roots.pop();
		}
	}
	if(v==roots.top()){
		bs.pb(P(p,v));
		vector<int> vc;
		while(true){
			int w=S.top();S.pop();
			inS[w]=false;
			vc.pb(w);
//			cmp[w]=cc.size();
			if(v==w) break;
		}
		roots.pop();
		cc.pb(vc);
	}
}
void bridge(int N){
	rep(i,N) if(ord[i]==0){
		vis(i,-1);
		bs.pop_back();	//P(-1,hoge)
	}
/*	for(P p:bs){
		int x=cmp[p.fs],y=cmp[p.sc];
		cG[x].pb(y),cG[y].pb(x);
	}*/
}

struct edge{int to;};
vector<edge> G[MAX_N];
bool centroid[MAX_N];
int subtree_size[MAX_N];
int ans;
int compute_subtree_size(int v,int p){
	int c=1;
	rep(i,G[v].size()){
		int w=G[v][i].to;
		if(w==p || centroid[w]) continue;
		c+=compute_subtree_size(w,v);
	}
	subtree_size[v]=c;
	return c;
}
P search_centroid(int v,int p,int t){	
	P res=P(MAX_N,-1);
	int s=1,m=0;
	rep(i,G[v].size()){
		int w=G[v][i].to;
		if(w==p || centroid[w]) continue;
		res=min(res,search_centroid(w,v,t));
		m=max(m,subtree_size[w]);
		s+=subtree_size[w];
	}
	m=max(m,t-s);
	res=min(res,P(m,v));
	return res;
}
void solve_subproblem(int v){
	compute_subtree_size(v,-1);
	int s=search_centroid(v,-1,subtree_size[v]).sc;
	centroid[s]=true;
	//solve subproblem
	centroid[s]=false;
}

//get cycle
vector<int> G[MN];
bool dfsc(int v, int p, vector<int>& vis, vector<int>& cyc, bool& done){
	if(vis[v]==1){
		cyc.pb(v);
		return 1;
	}
	if(vis[v]==2) return 0;

	vis[v] = 1;
	for(int u:G[v]) if(u!=p){
		if(dfsc(u,v,vis,cyc,done)){
			if(v==cyc[0]) done=1;
			if(!done) cyc.pb(v);
			return 1;
		}
	}
	vis[v] = 2;
	return 0;
}
vector<int> getcycle(int N){
	vector<int> vis(N,0);	//0:yet 1:now 2:done
	bool done = 0;
	vector<int> cyc;
	rep(i,N) if(vis[i]==0){
		if(dfsc(i,-1,vis,cyc,done)){
			reverse(all(cyc));
			return cyc;
		}
	}
	return {};
}

struct Bipartite_matching{
	int V;
	vector< vector<int> > G;
	vector<int> match;
	vector<bool> used;
	void init(int N){
		V=N;
		G.assign(V,vector<int>());
		match.assign(V,0);
		used.assign(V,false);
	}
	void add_edge(int v,int u){
		G[v].pb(u);
		G[u].pb(v);
	}
	bool dfs(int v){
		used[v]=true;
		rep(i,G[v].size()){
			int u=G[v][i],w=match[u];
			if(w<0 || (!used[w] && dfs(w))){
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int max_matching(){
		int res=0;
		fill(all(match),-1);
		rep(v,V){
			if(match[v]<0){
				fill(all(used),false);
				if(dfs(v)) res++;
			}
		}
		return res;
	}
};

//max flow
struct edge {int to,cap,rev;};
const int MAX_V=,inf=;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void init(int V){
	rep(i,V) G[i].clear();
}
void add_edge(int from, int to, int cap){
	edge e1={to,cap,G[to].size()},e2={from,0,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	while(true){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while( (f=dfs(s,t,inf))>0 ) flow+=f;
	}
}

typedef pair<int,int> P;
struct edge {int to,cap,cost,rev;};
const int MAX_V=,INF=;
int V;			//代入!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from, int to, int cap, int cost){
	edge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int min_cost_flow(int s, int t, int f){
	int res=0;
	fill(h,h+V,0);
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int par[MV],m[MV],I,parent[MV],vertex[MV],semi[MV],U[MV],idom[MV];
vector<int> bucket[MV],G[MV],rG[MV];

void init(int N){rep(i,N) par[i]=i,m[i]=i;}
int find(int v){
	if(par[v]==v) return v;
	int r=find(par[v]);
	if(semi[m[v]]>semi[m[par[v]]]) m[v]=m[par[v]];
	return par[v]=r;
}
int EVAL(int v){					//sdom最小 になる頂点を返す.sdomを返すわけではない!
	find(v);
	return m[v];
}
void LINK(int x,int y){par[y]=x;}

void dfs(int v){			//dfs木
	semi[v]=I;
	vertex[I++]=v;
	for(int u:G[v]) if(semi[u]<0){
		parent[u]=v;
		dfs(u);
	}
}
void makedomtree(int N,int r){
	init(N);
	rep(i,N) semi[i]=-1;
	dfs(r);									//step1
	for(int i=N-1;i>0;i--){
		//step2
		int w=vertex[i];
		for(int v:rG[w]){
			int u=EVAL(v);
			chmin(semi[w],semi[u]);
		}
		bucket[vertex[semi[w]]].pb(w);		//bucketの更新
		//ここからstep3
		for(int v:bucket[parent[w]]) U[v]=EVAL(v);
		bucket[parent[w]].clear();			//step3が終わったらbucketから消す
		LINK(parent[w],w);					//辺の追加
	}
	//step4
	for(int i=1;i<N;i++){
		int w=vertex[i];
		int u=U[w];
		if(semi[w]==semi[u]) idom[w]=semi[w];
		else idom[w]=idom[u];
	}

	for(int i=1;i<N;i++){				//idom[w]の中身をvertex idから名前に変える
		int w=vertex[i];
		idom[w]=vertex[idom[w]];
	}
	idom[r]=-1;
}
void add_edge(int a,int b){
	G[a].pb(b);
	rG[b].pb(a);
}
int main(){
	int N,M,r;
	cin>>N>>M>>r;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		add_edge(a,b);
	}
	makedomtree(N,r);
}

//scc
vector<int> G[MAX_V],rG[MAX_V],vs;
bool used[MAX_V];
int cmp[MAX_V];
void add_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v){
	used[v]=true;
	rep(i,G[v].size()){
		if(!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	rep(i,rG[v].size()){
		if(!used[rG[v][i]]) rdfs(rG[v][i],k);
	}
}
vector<int> cG[MAX_V];
int scc(int N){
	memset(used,0,sizeof(used));
	vs.clear();
	rep(v,N) if(!used[v]) dfs(v);
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--){
		if(!used[vs[i]]) rdfs(vs[i],k++);
	}
	//compressed Graphを作るときはON
	rep(i,N) for(int j:G[i]){
		if(cmp[i]!=cmp[j]) cG[cmp[i]].pb(cmp[j]);
	}
	rep(i,K) sort(all(cG[i])),cG[i].erase(unique(all(cG[i])),cG[i].end());
	return k;
}

/*
topo sort
visを0で初期化して,Gを作って、maketopo(頂点数)すると
topo[i]=i番目の頂点 になる
*/
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo,G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}

//dir mst
typedef pair<double,int> P;
int N,M,from[101],nid[101];
double inf=1e5,d[101][101],d2[101][101];
bool vis[101];
vector<int> cycle;
bool visit(int v,int s,int r){
	if(v==r) return 0;
	if(vis[v]) return v==s;
	cycle.pb(v);
	vis[v]=1;
	return visit(from[v],s,r);
}
double dir_mst(int r){	//root = r
	int S=N;
	bool update=1;
	while(update){
		update=0;
		double sco=0;
		rep(i,S){
			if(i==r) continue;
			P mn=P(inf,-1);
			rep(j,S) if(i!=j) mn=min(mn,P(d[j][i],j));
			if(mn.fs==inf) return inf;
			from[i]=mn.sc;
			sco+=mn.fs;
		}
		rep(i,S){
			if(i==r) continue;
			rep(j,S) vis[j]=0;
			cycle.clear();
			if(!visit(i,i,r)) continue;
			update=1;
			int len=cycle.size();
			cycle.pb(cycle[0]);
			int S2=S-len+1,it=0;
			rep(j,S){
				if(!vis[j]) nid[j]=it++;
				else nid[j]=-1;
			}
			r=nid[r];
			rep(j,S) if(nid[j]!=-1){
				rep(k,S) if(nid[k]!=-1){
					d2[nid[j]][nid[k]]=d[j][k];
				}
			}
			rep(j,S) if(nid[j]!=-1){
				double mn=inf;
				rep(k,S) if(nid[k]==-1) mn=min(mn,d[k][j]);
				d2[S2-1][nid[j]]=mn;
			}
			double csum=0;
			rep(j,len) csum+=d[cycle[j+1]][cycle[j]];
			rep(j,S) if(nid[j]!=-1){
				double mn=inf;
				rep(k,len){
					mn=min(mn,d[j][cycle[k]]+csum-d[cycle[k+1]][cycle[k]]);
				}
				d2[nid[j]][S2-1]=mn;
			}
			S=S2;
			rep(j,S) rep(k,S) d[j][k]=d2[j][k];
			break;
		}
		if(!update) return sco;
	}
}

//辺AとBが常に同じサイクルに属する という同値関係
unsigned long long seed = 1145141919810893ULL;
unsigned long long xor_rand(){
  seed = seed ^ (seed<<13);
  seed = seed ^ (seed>>7);
  seed = seed ^ (seed<<17);
  return seed;
}
class ToursDecomposition {
 public:
  struct Edge {
    int u, v;
    Edge() {}
    Edge(int u, int v) : u(u), v(v) {}
  };
  int n;
  vector< vector<int> > to;
  vector<int> depth;
  using ull = unsigned long long;
  vector<ull> hash;
  map< ull, vector<Edge> > group;
  ToursDecomposition() {}
  ToursDecomposition(int n) : n(n), to(n), depth(n, -1), hash(n) {}
  void AddEdge(int u, int v) {
    to[u].push_back(v);
    to[v].push_back(u);
  }
  void Init() {
    rep(i,n) {
      if (depth[i] != -1) continue;
      depth[i] = 0;
      dfs(i, -1);
    }
  }
 private:
  void dfs(int v, int p) {
    for (int u : to[v]) {
      if (depth[u] == -1) {
        depth[u] = depth[v] + 1;
        dfs(u, v);
        hash[v] += hash[u];
        group[hash[u]].push_back(Edge(u, v));
      } else if (depth[u] < depth[v] && u != p) {
        ull r = xor_rand();
        group[r].push_back(Edge(u, v));
        hash[v] += r;
        hash[u] -= r;
      }
    }
  }
};


//tree DP
namespace Normalize{
	template<class E>
	void dfs(vector<vector<E>>& G,vector<int>& ord, int v,int p=-1){
		ord.pb(v);
		int K = G[v].size();
		rep(i,K){
			if(G[v][i].to==p){
				rotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());
				K--;
				break;
			}
		}
		rep(i,K) dfs(G,ord,G[v][i].to,v);
	}
	template<class E>
	vector<int> normalize_and_gettopord(vector<vector<E>>& G, int r=0){
		vector<int> ord;
		dfs(G,ord,r);
		return ord;
	}
}

template<class N>
struct BidirectionalTreeDP{
	vector<N> dp;	//dp[v] <- u1,u2,... 			pを削ってvが根
	vector<N> up;	//up[v] <- v's brothers + pp 	vを削ってpが根
	vector<N> rp;	//dp[r] <- rを根とした時のこたえ
	vector<int> par;
	template<class E>
	BidirectionalTreeDP(vector<vector<E>>& G, int r=0){
		int V = G.size();
		dp.assign(V,N());
		up.assign(V,N());
		rp.assign(V,N());
		par.assign(V,0);
		vector<int> ord = Normalize::normalize_and_gettopord<E>(G,r);
		rep(t,V){
			int v = ord[t];
			if(v==r) par[v]=-1;
			else par[v]=G[v].back().to;
		}
		for(int t=V-1;t>=0;t--){	//dfs
			int v = ord[t];
			dp[v] = N();
			int K = G[v].size() - (v!=r);
			rep(i,K){
				const E& e = G[v][i];
				int u = e.to;
				dp[v] = dp[v] + dp[u].append_edge(v,e);
			}
			dp[v].finalize(v);
		}
		rep(t,V){					//ufs
			int v = ord[t];
			int K = G[v].size() - (v!=r);
			vector<N> ls(K+1),rs(K+1);
			rep(i,K){
				ls[i+1] = ls[i] + dp[G[v][i].to].append_edge(v,G[v][i]);
				rs[K-1-i] = dp[G[v][K-1-i].to].append_edge(v,G[v][K-1-i]) + rs[K-i];
			}
			rep(i,K){
				const E& e = G[v][i];
				int u = e.to;
				up[u] = ls[i] + rs[i+1];
				if(v!=r) up[u] = up[u] + up[v].append_edge(v,G[v].back());
				up[u].finalize(v);
			}
			rp[v] = ls[K];
			if(v!=r) rp[v] = rp[v] + up[v].append_edge(v,G[v].back());
			rp[v].finalize(v);
		}
	}
	N get(int v,int p=-1){	//pを削ってvが根
		if(p==-1) return rp[v];
		if(par[v]==p) return dp[v];
		return up[p];
	}
};
/*
	get(v,p) = vからのmax dist, 部分木v以下の葉の個数, 葉からの距離の総和
	"葉である" の判定のために finalize の引数にGを渡している
*/
struct Node{	//vから最も遠い頂点への距離
	int d;
	ll lnum;
	ll lsum;
	Node(){
		d=0;
		lnum=0;
		lsum=0;
	}
	/*
		根付き木→森
		e=(p -> this)を追加したものを返す
	*/
	template<class E>
	Node append_edge(int p,const E& e) const {
		Node n;
		n.d = d+1;
		n.lnum = lnum;
		n.lsum = lsum + lnum;
		return n;
	}
	Node operator+(const Node& r) const {
		Node n;
		n.d = max(d,r.d);
		n.lnum = lnum + r.lnum;
		n.lsum = lsum + r.lsum;
		return n;
	}
	template<class E>
	void finalize(int v,vector<vector<E>>& G){
		if(G[v].size() == 1) lnum++;
	}
};

struct Edge{int to;};
int main(){
	int N;
	cin>>N;
	vector<vector<Edge>> G(N);
	rep(i,N-1){
		int x,y,d;
		cin>>x>>y>>d;
		G[x].pb({y,d});
		G[y].pb({x,d});
	}

	BidirectionalTreeDP<Node> treedp(G);
	rep(v,N){
		for(const Edge& e:G[v]){
			int u = e.to;
			printf("dia[%d] (par = %d)  = %d\n",v,u,treedp.get(v,u).dia);
		}
	}
	rep(v,N){
		printf("all[%d]=%d\n",v,treedp.get(v).dia);
	}
}

int bsr(int x) { return 31 - __builtin_clz(x); }
using D = double;
const D pi = acos(-1);
using Pc = complex<D>;
void fft(bool type, vector<Pc> &c){	//multiply : false -> mult -> true
	static vector<Pc> buf[30];
	int N = c.size();
	int s = bsr(N);
	assert(1<<s == N);
	if(buf[s].empty()){
		buf[s]=vector<Pc>(N);
		rep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);
	}
	vector<Pc> a(N),b(N);
	copy(begin(c),end(c),begin(a));
	rep1(i,s){
		int W = 1<<(s-i);
		for(int y=0;y<N/2;y+=W){
			Pc now = buf[s][y];
			if(type) now = conj(now);
			rep(x,W){
				auto l =       a[y<<1 | x];
				auto r = now * a[y<<1 | x | W];
				b[y | x]        = l+r;
				b[y | x | N>>1] = l-r;
			}
		}
		swap(a,b);
	}
	copy(begin(a),end(a),begin(c));
}

template<class D>
vector<D> multiply_fft(const vector<D>& x,const vector<D>& y){
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a(N),b(N);
	rep(i,x.size()) a[i] = Pc( x[i] , 0 );
	rep(i,y.size()) b[i] = Pc( y[i] , 0 );
	fft(false,a);
	fft(false,b);

	vector<D> z(S);
	vector<Pc> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	fft(true,c);
	rep(i,S){
		c[i] *= 1.0/N;
		z[i] = c[i].real();
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>& y){	//hissan
	const int B = 15;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[2],b[2];
	rep(t,2){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,3){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-1,0); xt<=min(1,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}

template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(int N=0) : v(vector<D>(N)){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	//double? iszeroをglobalに用意したほうがいいかな
		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		//v[i] := x
		if(i>=size() && !x) return;
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}
	
	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_fft(r);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);
//		return rem_naive(y);
	}
	Poly operator<<(const int &n) const{	// *=x^n
		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	// /=x^n
		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv(n),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	//ignore x^n , x^n+1,...
		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	//ignore x^n ~  ->  return x^(n-1) * f(1/x)
		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}
	Poly inv(int n) const{		// f * f.inv() = x^B + r(x) (B>=n)
		int N = size();
		assert(N>=1);		//f : non0
		assert(n>=N-1);		//f = .. + c_{N-1}x^{N-1}
		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		//need to strip!!
			g *= (Poly(vector<D>{2})-a*g).strip(2*i);
		}
		return g.rev(n+1-N);
	}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};
int main(){
	vector<int> vc={1,0,2,-1,0};
	Poly<int> poly(vc);
	show(poly);
}


//f(S)からg(S)=sigma f(T) for all T>S を求める g(10010) = sigma f(1**1*)
void zeta(int* f,int N){rep(i,N) rep(j,1<<N) if(!(j&1<<i)) f[j]+=f[j|(1<<i)];}
//g(10010) = sigma f(*00*0)
void zeta(){rep(i,N)for(int j=(1<<N)-1;j>=0;j--)if((j>>i)&1)f[j]+=f[j^(1<<i)];}
void mebi(){rep(i,N)for(int j=(1<<N)-1;j>=0;j--)if(!(j&1<<i))g[j]-=g[j^(1<<i)];}
void mebi(){rep(i,N) rep(j,1<<N) if(j&(1<<i)) g[j]-=g[j^(1<<i)];}

int c=(1<<k)-1;	//size k subset
while(c<1<<n){
	int x=c&-c,y=c+x;
	c=(((c&~y)/x)>>1)|y;
}

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<1000000007>;

for(int i=2;i<=MX;i++) inv[i]=mod-mod/i*inv[mod%i]%mod;
ll inv(ll a){
	ll x,y;
	extgcd(a,mod,x,y);
	return x;
}
//↓非再帰 extgcd
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll u[]={a,1,0},v[]={b,0,1};
	while(*v){
		ll t=*u/ *v;
		rep(i,3) swap(u[i]-=t*v[i],v[i]);
	}
	if(u[0]<0) rep(i,3) u[i]=-u[i];
	x=u[1],y=u[2];
	return u[0];
}

ll interpolate(vector<ll> xs,vector<ll> ys,ll x){
	int N=xs.size();
	rep(i,N){
		if(xs[i]==x) return ys[i];
	}
	ll ret=0;
	rep(i,N){
		ll a=ys[i];
		rep(j,N) if(j!=i) a=a*(x-xs[j])%mod*inv(xs[i]-xs[j])%mod;
		ret+=a;
	}
	ret=(ret%mod+mod)%mod;
	return ret;
}


//xor convolution
void transform(vector<D> &a, int l, int n) {
	if (n == 1) return;
	int m = l + n / 2;
	transform(a, l, n / 2);
	transform(a, m, n / 2);
	for (int i = 0; i < n / 2; i++) {
		D x = a[l + i], y = a[m + i];
		a[l + i] = x + y;
		a[m + i] = x - y;
	}
}
void transform(vector<D> &a) {	//size must be power of 2
	transform(a, 0, a.size());
}
vector<D> conv(vector<D> a,vector<D> b){
	assert(a.size()==b.size());
	int N = a.size();
	transform(a);
	transform(b);
	vector<D> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	transform(c);
	rep(i,N) c[i]/=N;
	return c;
}

template<class D>
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}
vector<int> fib({0,1,1,2,3,5,8});
auto c = berlekamp_massey(fib);	// return	2 x^0 +   x^1 -   x^2 -   x^3

/*
string s
A[i]="s[0,i-1] suffix & prefix max matching"
S : aabaabaaa
A : _010123452
はじめての文字の比較 			i -> A[i] (前ループのjなので、今のiからみるとA[i])
文字が一致した場所(終了した箇所)	i -> A[i+1]-1 (まあみればわかる)
片方から片方は簡単に導ける.両方とも根付き木でかなり性質が良い.

border列挙
vector<int> res;
int X = A[N];
while(X>0){
	res.pb(X);
	X = A[X];
}
*/
string s;
int A[MN+1];
void calckmp(){
	A[0]=-1;
	int j=-1;
	rep(i,s.size()){
		while(j>=0&&s[i]!=s[j]) j=A[j];
		j++;
		A[i+1]=j;
	}
}
vector<int> manacher(string s){
	int N = s.size();
	vector<int> R(N);
	int i=0,j=0;
	while(i<s.size()){
		while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j]) ++j;
		R[i]=j;
		int k=1;
		while(i-k>=0&&i+k<s.size()&&k+R[i-k]<j) R[i+k]=R[i-k],++k;
		i+=k,j-=k;
	}
	return R;
}

//the longest length of prefix of S and S[i~]
//S:aaabaaaab
//A:921034210
calcZ(){
	A[0]=s.size();
	int i=1,j=0;
	while(i<s.size()){
		while(i+j<s.size()&&s[j]==s[i+j]) ++j;
		A[i]=j;
		if(j==0){++i;continue;}
		int k=1;
		while(i+k<s.size()&&k+A[k]<j) A[i+k]=A[k],++k;
		i+=k,j-=k;
	}
}
//can calc pfx of s[i~] and T
calc(string s,string t){calcZ(t+"$"+s);}

namespace SuffixArray{
	template<class T>
	void induce(int N,const T s[],bool is[],int sa[],int lbase[],int K){
		int it[K+1];
		copy_n(lbase,K+1,it);
		rep(i,N+1){
			if(sa[i]>=1&&!is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[it[c]++]=sa[i]-1;
			}
		}
		copy_n(lbase,K+1,it);
		for(int i=N;i>0;i--){
			if(sa[i]>=1&&is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[--it[c+1]]=sa[i]-1;
			}
		}
	}
	template<class T>
	void SA(int N,const T s[],int sa[],int K){
		bool is[N+1];		//stype?
		int lcnt[K+1]={},scnt[K+1]={};
		is[N]=1;
		for(int i=N-1;i>=0;i--){
			if(i==N-1||s[i]>s[i+1]) is[i]=0;
			else if(s[i]<s[i+1]) is[i]=1;
			else is[i]=is[i+1];
			if(!is[i]) lcnt[(int)s[i]]++;
			else scnt[(int)s[i]]++;
		}
		vector<int> v;		//LMSs
		int lms[N+1];
		fill_n(lms,N+1,-1);
		int c=0;
		rep1(i,N-1){
			if(!is[i-1]&&is[i]){lms[i]=c++;v.pb(i);}
		}
		int lbase[K+1],sbase[K+1];
		lbase[0]=1,sbase[0]=1+lcnt[0];
		rep1(i,K){
			lbase[i]=sbase[i-1]+scnt[i-1];
			sbase[i]=lbase[i]+lcnt[i];
		}
		if(!v.empty()){
			vector<int> v2=v;
			int it[K+1];			//iterate
			copy_n(sbase,K+1,it);
			fill_n(sa,N+1,-1);
			sa[0]=N;
			rep(i,v.size()){
				int c=s[v[i]];
				sa[it[c]++]=v[i];
			}
			induce(N,s,is,sa,lbase,K);
			int c=0;
			rep1(i,N) if(lms[sa[i]]>=0) v[c++]=sa[i];
			int s2[v.size()],sa2[v.size()+1];
			c=0;
			s2[lms[v[0]]]=0;
			for(int i=1;i<(int)v.size();i++){
				int l=v[i-1],r=v[i];
				while(true){
					if(s[l]!=s[r]){
						c++;
						break;
					}
					l++,r++;
					if(lms[l]>=0||lms[r]>=0){
						if(lms[l]<0||lms[r]<0) c++;
						break;
					}
				}
				s2[lms[v[i]]]=c;
			}
			SA(v.size(),s2,sa2,c);
			rep1(i,v.size()) v[i-1]=v2[sa2[i]];
		}
		int it[K+1];
		copy_n(sbase,K+1,it);
		fill_n(sa,N+1,-1);
		sa[0]=N;
		rep(i,v.size()){
			int c=s[v[i]];
			sa[it[c]++]=v[i];
		}
		induce(N,s,is,sa,lbase,K);
	}
	template<class T>
	void LCP(int N,const T s[],const int sa[],int lcp[]){
		int isa[N+1];
		rep(i,N+1) isa[sa[i]]=i;
		int h=0;
		rep(i,N){
			int j=sa[isa[i]-1];
			if(h>0) h--;
			for(;j+h<N&&i+h<N;h++){
				if(s[j+h]!=s[i+h]) break;
			}
			lcp[isa[i]-1]=h;
		}
	}
}

template<int N_>
struct BigInt{
	using ll = long long;
	constexpr static int B = TEN(6);
	constexpr static int N = (N_+5)/6;
	array<ll,N> v;
	BigInt(){
		fill(all(v),0);
	}
	BigInt(ll x){
		fill(all(v),0);
		for(int i=0;x>0;i++){
			assert(i<N);
			v[i] = x%B;
			x /= B;
		}
	}
	BigInt(array<ll,N> v):v(v){}
	BigInt(string s){
		fill(all(v),0);
		int L = s.size();
		rep(i,L/6){v[i] = stoi(s.substr(L-(i+1)*6,6));}
		if(L%6){v[L/6] = stoi(s.substr(0,L%6));}
	}
	int sz() const {
		for(int i = N-1;i>=0;i--){if(v[i]!=0) return i+1;}
		return 0;
	}
	explicit operator bool() const {
		rep(i,N) if(v[i]!=0) return true;
		return false;
	}
	BigInt& operator+=(const BigInt& r){
		rep(i,N){
			v[i] += r.v[i];
			if(v[i] >= B){
				v[i] -= B;
				v[i+1]++;
			}
		}
		return *this;
	}
	BigInt operator+(const BigInt& r) const {return BigInt(*this)+=r;}
	BigInt operator*(const BigInt& r) const {
		array<ll,N> res;
		fill(all(res),0);
		int X = sz();
		int Y = r.sz();
		assert(X+Y-2 < N);
		rep(i,X){
			rep(j,Y){
				res[i+j] += v[i] * r.v[j];
			}
		}
		rep(i,N){
			res[i+1] += res[i]/B;
			res[i] %= B;
		}
		return BigInt(res);
	}
	BigInt& operator*=(const BigInt& r){ return *this=*this*r;}
	bool operator==(const BigInt& r) const { return v==r.v;}
	bool operator!=(const BigInt& r) const { return v!=r.v;}
	bool operator<(const BigInt& r) const {
		for(int i=N-1;i>=0;i--) if(v[i] != r.v[i]) return v[i] < r.v[i];
		return 0;
	}
	string to_str() const {
		string s;
		bool is = 0;
		for(int i=N-1;i>=0;i--){
			if(!is && v[i]==0) continue;
			else if(!is){
				is = 1;
				s += to_string(v[i]);
			}else{
				string t = to_string(v[i]);
				s += string(6-(int)t.size(),'0') + t;
			}
		}
		if(s=="") s = "0";
		return s;
	}
};
using Int = BigInt<1010>;
/*
	スライド最小値
	[0,L), [1,L+1), .. , [N-L,N) のうちの !!!ARGMIN!!! を返す
	maxにしたければrsuccのwhileの不等式を逆にする
	長さ一定じゃなくても、書き換えれば尺取っぽいやつは全てできる
*/
template<class D>
vector<int> calcmins(vector<D> a,int L){
	int N = a.size();
	vector<int> ret;
	deque<int> deq;
	auto rsucc = [&](int i){
		while(!deq.empty() && a[deq.back()]>a[i]) deq.pop_back();
		deq.push_back(i);
	};
	auto lsucc = [&](int i){
		if(!deq.empty() && deq.front()==i) deq.pop_front();
	};
	rep(i,N){
		rsucc(i);
		if(i>=L-1){
			ret.pb(deq.front());
			lsucc(i-L+1);
		}
	}
	return ret;
}
struct unionfind{
	int par[15];
	void init(int N){rep(i,N) par[i]=i;}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(x>y) swap(x,y);		//roots have the smallest id
		par[y]=x;
	}
};
struct Bell{
	//(1, )1, 2, 5, 15, 52,
	//203, 877, 4140, 21147, 115975,
	//678570, 4213597, 27644437, 190899322, 1382958545	
	vector<unionfind> UFs;
	typedef vector<int> VI;
	int N;
	map<VI,int> VI2id;
	queue<int> que;
	VI UF2VI(unionfind UF){
		VI vi(N);
		rep(i,N) vi[i]=UF.find(i);
		return vi;
	}
	int add(unionfind UF){
		VI vi = UF2VI(UF);
		int id = UFs.size();
		VI2id[vi]=id;
		UFs.pb(UF);
		que.push(id);
		return id;
	}
	int UF2id(unionfind UF){
		VI vi = UF2VI(UF);
		if(VI2id.count(vi)) return VI2id[vi];
		return -1;
	}
	void bfs(){
		while(!que.empty()){
			int id = que.front();que.pop();
			VI roots;
			rep(i,N) if(UFs[id].find(i)==i) roots.pb(i);
			int K=roots.size();
			rep(i,K) rep(j,i){
				unionfind UF = UFs[id];
				UF.unite(roots[i],roots[j]);
				int nid;
				if((nid=UF2id(UF))==-1){
					nid = add(UF);
				}
			}
		}
	}
	int init(int N_){		//enum partitions
		N=N_;
		unionfind UF;
		UF.init(N);
		add(UF);
		bfs();
		return UFs.size();
	}
}bell;
const int B8=4140;

bool e[8][8];
ll dp[B8];
int main(){
	int N,M;
	cin>>N>>M;
	int B = bell.init(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		e[a][b]=e[b][a]=1;
	}
	rep(id,B){
		if(id==B-1) break;
		vector<int> roots;
		rep(i,N) if(bell.UFs[id].find(i)==i) roots.pb(i);
		int K=roots.size();
		int cnt = 0;
		rep(i,N) rep(j,i) if(e[i][j]&&bell.UFs[id].same(i,j)) cnt++;
		rep(i,K) rep(j,i){
			unionfind UF = bell.UFs[id];
			int cand = 0;
			rep(a,N) rep(b,N) if(e[a][b]&&UF.find(a)==roots[i]&&UF.find(b)==roots[j]) cand++;
			if(cand==0) continue;
			UF.unite(roots[i],roots[j]);
			int nid=bell.UF2id(UF);
			ll tmp = dp[id]*cand;
			dp[nid] += tmp;
		}
	}
}

#define BEGIN_STACK_EXTEND(size) void *sem = malloc(size);void* seom;
char* sedm = (char*)alloca((1+(int)(((long long)sem)&127))*16);*sedm = 0;
asm volatile("mov %%esp, %%ebx\nmov %%eax, %%esp":"=b"(seom):"a"
((char*)sem+(size)-1024));
#define END_STACK_EXTEND asm volatile("mov %%eax, %%esp"::"a"(seom));free(sem);
BEGIN_STACK_EXTEND(128*1024*1024);
END_STACK_EXTEND;