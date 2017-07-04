/*
	D によってinf の書き換え
	double なら = まわりを変える
*/
template<class D>
vector<D> dijkstra(const vector<vector<pair<int,D>>>& G, int s = 0){	//G:(v,cost)
	using P = pair<D,int>;
	priority_queue<P,vector<P>,greater<P> > que;
	int N = G.size();

	D inf = 1e18;
	vector<D> d(N,inf);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v = p.sc;
		D c = p.fs;
		if(d[v]!=c) continue;
		for(auto p:G[v]){
			int to=p.fs;
			if(d[to]>d[v]+p.sc){
				d[to]=d[v]+p.sc;
				que.push(P(d[to],to));
			}
		}
	}

	return d;
}