/*
ま、一応ね?
*/
vector<P> G[100000];
void dijkstra(ll *d, vector<P> *G){
	priority_queue<P,vector<P>,greater<P> > que;
	rep(i,N) d[i]=inf;
	d[0]=0;
	que.push(P(0,0));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v=p.sc;
		ll c=p.fs;
		if(d[v]!=c) continue;
		for(P p:G[v]){
			int to=p.fs;
			if(d[to]>d[v]+p.sc){
				d[to]=d[v]+p.sc;
				que.push(P(d[to],to));
			}
		}
	}
}