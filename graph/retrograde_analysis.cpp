/*
retrograde analysis 後退解析
グラフ上でターン毎に動かす二人ゲームをやる 動かせなくなったほうが負け
DAGではなくて無限ループし得る時,決まるところから決めていく方針がこれ. 最後まで決まらないと無限に続いて引き分け.
自明な部分をsetdpしたあと、
行き先に相手の負けがある or 行き先が相手の勝ちで埋まった のときにその部分が埋められるのでqueueに入れる.
全体で計算量はO(M)

How to use
add_edgeでグラフ構築した後calcdp(N)するとdp[t][v]に, 人tが頂点vではじめるとどうなるか が入る

verify : yandex/neerc2016/G.cpp

これは無限に続けられると勝ち というやつで少し特殊

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
const int MN=100000;
vector<int> G[MN],iG[MN];

int dp[2][MN];	//turn,v	win=1,lose=-1,?=0
int outdeg[MN];
int done[2][MN];
typedef pair<int,int> P;	//P(turn,v)
queue<P> que;
bool vis[2][MN];

void add_edge(int v,int u){
	G[v].pb(u);
	iG[u].pb(v);
	outdeg[v]++;
}
void setdp(int t,int v,int val){
	dp[t][v]=val;
	for(int u:iG[v]){
		done[t^1][u]++;
		if(val==-1||done[t^1][u]==outdeg[u]){
			if(!vis[t^1][u]){
				que.push(P(t^1,u));
				vis[t^1][u]=1;
			}
		}
	}
}
void calcdp(int N){
	rep(v,N) if(outdeg[v]==0){
		setdp(0,v,-1);
		setdp(1,v,-1);
		vis[0][v]=vis[1][v]=1;
	}
	while(!que.empty()){
		int t,v;
		tie(t,v)=que.front();que.pop();
		bool twin=0;
		for(int u:G[v]){
			if(dp[t^1][u]==-1) twin=1;
		}
		if(twin) setdp(t,v,1);
		else setdp(t,v,-1);
	}
}
int N,M;
int main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		add_edge(a,b);
	}
}
