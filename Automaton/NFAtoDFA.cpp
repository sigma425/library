/*
2^N全てを列挙するのではなく,たどり着ける状態だけを考えたものなので,やってみるとはやい,という可能性はある
vectorでもってるけど結局bool列挙みたいなのでループの中でQ^2とかやってるし意味ないかも


NFAの入力例
Q A
M
q a nq
...
q0
Fsize
f1 f2...
5 2
8
0 0 0
0 0 1
1 0 3
1 1 1
1 1 2
2 0 0
2 1 2
3 0 1
0
2
2 3
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
const int Qmax=100;
typedef vector<int> vi;
struct DFA{
	int Q;		//state
	int A;		//alphabet
	vector<vi> t;
	int q0;
	vi F;
	DFA(int Q,int A,vector<vi> t,int q0,vi F) :Q(Q),A(A),t(t),q0(q0),F(F){}
	void showDFA(){
		printf("Q=%d   A=%d    q0=%d\nF:",Q,A,q0);
		for(int f:F) cout<<f<<" ";
		puts("");
		rep(i,Q){
			rep(j,A) cout<<t[i][j]<<" ";
			puts("");
		}
	}
};
struct NFA{
	int Q;
	int A;
	vector<vector<vi> > t;
	int q0;
	vi F;
	NFA(int Q,int A,vector<vector<vi> >t,int q0,vi F) :Q(Q),A(A),t(t),q0(q0),F(F){}
	DFA NFAtoDFA(){
		int DN=1;
		vector<vi> dt(1,vi(A,0));
		vi DF;
		map<vi,int> mp;		//sets->id
		queue<vi> que;
		que.push(vi{q0});
		mp[vi{q0}]=0;
		while(!que.empty()){
			vi vc=que.front();que.pop();
			bool isF=0;
			for(int f:F) for(int v:vc) if(f==v) isF=1;
			if(isF) DF.pb(mp[vc]);
			show(mp[vc]);
			rep(i,A){
				vi nvc;
				for(int v:vc){
					for(int u:t[v][i]) nvc.pb(u);
				}
				sort(all(nvc));nvc.erase(unique(all(nvc)),nvc.end());
				if(!mp.count(nvc)){
					mp[nvc]=DN++;
					dt.pb(vi(A,0));
					que.push(nvc);
				}
				dt[mp[vc]][i]=mp[nvc];
			}
		}
		for(auto p:mp){
			cout<<p.sc<<":  ";
			for(auto v:p.fs) cout<<v<<" ";
			puts("");
		}
		return DFA(mp.size(),A,dt,0,DF);
	}
};

DFA readDFA(){
	int Q,A,q0,Fsize;
	cin>>Q>>A;
	vector<vi> t(Q,vi(A,0));
	vector<int> F;
	rep(i,Q) rep(j,A) cin>>t[i][j];
	cin>>q0>>Fsize;
	rep(i,Fsize){
		int x;
		cin>>x;
		F.pb(x);
	}
	return DFA(Q,A,t,q0,F);
}
NFA readNFA(){
	int Q,A,q0,Fsize,M;
	cin>>Q>>A;
	vector<vector<vi> > t(Q,vector<vi>(A,vi{}));
	vector<int> F;
	cin>>M;
	rep(i,M){
		int x,a,y;
		cin>>x>>a>>y;
		t[x][a].pb(y);
	}
	cin>>q0>>Fsize;
	rep(i,Fsize){
		int x;
		cin>>x;
		F.pb(x);
	}
	return NFA(Q,A,t,q0,F);
}
int main(){
	NFA nfa=readNFA();
	DFA d=nfa.NFAtoDFA();
	d.showDFA();
}
