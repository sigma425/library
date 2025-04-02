
/*
	D 次元 Z/pZ ベクトル a_0, a_1, ... を追加していき、その状態で suffix の基底がどうなっているかを扱うライブラリ
		- add(a): 末尾にベクトル a を追加
		- get_l(v): v \in span(a_l, ... , a_{n-1}) となる最大の l, なければ -1, v が 0 ベクトルなら n を返す
		- get_index(): a[n-1] から順番に suffix を左に伸ばしていって、span が変化する index の列挙 (降順)
	
	ようは基底に関する区間クエリで使える。 a_r まで追加したあとに get_l(v) >= l かどうかをみれば v \in span([l,r]) かどうかわかる
	線形結合の係数の復元は計算量が悪くなると思うのでやってない

	計算量は現在の rank を r として O(rD). xor なら D が算術操作に吸収されて消える、下にある SuffixXorBasis 参照

	参考: https://noshi91.hatenablog.com/entry/2023/12/06/002723
	verify: ABC399-G https://atcoder.jp/contests/abc399/submissions/64444473, get_index
*/
template<class Mint>
struct SuffixLinearBasis{
	int n;
	vector<pair<int, vector<Mint>>> b;

	SuffixLinearBasis() : n(0) {}

	/*
		末尾にベクトル a を追加
		O(rD)
	*/
	void add(const vector<Mint>& a){
		int D = a.size();
		pair<int, vector<Mint>> p = {n, a};
		n++;
		bool added = false;
		for(auto it = b.begin(); it != b.end(); it++){
			int pl = lsb(p.sc), il = lsb(it->sc);
			if(pl < il){
				b.insert(it, p);
				added = true;
				break;
			}
			if(p.sc[il] == 0) continue;
			if(p.fs > it->fs){
				swap(p, *it);
			}
			// p.sc -= it->sc * (p.sc[il] / it->sc[il]);
			Mint c = p.sc[il] / it->sc[il];
			for(int d=il;d<D;d++) p.sc[d] -= it->sc[d] * c;
		}
		if(!added && lsb(p.sc) != D) b.push_back(p);
	}

	/*
		v \in span(a_l, .., a_{n-1}) となる最大の l, なければ -1, v が 0 ベクトルなら n を返す
		O(rD)
	*/
	int get_l(vector<Mint> v){
		int D = v.size();
		int h = lsb(v);
		if(h == D) return n;
		int l = n;
		for(const auto& [i, a] : b){
			int hh = lsb(a);
			if(h < hh) return -1;
			if(h > hh) continue;
			Mint c = v[hh] / a[hh];
			for(int d=hh;d<D;d++) v[d] -= a[d] * c;
			h = lsb(v);
			chmin(l, i);
		}
		if(h != D) return -1;
		return l;
	}

	/*
		a[n-1] から順番に suffix を左に伸ばしていって、span が変化する index の列挙 (降順)
		res[i] = (rank = i+1 になるために追加する suffix の index)
		O(r log r)
	*/
	vector<int> get_index(){
		vector<int> res; for(const auto& [i, a] : b) res.emplace_back(i);
		sort(all(res), greater<int>());
		return res;
	}

	/*
		最初の non0
		O(D)
	*/
	int lsb(const vector<Mint>& v){
		return find_if(v.begin(), v.end(), [](Mint x){ return x != 0; }) - v.begin();
	};
};


/*
	xor 版
	T = int, ull など
	verify: ABC223-H https://atcoder.jp/contests/abc223/submissions/64445206, get_l
*/
template<class T>
struct SuffixXorBasis{
	int n;
	vector<pair<int, T>> b;

	SuffixXorBasis() : n(0) {}

	/*
		末尾にベクトル a を追加
		O(r)
	*/
	void add(T a){
		pair<int, T> p = {n, a};
		n++;
		bool added = false;
		for(auto it = b.begin(); it != b.end(); it++){
			if((p.sc & ~it->sc) > it->sc){
				b.insert(it, p);
				added = true;
				break;
			}
			if(p.sc <= (p.sc ^ it->sc)) continue;
			if(p.fs > it->fs){
				swap(p, *it);
			}
			p.sc ^= it->sc;
		}
		if(!added && p.sc) b.push_back(p);
	}

	/*
		v \in span(a_l, .., a_{n-1}) となる最大の l, なければ -1, v が 0 ベクトルなら n を返す
		O(r)
	*/
	int get_l(T v){
		if(v == 0) return n;
		int l = n;
		for(const auto& [i, a] : b){
			if(v > (v ^ a)){
				v = v ^ a;
				chmin(l, i);
			}
		}
		if(v) return -1;
		return l;
	}

	/*
		a[n-1] から順番に suffix を左に伸ばしていって、span が変化する index の列挙 (降順)
		res[i] = (rank = i+1 になるために追加する suffix の index)
		O(r log r)
	*/
	vector<int> get_index(){
		vector<int> res; for(const auto& [i, a] : b) res.emplace_back(i);
		sort(all(res), greater<int>());
		return res;
	}
};