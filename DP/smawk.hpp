/*
	totally monotone な H*W 行列 A に対し、各行のargmaxの位置を計算する
		monotone: argmaxが下の行ほど右にある
		totally monotone: 各 2x2 submatrix が monotone
		monotone なだけなら monotone_minima を使う
		monge => totally monotone なので 最適化DP なら成り立ってることが多い?

	A にランダムな順でアクセスクエリが飛んでくるので、DPで上の行から順に埋まる とかだと無理
	https://noshi91.hatenablog.com/entry/2023/02/18/005856 でいう オンライン / ランダム

	in:
		H,W: size
		select(i, j1, j2) := A[i][j1] と A[i][j2] のうち左が "良い" か? (j1 < j2)
			leftmost argmax が条件を満たすなら
				[&](int i, int j1, int j2){return A[i][j1] >= A[i][j2];}
			rightmost argmax が条件を満たすなら
				[&](int i, int j1, int j2){return A[i][j1] > A[i][j2];}
			もしくは -A が totally monotone みたいなケースでも select を変えるだけで良い

	O(H+W)
*/

#include "template.hpp"
template<class Select>
vector<int> smawk(int H, int W, Select select){
	auto rec = [&](auto&& self, const vector<int>& hs, const vector<int>& ws) -> vector<int> {
		int N = hs.size();
		if(N == 0) return {};

		vector<int> h2;
		for(int i=1;i<N;i+=2) h2.push_back(hs[i]);

		vector<int> w2;
		for(int w: ws){
			while(!w2.empty() && select(hs[w2.size()-1], w2.back(), w)){
				w2.pop_back();
			}
			if(w2.size() < N) w2.push_back(w);
		}

		vector<int> a2 = self(self, h2, w2);
		vector<int> ans(N);
		rep(i,si(a2)) ans[i*2+1] = a2[i];
		int j = 0;
		for(int i=0;i<N;i+=2){
			ans[i] = w2[j];
			int end = i == N-1 ? w2.back() : ans[i+1];
			while(w2[j] != end){
				j++;
				if(select(hs[i], ans[i], w2[j])){
					ans[i] = w2[j];
				}
			}
		}
		return ans;
	};
	vector<int> hs(H); iota(all(hs),0);
	vector<int> ws(W); iota(all(ws),0);
	return rec(rec,hs,ws);
}