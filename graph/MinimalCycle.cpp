/*
    minimal な ( <=> induced graph も cycle, chordless?) cycle を一つ返す、なければ {}
    O(V+E)
    verified at : ABC142 F (でも、嘘(Down1個)が通ったのでまともなverifyではない・・・)

    undirected なら dfs tree の Up のうち最短を取ればおわり
    directed ならそのサイクル内で Down を使いまくる必要があって、その頂点から貪欲に最長を取ればいい
*/

V<int> getMinimalCycleDirected(const VV<int>& G){
	using P = pair<int,int>;
	int N = G.size();
	V<int> vis(N);	//0:yet 1:now 2:done
	V<int> par(N,-1);
	V<int> d(N);

	P U(-1,-1);	// min distance backward edge

	function<void(int)> dfs = [&](int v){
		vis[v] = 1;
		for(int u: G[v]){
			if(vis[u] == 0){	// dfs edge
				par[u] = v;
				d[u] = d[v]+1;
				dfs(u);
			}else if(vis[u] == 1){	// up
				if(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){
					U = P(v,u);
				}
			}else{}	// left, down
		}
		vis[v] = 2;
	};
	rep(v,N) if(vis[v] == 0){
		dfs(v);
	}
	if(U.fs == -1) return {};
	V<bool> in_cycle(N);
	V<int> c;
	{
		int v = U.fs;
		while(true){
			c.pb(v); in_cycle[v] = true;
			if(v == U.sc) break;
			v = par[v];
		}
	}
	reverse(all(c));
	V<int> nc;
	{
		int v = c[0];
		while(true){
			nc.pb(v);
			if(v == c.back()) break;
			int nxt = v;
			for(int u: G[v]) if(in_cycle[u] && d[u] > d[nxt]) nxt = u;
			v = nxt;
		}
	}
	return nc;
}
