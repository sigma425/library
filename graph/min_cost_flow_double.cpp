typedef pair<double,int> P;
struct edge{
	int to,cap;
	double cost;
	int rev;
};
const int MAX_V=;
double inf=,eps=;
int V;
vector<edge> G[MAX_V];
double h[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from,int to,int cap,double cost){
	edge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};
	G[from].pb(e1);
	G[to].pb(e2);
}
double min_cost_flow(int s,int t,int f){
	double res=0;
	fill(h,h+V,0);
	while(f>eps){
		priority_queue<P,vector<P>,greater<P> > que;
		fill(dist,dist+V,inf);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.sc;
			if(dist[v]<p.fs) continue;
			rep(i,G[v].size()){
				edge &e=G[v][i];
				if(e.cap>eps&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==inf) return -1;
		rep(v,V) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}
