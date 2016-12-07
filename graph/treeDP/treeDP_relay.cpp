/*
Data dp[MN];
SubData init;
SubData merge(SubData val,Data v);
Data term(SubData val);
void dfs(int v,int p){
	for(int u:G[v]) if(u!=p) dfs(u,v);
	SubData val=init;
	for(int u:G[v]) if(u!=p) val=merge(val,dp[u]);
	dp[v]=term(val);
}
これをオーダーを変えずに全方向にする
mergeに順序が関係ない とかが必要(実はうまくやれば適切な順なら出来ると思う(ex.頂点id小さい順)けどそんなエグいのは出ないと思う)

merge2が計算量的に間に合わない場合は無理だと思う(例えば,knapsackで何か荷物を追加する はO(K)で出来ても,今のdpの状況 どうしを追加するのにはO(NK)かかる)
その場合は逆元で子を消すタイプのやつをやればよさそう(ls,rsがいらなくて,nottermedから子を一つ引く感じ)


How To Use
Gつくる

Data,SubData,init,merge,merge2を定義する(上の普通の木DPを参照)

Dataは答えだけじゃなくて,再帰的に計算するときに必要な値は保持する(ex.sizeとか)

merge2は,SubData同士の演算
Data=SubData,merge=merge2に出来ることも多そう?(ただの積とか)


calcDPをよぶ
DP[]を使う(dpではない!!!!)

debugのために元となるrootを変えられるようにしてある(初期化とかはいらない) calcDP(N,r)

verified by https://csacademy.com/contest/round-11/#task/connected-tree-subgraphs

*/

//このコードはhttp://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day1&pid=F 直径求めるやつ

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
struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost):to(to),cost(cost){}
};
int inf=1e9;
struct Data{
	int a,b,c;			//v以下のmax, vからのpathのmax,max2
	Data(int a,int b,int c):a(a),b(b),c(c){}
	Data():a(0),b(0),c(-inf){}
	friend ostream& operator<<(ostream& o,const Data& d){return o<<d.a<<","<<d.b<<","<<d.c;}
};
struct SubData{
	int a,b,c;			//子を途中まで見た時の↑
	SubData(int a,int b,int c):a(a),b(b),c(c){}
	SubData():a(0),b(-inf),c(-inf){}
	friend ostream& operator<<(ostream& o,const SubData& d){return o<<d.a<<","<<d.b<<","<<d.c;}
};

const int MN=1000000;

vector<edge> G[MN];
Data dp[MN];			//0-rooted dp[v]=term(merge(dp[u1],dp[u2],...))
SubData dp_nottermed[MN];	//0-rooted merge(dp[u1],...)
Data up[MN];			//up[v]= 0-rootedでのvの親をpとして, v->p方向のdpの値 term(merge(up[p],dp[v's bro1],dp[v's bro1],...))
Data DP[MN];			//DP[v]: ans for v-rooted tree
vector<SubData> ls,rs;		//ls/rs[i] = 0-rootedで見てvのchildrenを左/右からi個mergeしたもの(各vで使い回す)
SubData init(0,-inf,-inf);
SubData merge(SubData val,Data v,edge e){
	int a=max(val.a,v.a);
	vector<int> vc={val.b,val.c,v.b+e.cost};
	sort(all(vc));
	return SubData(a,vc[2],vc[1]);
}
SubData merge2(SubData x,SubData y){
	int a=max(x.a,y.a);
	vector<int> vc={x.b,x.c,y.b,y.c};
	sort(all(vc));
	return SubData(a,vc[3],vc[2]);
}
Data term(SubData v){
	int a=max(v.a,v.b+v.c);
	if(v.b==-inf) v.b=0;
	return Data(a,v.b,v.c);
}

int ans;

void dfs(int v,int p=-1){
	SubData val=init;
	edge vp;
	for(edge& e:G[v]){
		int u=e.to;
		if(u==p){vp=e;continue;}
		dfs(u,v);
		val=merge(val,dp[u],e);			//dp[u]からdp[v]を計算するのにe= v->uを使う
	}
	dp_nottermed[v]=val;
	dp[v]=term(val);
//	cout<<"dp["<<v<<"]="<<dp[v]<<endl;
	if(p>=0){
		chmax(ans,dp[v].a+vp.cost);
	}
}
void ufs(int v,int p=-1){		//0-rootedでupwardな部分を計算
	vector<edge> es;	//edges to children
	edge vp;		//v->p
	for(edge& e:G[v]){
		int u=e.to;
		if(u==p) vp=e;
		else es.pb(e);
	}
	int K=es.size();
	ls.resize(K+1);
	rs.resize(K+1);
	ls[0]=init;
	rs[0]=init;
	rep(i,K){
		ls[i+1]=merge(ls[i],dp[es[i].to],es[i]);
		rs[i+1]=merge(rs[i],dp[es[K-1-i].to],es[K-1-i]);
	}
//	if(p==-1) rep1(i,K) show(ls[i]),show(rs[i]);
	rep(i,K){
		int u=es[i].to;
		SubData val=merge2(ls[i],rs[K-1-i]);
		if(p>=0) val=merge(val,up[v],vp);			//v->p
		up[u]=term(val);
//		cout<<"up["<<u<<"]="<<up[u]<<endl;
		chmax(ans,up[u].a+es[i].cost);
	}
	rep(i,K) ufs(es[i].to,v);
}
void calcDP(int N,int r=0){
	dfs(r);
//	up[r]=e			//Dataの単位元(≠init)が必要で面倒なので回避
	ufs(r);
}
int main(){
	int N;
	cin>>N;
	rep(i,N-1){
		int y,w;
		scanf("%d %d",&y,&w);
		int x=i+1;
		G[x].pb(edge(y,w));G[y].pb(edge(x,w));
	}
	calcDP(N);
	cout<<ans<<endl;
}
