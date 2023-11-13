/*
	RSK correspondence
	O(N^2)
	P: 最終的なSYT
	Q: そのマスが増えたタイミング	
*/
pair<VV<int>,VV<int>> p2PQ(V<int> p){
	int N = si(p);
	VV<int> P,Q;
	rep(i,N){
		int v = p[i];
		for(int h=0;;h++){
			if(si(P) == h){
				P.pb({});
				Q.pb({});
			}
			if(P[h].empty() or P[h].back() < v){
				P[h].pb(v);
				Q[h].pb(i);
				break;
			}
			rep(w,si(P[h])) if(P[h][w] > v){
				swap(P[h][w],v);
				break;
			}
		}
	}
	return make_pair(P,Q);
}
V<int> PQ2p(VV<int> P, VV<int> Q){
	using pa = pair<int,int>;
	int N = 0;
	rep(i,si(P)) N += si(P[i]);
	V<pa> iQ(N);
	rep(i,si(P)) rep(j,si(P[i])){
		iQ[Q[i][j]] = pa(i,j);
	}
	V<int> p(N);
	const int inf = 1e9;
	per(t,N){
		int h = iQ[t].fs, w = iQ[t].sc;
		int v = P[h][w];
		P[h][w] = inf;
		h--;
		for(;h>=0;h--){
			rep(i,si(P[h])) if(P[h][i] < v){
				w = i;
			}
			swap(P[h][w],v);
		}
		p[t] = v;
	}
	return p;
}
void showPQ(pair<VV<int>,VV<int>> pq){
	auto p = pq.fs, q = pq.sc;
	int H = si(p), W = si(p[0]);
	rep(i,H){
		rep(j,W){
			if(j < si(p[i])) printf("%2d ",p[i][j]);
			else printf("   ");
		}
		printf("| ");
		rep(j,W){
			if(j < si(q[i])) printf("%2d ",q[i][j]);
			else printf("   ");
		}
		printf("\n");
	}
	printf("\n");
}