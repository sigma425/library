/*
	convex hull trick
	直線集合 S={y=ax+b}に対し,次の操作ができる
	- Sに直線を加える,ただし,「Sの中で最もaが小さいもの」を加えなきゃいけない(つまり追加クエリのaは単調減少)
	- "与えられたx"に対し,min{a_i*x+b_i | i} を求める

	クエリxが単調増加の場合,incrementalにやれば全体でO(N)
	そうでないなら,普通にSに対しにぶたんすればいい

	追加クエリが単調減少でない場合,Sをsetでもって,どの範囲を削るか頑張る必要がある
	こっちはやることはわかるんだけど書くのが面倒 CHT2.cppを参考



	↑は直線集合 にy軸に平行な直線を引いて交わる部分の最大を求める形.
	↓は点集合に、ある傾きの直線を上からおろしていくイメージ

	点集合S={(a,b)}が与えられる.次の操作ができる.
	- Sに点を加える,ただし,「Sの中で最もaが大きいもの」を加える
	- 与えられた傾きtに対し、その直線をどこまで下げられるか(すなわち、max b-ta)


	この対応は、点と直線の双対((a,b) <-> y=ax-b)を取り、その後符号を反転した形になっている.(つまりy=-ax+bとすると完全にただの双対)


	だからmaxを求める形のときは、a->-a,b->-bとしてこのコードに突っ込めば良くて、
	注意すべきこととしては,追加クエリのaが元のaが小さい順になる


	ていうか、どっちも凸包の上側を求めるときの途中経過がどうなってるか考えるとわかるよね?
	下側をやろうとするとminとmaxで求められるものが変わるのと、あと追加クエリの傾きの大小関係の順番が変わる?(isrightとかもisleftに変わる気がするしちょっとこわい)


*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
struct CHT{
	using D = ll;
	typedef pair<D,D> P;
	vector<P> deq;
	int s,t;
	void init(int N){
		deq.resize(N);
		s=0,t=0;
	}
	void add(D a,D b){		//add ax+b     a:(広義)単調減少!!!
		P p(a,b);
		while(s+1<t&&check(deq[t-2],deq[t-1],p)) t--;
		deq[t++]=p;
	}
	D inql_query(D x){		//x:単調増加の時,これを繰り返し呼ぶ(間にaddが挟まるのはOK)
		while(s+1<t&&f(deq[s],x)>=f(deq[s+1],x)) s++;
		return f(deq[s],x);
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
int main(){
	cht.init(3);
	cht.add(2,3);
	cht.add(-1,4);
	show(cht.query(1));
}
