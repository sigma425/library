/*
	ベル数(第二種スターリング数の和)
	グループに分ける方法の列挙
	B9=21147,B10=115975,B11=678570,...
	Nを代入してdfs(0)で全列挙
	rep(i,K) rep(j,A) for(int k=j+1;k<A;k++)のところは 分割としてHasse図で直上のやつを全部探してる
	これをやることで「Xの細分全体」に再帰でアクセスできる(dfs2)ので包除とかに使える
	O((B_N)^2)とかになるのでN=9くらいまでっぽい(なんか包除するのにもっと良いオーダーのものがあるだろうか)
	↑包除の係数は1 -1 2 -6 24 -120 みたいになります
*/
typedef vector<int> vi;
typedef vector<vi> vv;
vector<vv> parts;
vv now;
map<vv,int> mp;
vector<int> G[21147];
int N,M;
void dfs(int x){
	if(x==N){
		mp[now]=parts.size();
		parts.pb(now);
		return;
	}
	rep(i,now.size()){
		now[i].pb(x);
		dfs(x+1);
		now[i].pop_back();
	}
	now.pb(vi(1,x));
	dfs(x+1);
	now.pop_back();
}

bool same(vv vs,int a,int b){
	int N=vs.size();
	int aa=-1,bb=-1;
	rep(i,N){
		for(int x:vs[i]){
			if(x==a) aa=i;
			if(x==b) bb=i;
		}
	}
	assert(aa>=0&&bb>=0);
	return aa==bb;
}
void showvv(vv vs){
	int N=vs.size();
	rep(i,N){
		cout<<"{";
		for(int x:vs[i]) cout<<x<<",";
		cout<<"}  ";
	}
	puts("");
}

long long calc[21147];
bool vis[21147];
int V;
void dfs2(int v){
	vis[v]=1;
	if(V!=v) calc[V]-=calc[v];
	for(int u:G[v]) if(!vis[u]) dfs2(u);
}

class Gxor{
	public:
	long long countsubs(vector <string> S){
		M=S.size();
		for(;;N++) if(N*(N-1)/2==S[0].size()) break;
		dfs(0);
		int K=parts.size();
		show(K);
		rep(i,K){
			int A=parts[i].size();
			rep(j,A) for(int k=j+1;k<A;k++){
				vv nv;
				rep(l,A){
					if(l==j){
						vi h=parts[i][j];
						h.insert(h.end(),all(parts[i][k]));
						sort(all(h));
						nv.pb(h);
					}else if(l!=k){
						nv.pb(parts[i][l]);
					}
				}
				assert(mp.count(nv));
				int id=mp[nv];
				G[id].pb(i);
			}
		}
		for(int i=K-1;i>=0;i--){		//partition small -> large
//			show(i);
			V=i;
			memset(vis,0,K);
			dfs2(i);
//			for(int j:G[i]) show(j),calc[i]-=calc[j];
//			puts("");
		}
		return calc[0];
	}
};
