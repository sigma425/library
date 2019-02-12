/*
	多重辺、自己ループも大丈夫

	MaxMatching(N) -> add_edge(x,y) -> maxMatching()
	mate[v] = u or -1

	N = 500, M <= N Choose 2 で 200 ms

	https://min-25.hatenablog.com/entry/2016/11/21/222625

	N = M = 100000 なら多分通る

	verified at:
		http://uoj.ac/problem/79
		https://www.spoj.com/problems/ADABLOOM/

*/

struct MaxMatching{
	int N;
	VV<int> G;

	V<int> mate;

	void add_edge(int a,int b){
		if(a == b) return;
		G[a].pb(b);
		G[b].pb(a);
	}

	MaxMatching(int _N):N(_N),G(N){}

	using P = pair<int,int>;

	int maxMatching(){
		mate = V<int>(N+1,N);
		V<int> first(N+1,N),que(N);
		V<P> label(N+1,P(-1,-1));
		int qh = 0, qt = 0;

		auto enqueue = [&](int v){
			que[qt++] = v;
		};
		auto dequeue = [&](){
			return que[qh++];
		};

		function<void(int,int)> rematch = [&](int a, int b){
			int c = mate[a];
			mate[a] = b;
			if(mate[c] != a) return;
			if(label[a].sc == -1){
				mate[c] = label[a].fs;
				rematch(mate[c],c);
			}else{
				int x,y;
				tie(x,y) = label[a];
				rematch(x,y);
				rematch(y,x);
			}
		};
		auto relabel = [&](int a, int b){
			function<int(int)> findFirst = [&](int v){
				if(label[first[v]].fs < 0) return first[v];
				return first[v] = findFirst(first[v]);
			};
			int x = findFirst(a), y = findFirst(b);
			if(x == y) return;
			P h(~a,b);
			label[x] = label[y] = h;
			int join = -1;
			while(true){
				if(y != N) swap(x,y);
				x = findFirst(label[mate[x]].fs);
				if(label[x] == h){
					join = x;
					break;
				}else{
					label[x] = h;
				}
			}
			for(int v: {first[a],first[b]}){
				for(;v != join; v = first[label[mate[v]].fs]){
					label[v] = P(a,b);
					first[v] = join;
					enqueue(v);
				}
			}
		};
		auto augment = [&](int s){
			label[s] = P(N,-1);
			first[s] = N;
			qh = qt = 0;
			enqueue(s);
			while(qh != qt){
				int a = dequeue();
				for(int b: G[a]){
					if(mate[b] == N && b != s){
						mate[b] = a;
						rematch(a,b);
						return true;
					}else if(label[b].fs >= 0){
						relabel(a,b);
					}else if(label[mate[b]].fs == -1){
						label[mate[b]].fs = a;
						first[mate[b]] = b;
						enqueue(mate[b]);
					}
				}
			}
			return false;
		};

		int numMatch = 0;
		rep(v,N){
			if(mate[v]<N || !augment(v)) continue;
			numMatch++;
			rep(i,qt){		// including popped !!
				int v = que[i];
				label[v] = label[mate[v]] = P(-1,-1);
			}
			label[N] = P(-1,-1);
		}
		mate.pop_back();
		rep(i,N) if(mate[i] == N) mate[i] = -1;
		return numMatch;
	}
};
