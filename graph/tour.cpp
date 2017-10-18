/*
https://gist.github.com/snuke/df5d66a2adb575228c96

AとBは必ず同じサイクルに含まれる で分解したもの ちゃんと同値関係になっている
Aを取り除くとBが橋 と同値
橋検出の際のimos法っぽいことをやるときに、足す値を乱数にして、それが一致するものが同じグループ
llだと危険そう?
*/

unsigned long long seed = 1145141919810893ULL;
unsigned long long xor_rand(){
  seed = seed ^ (seed<<13);
  seed = seed ^ (seed>>7);
  seed = seed ^ (seed<<17);
  return seed;
}


class ToursDecomposition {
 public:
  struct Edge {
    int u, v;
    Edge() {}
    Edge(int u, int v) : u(u), v(v) {}
  };
  int n;
  vector< vector<int> > to;
  vector<int> depth;
  using ull = unsigned long long;
  vector<ull> hash;
  map< ull, vector<Edge> > group;
  ToursDecomposition() {}
  ToursDecomposition(int n) : n(n), to(n), depth(n, -1), hash(n) {}
  void AddEdge(int u, int v) {
    to[u].push_back(v);
    to[v].push_back(u);
  }
  void Init() {
    rep(i,n) {
      if (depth[i] != -1) continue;
      depth[i] = 0;
      dfs(i, -1);
    }
  }
 private:
  void dfs(int v, int p) {
    for (int u : to[v]) {
      if (depth[u] == -1) {
        depth[u] = depth[v] + 1;
        dfs(u, v);
        hash[v] += hash[u];
        group[hash[u]].push_back(Edge(u, v));
      } else if (depth[u] < depth[v] && u != p) {
        ull r = xor_rand();
        group[r].push_back(Edge(u, v));
        hash[v] += r;
        hash[u] -= r;
      }
    }
  }
};
