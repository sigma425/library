/*
	suffix tree

	S = aabbabbaa

	suffix array
	---------
	a--------
	aa-------
	aabbabbaa
	abbaa----
	abbabbaa-
	baa------
	babbaa---
	bbaa-----
	bbabbaa--

	suffix tree の node はこの長方形領域を表す index は preorder (だし、辞書順で早いほうが先)
	---------
	1--------
	12-------
	123333333
	14445----
	14446666-
	789------
	78AAAA---
	7BBC-----
	7BBDDDD--

	例えば node 4 は、 ud[4,6) * lr[1,4) = bba

	suffix_tree.png も参照

	初期化:
		SuffixTree(SuffixArray) で諸々を計算
	dat:
		上述の長方形の {u, d, l, r}		0 <= u < d <= sLen+1, 0 <= l <= r <= sLen
		v = 0 でだけ l = r になるので注意 (iff)
		例えば、dat[4] = {4, 6, 1, 4}, dat[0] = {0, sLen+1, 0, 0}
	G:
		suffix tree としての(有向)辺
		例えば G[4] = {5,6}, G[0] = {1,7}
	endpos:
		頂点 v が s[i,N) に対応するならば、endpos[v] = i. ないなら -1
		例えば endpos[4] = -1, endpos[2] = 7, endpos[0] = sLen

	debug(string s):
		元の文字列を渡して↑の情報をわかりやすく出力
	
	verify: ucup-3-9 C https://contest.ucup.ac/submission/563208
*/

#include "ds/cartesian_tree.hpp"

template<class SuffixArray>
struct SuffixTree {
	struct Node {
		int u, d, l, r;
		friend ostream& operator<<(ostream &o, const Node& x){
			return o << "ud[" << x.u << "," << x.d << ") * lr[" << x.l << "," << x.r << ")";
		}
	};

	const SuffixArray& SA;

	vector<Node> dat;
	vector<vector<int>> G;
	V<int> endpos;

	SuffixTree(const SuffixArray& SA_):SA(SA_){
		const auto& sa = SA.sa;
		const auto& lcp = SA.lcp;
		int sLen = lcp.size();
		CartesianTree<int, true> CT(SA.lcp);

		auto dfs = [&](auto&& self, int idx, int par, int baseh) -> void {
			int L = CT.range[idx].first;
			int R = CT.range[idx].second + 1;
			int h = lcp[idx];
			if(par == -1 || baseh < h){
				if(par != -1) G[par].eb(dat.size());
				par = dat.size();
				dat.eb(L, R, baseh, h); G.pb({}); endpos.pb(-1);
			}
			if(CT.lch[idx] == -1){
				int len = sLen - sa[idx];
				if(h < len){
					G[par].eb(dat.size());
					dat.eb(idx, idx+1, h, len); G.pb({}); endpos.pb(sa[idx]);
				}else{
					endpos.back() = sa[idx];
				}
			}else{
				self(self, CT.lch[idx], par, h);
			}
			if(CT.rch[idx] == -1){
				int len = sLen - sa[idx+1];
				G[par].eb(dat.size());
				dat.eb(idx+1, idx+2, h, len); G.pb({}); endpos.pb(sa[idx+1]);
			}else{
				self(self, CT.rch[idx], par, h);
			}
		};
		dfs(dfs, 0, -1, 0);
	}

	void debug(string s){
		int M = dat.size();
		cerr << "--------- suffix tree debug start ---------" << endl;

		rep(i,s.size()+1) cerr << s.substr(SA.sa[i]) << endl; 
		cerr << endl;

		rep(v,M){
			int off = SA.sa[dat[v].u];
			cerr << "id = " << v << " : " << dat[v] << " = " << s.substr(off + dat[v].l, dat[v].r-dat[v].l) << endl;
		}
		cerr << endl;

		rep(v,M){
			cerr << "children of " << v << " : ";
			for(int u: G[v]) cerr << u << ", ";
			cerr << endl;
		}
		cerr << endl;
		cerr << "endpos " << endpos << endl;
		cerr << endl;
		cerr << "--------- suffix tree debug end ---------" << endl;
	}
};