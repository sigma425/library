/*

関節点
ord[v]: dfs森でのid
low[v]: lowlink, dfs木で子にいく + 一回だけ後退辺で上に上がれる ときにたどりつけるord のmin
vが関節点⇔
 vがdfs木のroot かつ 次数が2以上 or
 vがdfs木のrootでない かつ ある子uが存在し, ord[v]<=low[u]
ord[v]=low[u]でも関節点(自分にサイクルが戻ってきたとしても上にはいけないのでまだ関節点なまま) なことに注意

二重(頂点)連結成分
橋に対する二重辺連結成分のように、二重連結成分が定義される。
辺集合Eが二重連結⇔Eで誘導されるグラフが関節点を持たない


作業中:二重辺連結成分分解が木を作るように、関節点と二重辺連結成分を頂点として持つ木みたいなのを作れる
joi/spring/12/sokoban.cpp 山椒

多重辺は対応していない、多重辺があっても関節点かどうかには関わりがない。
対応したいならEdgeにidみたいなのを持たせておいてif文の判定をそれでやる


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

template<class E>
struct Articulation{
	using P = pair<int,E>;
	using VP = vector<P>;

	//in
	vector<vector<E>> G;

	//out
	vector<int> arts;
	vector<VP> biedges;

	//out(ConstructGraphAB)
	vector<vector<int>> GraphAB;


	//tmp
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
		rep(i,A){
			a2id[arts[i]] = i;
		}

		rep(b,B){
			vector<int> vc;
			for(P p:biedges[b]){
				int from = p.fs;
				int to = p.sc.to;
				if(a2id[from]!=-1){
					vc.pb(a2id[from]);
				}
				if(a2id[to]!=-1){
					vc.pb(a2id[to]);
				}
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
struct Edge{
	int to;
	friend ostream& operator<<(ostream& o,const Edge& e){return o<<e.to;}
};
int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<Edge>> G(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb({b});G[b].pb({a});
	}

	Articulation<Edge> art(G);
	art.ConstructGraphAB();


	show(art.arts);
	int K=art.biedges.size();
	show(K);
	rep(i,K) show(art.biedges[i]);
	puts("---GraphAB---");
	rep(v,art.GraphAB.size()){
		for(int u:art.GraphAB[v]){
			if(v<u) cout<<"("<<v<<","<<u<<")"<<endl;
		}
	}
}
