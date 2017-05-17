//AOJ2450をそのままコピーしただけ
#include <bits/stdc++.h>
#define int long long
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
const int MAX_N=200000;
int N,Q;
int par[MAX_N][18];
int p[MAX_N];
int depth[MAX_N];

void genlca(){
	rep(i,N) par[i][0]=p[i];
	for(int i=1;i<=17;i++){
		rep(v,N){
			if(par[v][i-1]==-1) par[v][i]=-1;
			else par[v][i]=par[par[v][i-1]][i-1];
		}
	}
}
typedef pair<int,int> P;
P lca(int u,int v){
	bool swapped=0;
	if(depth[u]<depth[v]){
		swap(u,v);
		swapped=1;
	}
	int d=depth[u]-depth[v];
	rep(i,18){
		if((d>>i)&1) u=par[u][i];
	}
	if(u==v) return P(u,-1);
	for(int i=18-1;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	if(!swapped) return P(par[v][0],v);
	else return P(par[v][0],u);
}

struct Node{
	int mx,l,r,sum;
	Node(){mx=-1e9,l=-1e9,r=-1e9,sum=0;}
};
Node merge(Node a,Node b){
	Node ret;
	ret.sum=a.sum+b.sum;
	ret.l=max(a.l,a.sum+b.l);
	ret.r=max(b.r,b.sum+a.r);
	ret.mx=max(a.r+b.l,max(a.mx,b.mx));
	return ret;
}
Node flip(Node a){
	swap(a.l,a.r);
	return a;
}
void shownode(Node a){
	printf("l=%d,r=%d,mx=%d,sum=%d\n",a.l,a.r,a.mx,a.sum);
}
struct segtree{
	int getp2(int x){
		int p=1;
		while(p<x) p*=2;
		return p;
	}
	segtree(int N):N(N),p2(getp2(N)),seg(p2*2),same(p2*2),val(p2*2) {}
	int N;
	int p2;
	vector<Node> seg;
	vector<bool> same;
	vector<int> val;
	void dosame(int k,int v,int len){
		if(len==0) return;
		same[k]=1,val[k]=v;
		// show(k);
		// show(v);
		// show(len);
		// puts("");
		if(v>=0) seg[k].l=seg[k].r=seg[k].mx=seg[k].sum=v*len;
		else seg[k].l=seg[k].r=seg[k].mx=v,seg[k].sum=v*len;
//		else seg[k].l=seg[k].r=seg[k].mx=v,seg[k].sum=v*len;
	}
	Node calc(int a,int b,int l,int r,int k){
		if(r<=a||b<=l) return Node();
		if(a<=l&&r<=b) return seg[k];
		if(same[k]){
			dosame(k*2,val[k],(r-l)/2);
			dosame(k*2+1,val[k],(r-l)/2);
		}
		return merge(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));
	}
	Node calc(int a,int b){
		return calc(a,b,0,p2,1);
	}
	void change(int a,int b,int l,int r,int k,int v){
		if(r<=a||b<=l) return;
		if(a<=l&&r<=b){
			dosame(k,v,r-l);
			return;
		}
		if(same[k]){
			dosame(k*2,val[k],(r-l)/2);
			dosame(k*2+1,val[k],(r-l)/2);
		}
		same[k]=0;
		change(a,b,l,(l+r)/2,k*2,v);
		change(a,b,(l+r)/2,r,k*2+1,v);
		seg[k]=merge(seg[k*2],seg[k*2+1]);
	}
	void change(int a,int b,int v){
		change(a,b,0,p2,1,v);
	}
};

int w[MAX_N];
int topo[MAX_N];
int sz[MAX_N];
int hchild[MAX_N];
int chainid[MAX_N];	//vertex->chainid
int top[MAX_N];	//chainid->top
vector<int> G[MAX_N];
void bfs(int s){
	bool vis[MAX_N]={};
	queue<int> que;
	que.push(s);
	int cnt=0;
	while(!que.empty()){
		int t=que.front();
		que.pop();
		vis[t]=1;
		topo[cnt++]=t;
		rep(i,G[t].size()){
			int v=G[t][i];
			if(!vis[v]) que.push(v);
			else{
				p[t]=v;
				G[t].erase(G[t].begin()+i);
				i--;
				continue;
			}
		}
	}
}
void dfs(int v){
	sz[v]=1;
	int id=-1;
	for(int u:G[v]){
		sz[v]+=sz[u];
		if(id<0||sz[u]>sz[id]) id=u;
	}
	hchild[v]=id;
}

vector<segtree> chains;

Node calcall(int T,int B){
	Node ret;
	while(true){
		segtree &seg=chains[chainid[B]];
		int t=top[chainid[B]];
		if(depth[t]<=depth[T]){
			int d1=depth[B]-depth[t];
			int d2=depth[T]-depth[t];
			ret=merge(ret,seg.calc(seg.N-1-d1,seg.N-d2));
/*			show(t);
			show(B);
			show(T);
			show(d1);
			show(d2);
			show(N-1-d1);
			show(seg.N-d2);*/
			return ret;
		}
		int d=depth[B]-depth[t];
		ret=merge(ret,seg.calc(seg.N-1-d,seg.N));
		B=p[t];
	}
}
void changeall(int T,int B,int v){
	while(true){
		segtree &seg=chains[chainid[B]];
		int t=top[chainid[B]];
		if(depth[t]<=depth[T]){
			int d1=depth[B]-depth[t];
			int d2=depth[T]-depth[t];
			seg.change(seg.N-1-d1,seg.N-d2,v);
			return;
		}
		int d=depth[B]-depth[t];
		seg.change(seg.N-1-d,seg.N,v);
		B=p[t];
	}
}
signed main(){
	cin>>N>>Q;
	rep(i,N) cin>>w[i];
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	bfs(0);
//	rep(i,N) show(topo[i]);
	for(int i=N-1;i>=0;i--) dfs(topo[i]);
	rep1(i,N-1){
		int v=topo[i];
		depth[v]=depth[p[v]]+1;
	}
	p[0]=-1;
//	rep(i,N) show(p[i]);
	int C=0;
	bool vis[MAX_N]={};
	rep(i,N){
		int v=topo[i];
		if(!vis[v]){
			top[C]=v;
			vector<int> vc;
			int u=v;
			while(u>=0){
				vc.pb(u);
				vis[u]=1;
				chainid[u]=C;
				u=hchild[u];
			}
			int Nc=vc.size();
			segtree seg(Nc);
//			show(Nc);
			rep(j,Nc){
				seg.change(j,j+1,w[ vc[Nc-1-j] ]);
//				show(j);
//				show(vc[Nc-1-j]);
//				show(w [vc[Nc-1-j] ]);

			}
			chains.pb(seg);
			C++;
		}
	}
//	show(C);
	genlca();
//	rep(i,N) show(depth[i]);
//	show(p.fs);
//	show(p.sc);
	rep(tt,Q){
		int t,a,b,c;
		cin>>t>>a>>b>>c;
		a--,b--;
		P p=lca(a,b);
//		show(p.fs);
//		show(p.sc);
		if(t%2){
			if(p.sc==-1){
				if(b==p.fs) swap(a,b);
				changeall(a,b,c);
			}else{
				changeall(p.fs,a,c);
				changeall(p.sc,b,c);
			}
		}else{
			if(p.sc==-1){
				if(b==p.fs) swap(a,b);
//				show(a);
//				show(b);
//				shownode(calcall(a,b));
				cout<<calcall(a,b).mx<<endl;
			}else{
				Node x=calcall(p.fs,a);
				Node y=calcall(p.sc,b);
//				show(a);
//				show(p.fs);
//				shownode(x);
//				show(b);
//				show(p.sc);
//				shownode(y);
				cout<<merge(x,flip(y)).mx<<endl;
			}
		}
	}
}
