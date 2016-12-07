/*
input
N A
N*A matrix
q0
Fsize
F0,F1,...

sample input
16 2
1 15
3 2
15 15
6 4
15 5
15 15
10 7
15 8
15 9
15 15
15 11
15 12
15 13
15 14
15 15
15 15
0
5
0 2 5 9 14
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
	DFA minimizeDFA(){
		bool dis[Qmax][Qmax]={};
		bool inF[Qmax]={};
		for(int f:F) inF[f]=1;
		rep(i,Q) rep(j,Q) if(inF[i]!=inF[j]) dis[i][j]=1; 
		bool update=1;
		while(update){
			update=0;
			rep(i,Q) rep(j,Q){
				if(dis[i][j]) continue;
				rep(k,A){
					if(dis[t[i][k]][t[j][k]]){
						update=1;
						dis[i][j]=1;
						printf("i,j=%d,%d\n",i,j);
						break;
					}
				}
			}
		}
		int root[Qmax];
		rep(i,Q) root[i]=i;
		rep(i,Q){
			rep(j,i){
				if(!dis[i][j]){
					root[i]=j;
					break;
				}
			}
		}
		vi ash;
		rep(i,Q) ash.pb(root[i]),show(root[i]);
		sort(all(ash));
		ash.erase(unique(all(ash)),ash.end());
		rep(i,Q) root[i]=lower_bound(all(ash),root[i])-ash.begin();
		int NQ=ash.size();
		int NA=A;
		vector<vi> Nt(Q,vi(A,0));
		rep(i,Q) rep(j,A) Nt[root[i]][j]=root[t[i][j]];
		int Nq0=root[q0];
		vi NF;
		for(int f:F) NF.pb(root[f]);
		sort(all(NF));NF.erase(unique(all(NF)),NF.end());
		return DFA(NQ,NA,Nt,Nq0,NF);
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
struct NFA{
	
};
int main(){
	DFA M=readDFA();
	DFA M2=M.minimizeDFA();
	show(M2.Q);
}
