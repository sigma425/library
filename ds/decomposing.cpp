/*
	decomposable problem
	データを複数個のデータに分けた後、それぞれにqueryを投げた後統合できる形ならできる
	query([a1,a2,a3,a4,a5]) = query([a1,a2]) * query([a3]) * query([a4,a5])

	countとかならerase用のを作って消す

	下の例はBIT(座標範囲制限なし) 愚直にsorted vectorにもつだけ
	vv[K-2] と vv[K-1] は一から作らなくてもmergeでいいため、計算量はO(NlogN)
*/

struct Decomposing{
	using D = int;
	vector<vector<D>> vv;

	Decomposing(){}

	void add(D x){
		vv.pb({x});
		while(true){
			int K = vv.size();
			if(K==1 || vv[K-1].size()!=vv[K-2].size()) break;
			vector<D> nv(vv[K-1].size()+vv[K-2].size());
			merge(all(vv[K-2]),all(vv[K-1]),nv.begin());	//reconstruct (with using vv[K-2],vv[K-1])
			vv.pop_back();vv.pop_back();
			vv.pb(nv);
		}
	}
	int get(int x){
		int res = 0;
		for(const auto& v:vv){	//calc query for each and combine them
			res += lower_bound(all(v),x) - x.begin(); // x 未満
		}
		return res;
	}
};
