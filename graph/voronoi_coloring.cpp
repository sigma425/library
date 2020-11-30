/*
	距離空間上の点集合が与えられた時に、MST
	これはボロノイ図を作って接してる色どうしに飲み編を塗れば良い
	そのために、多点スタートのdijkstra(どの点から来たかも持つ)をして、この場所（頂点とは限らない）ではどの色どうしが接してるかみたいなのを持つ
	Tree MST, Water Bottle, 覚えてないけどSnukezavodskかなんかの2^20状態のやつ などはこの枠組みで考えられる
	この実装が使えるとは限らないけど

	initial_color: その頂点から出てくる色、ついてないなら-1
	pair<距離vec,色vec> を返す
	
	verified: https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j
*/
template<class D>
pair<vector<D>,vector<int>> dijkstra_coloring(const vector<vector<pair<int,D>>>& G, V<int> initial_color){	//G:(v,cost)
	using P = pair<D,int>;
	priority_queue<P,vector<P>,greater<P> > que;
	int N = G.size();

	D inf = 1e18;
	vector<D> d(N,inf);
	V<int> col(N,-1);;
	rep(v,N) if(initial_color[v] != -1){
		d[v] = 0;
		que.push(P(0,v));
		col[v] = initial_color[v];
	}

	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.sc;
		D c = p.fs;
		if(d[v]!=c) continue;
		for(auto p:G[v]){
			int to=p.fs;
			if(d[to]>d[v]+p.sc){
				d[to]=d[v]+p.sc;
				que.push(P(d[to],to));
				col[to] = col[v];
			}
		}
	}

	return make_pair(d,col);
}
