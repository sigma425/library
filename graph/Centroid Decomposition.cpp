struct edge{int to,;};
const int MAX_N=;
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