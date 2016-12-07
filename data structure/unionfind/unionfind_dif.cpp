/*
	w[x]-w[y]=d とするクエリ unite(x,y,d)
	w[x]-w[y] を答えるクエリ diff(x,y)が処理できる
	d[x]=w[par[x]]-w[x]
	diffの前にsameで比較可能かどうか見ること!!(same<->比較可能)
	sameしてればdiffの中のfindはいらないけど一応

	w[x]=定数 みたいなのがあるなら,w[0]:=0としてw[x]-w[0]=定数 にする
	w[x]+w[y]=aとかも頂点倍加で

	verified by http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
*/
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;
struct unionfind{
	int par[100000];
	ll d[100000];
	void init(int n) { rep(i,n) par[i]=i,d[i]=0; }
	int find(int x){
		if(x==par[x]) return x;
		int r=find(par[x]);
		d[x]+=d[par[x]];
		return par[x]=r;
	}
	void unite(int x,int y,int z){		//w[x]-w[y]=z	
		int rx=find(x),ry=find(y);
		if(rx==ry) return;
		d[ry]=d[x]-d[y]-z;
		par[ry]=rx;
	}
	int diff(int x,int y){		//w[x]-w[y]=?
		find(x),find(y);			//いる!!
		return d[x]-d[y];
	}
	bool same(int x,int y) { return find(x)==find(y); }
}UF;

int main(){
	while(true){
		int N,M;
		cin>>N>>M;
		if(N==0) break;
		UF.init(N);
		rep(t,M){
			char c;
			cin>>c;
			if(c=='!'){
				int x,y,z;
				cin>>x>>y>>z;
				x--,y--;
				UF.unite(y,x,z);
			}else{
				int x,y;
				cin>>x>>y;
				x--,y--;
				if(!UF.same(x,y)) puts("UNKNOWN");
				else cout<<UF.diff(y,x)<<endl;
			}
		}
	}
}