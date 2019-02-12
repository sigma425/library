/*
	Suffix Automaton
		https://www37.atwiki.jp/uwicoder/pages/2842.html
		http://e-maxx.ru/algo/suffix_automata
		https://codeforces.com/blog/entry/20861
	s の substring について t に何回現れるか、とかが得意
	application 参照

	TODO: run enumeration

*/

struct SuffixAutomaton{
	SuffixAutomaton(int N){
		init(N);
	}
	SuffixAutomaton(string s){
		init(s.size());
		NP last = nodes[0];
		for(char c: s){
			last = AddChar(last, c);
		}
		TopologicalSort();
	}
	void init(int N){
		assert(N>0);
		sz = 0;
		nodes = V<Node*>(2*N,nullptr);
		nodes[0] = MakeNode(0,false);
	}

	/*
		Node information

		構築時に作る情報を増やしたいなら、
			- Node の定義
			- MakeNode() での初期化
			- clone のときの deep copy
		を変更する

		例えば Node v にマッチするsubstr を S(v) = {abb,aabb,caabb} とする
		このように一文字ずつ前に追加した形になる

		len :
			マッチするsubstrのうちlongest (4)
		link:
			shortest から更に削ったとき(bb) どこにマッチするか
			reverse(s) の suffix tree になる (0がroot)

		なので shortest は v -> link -> len + 1
	*/
	struct Node{
		using NP = Node*;

		int id;
		int len;
		NP link;
		bool isCloned;
		map<char,NP> next;

		Node(){}

		int getLongest(){
			return len;
		}
		int getShortest(){
			return link == nullptr ? 0 : link->len+1;
		}

		/*
			nextの構造変えたいならここを変える
			今は map<char,NP>
			array<NP,(K := const alphabet size)> はアリ
			hasNextはull使うとか
			ull nextbit とか増やしたら上述の3つを変えるのを忘れないこと
		*/
		void putNext(char c, NP to){
			next[c] = to;
		}
		bool hasNext(char c){
			return next.count(c);
		}
		NP getNext(char c){
			return hasNext(c) ? next[c] : nullptr;
		}
		V<pair<char,NP>> getAllTransitions(){
			V<pair<char,NP>> res;
			for(auto it: next) res.pb(it);
			return res;
		}
	};
	using NP = Node*;

	int sz;			// the number of nodes
	V<NP> nodes;

	NP MakeNode(int len, bool isCloned){
		nodes[sz] = new Node();
		nodes[sz] -> id = sz;
		nodes[sz] -> len = len;
		nodes[sz] -> link = nullptr;
		nodes[sz] -> isCloned = isCloned;
		return nodes[sz++];
	}
	/*
		Add c to nodes[last]
		return the new node id
	*/
	NP AddChar(NP last, char c){
		NP cur = MakeNode(last->len+1, false);
		NP p;
		for(p = last; p && !p->hasNext(c); p = p->link){
			p -> putNext(c,cur);
		}
		if(p == nullptr){
			cur -> link = nodes[0];
		}else{
			NP q = p -> getNext(c);
			if(p->len+1 == q->len){
				cur -> link = q;
			}else{	//clone!
				NP clone = MakeNode(p->len+1, true);
				/*
					deep copy !
				*/
				clone -> next = q -> next;
				clone -> link = q -> link;
				for(;p!=nullptr && p->getNext(c) == q; p = p->link){
					p -> putNext(c,clone);
				}
				q -> link = cur -> link = clone;
			}
		}
		return cur;
	}

	int where(string t){
		NP now = nodes[0];
		for(char c: t){
			now = now -> getNext(c);
			if(now == nullptr) return -1;
		}
		return now -> id;
	}

	void debug(){
		cerr << "======= DEBUG !! ========" << endl;
		rep(v,sz){
			NP n = nodes[v];
			cerr << "---- Node " << v << " ----" << endl;
			for(auto p: n->next){
				char c = p.fs;
				int to = p.sc->id;
				cerr << "  --(" << c << ")--> " << to << endl;
			}
			cerr << "  suf link : " << (n->link == nullptr ? -1 : n->link->id) << endl;
			cerr << "  shortest : " << n -> getShortest() << endl;
			cerr << "  longest  : " << n -> getLongest() << endl;
			cerr << endl;
		}
		cerr << "======= DEBUG END ========" << endl;
	}

	/*
		普通にSA作るだけだとcloneのせいでtopological順になっていないのでソート
		当然 v -> u なら v < u を満たすが、更に
		p <--(suffix link)-- v なら p < v も満たす
		これはトポソのやり方的に再長距離が短い順に追加していることからわかる(suf linkをたどると再長距離は短くなるので)
	*/
	void TopologicalSort(){
		V<int> indeg(sz);
		V<NP> sorted(sz);
		rep(v,sz){
			auto trans = nodes[v] -> getAllTransitions();
			for(auto it: trans){
				indeg[it.sc->id]++;
			}
		}
		sorted[0] = nodes[0];
		int idx = 1;
		rep(i,sz){
			NP n = sorted[i];
			auto trans = nodes[n->id] -> getAllTransitions();
			for(auto it: trans){
				if(--indeg[it.sc->id] == 0){
					sorted[idx++] = it.sc;
				}
			}
		}
		nodes = sorted;
		rep(i,sz) nodes[i]->id = i;
	}



	/*
		applications
	*/

	ll getNumberOfSubstr(){
		ll res = 0;
		rep(v,sz){
			res += nodes[v]->len - (nodes[v]->link == nullptr ? 0 : nodes[v]->link->len);
		}
		return res;
	}

	/*
		https://www.spoj.com/problems/SUBLEX/
		辞書順K番目 のsubstring
	*/
	string GetKthSubstr(ll K){
		V<ll> dp(sz);
		for(int v=sz-1;v>=0;v--){
			dp[v] = 1;
			auto trans = nodes[v] -> getAllTransitions();
			for(auto it: trans){
				int u = it.sc->id;
				dp[v] += dp[u];
			}
		}
//		debug();
//		show(dp);

		K++;		//eps
		if(dp[0]<K) return "Eel";
		NP now = nodes[0];
		string res;
		while(K>1){
			K--;
			auto trans = now -> getAllTransitions();
			for(auto it: trans){
				int u = it.sc->id;
				if(K<=dp[u]){
					res += it.fs;
					now = it.sc;
					break;
				}else{
					K -= dp[u];
				}
			}
		}
		return res;
	}

	/*
		https://codeforces.com/problemset/problem/235/C
		sのsubstr s[i,j] であって t を cyclic にまわしたものと一致するものはいくつあるか?

		tがいくつあるか? なら #{v -> terminal} の DP
		今回はそれをやったあと s 上で substr をぐにょぐにょスライドさせていく
		r++ は 簡単で、 l++ もそのままか link かだけど長さを保ったままやるのがちょっと難しい
		しゃくとりっぽく l,r でやるより 今追加したい i と 今の文字列の長さ len を持ったほうがかなりわかりやすい
	*/
	void solveCF253C(){
		V<ll> dp(sz);
		NP last = nodes[sz-1];
		while(last){
			dp[last->id]++;
			last = last -> link;
		}
		for(int v=sz-1;v>=0;v--){
			auto trans = nodes[v] -> getAllTransitions();
			for(auto it: trans){
				int u = it.sc->id;
				dp[v] += dp[u];
			}
		}

		int Q;
		cin >> Q;
		rep(_,Q){
			string t;
			cin >> t;
			int n = t.size();
			int len = 0;
			NP now = nodes[0];
			V<NP> visited;

			rep(i,n+n-1){
				char c = t[i%n];
				while(now && !now->hasNext(c)){
					now = now -> link;
					len = now ? now->getLongest() : 0; 
				}
				if(!now){
					now = nodes[0];
					len = 0;
				}else{
					now = now -> getNext(c);
					len++;
				}
				if(len > n){
					if(now -> getShortest() == len){
						now = now -> link;
					}
					len--;
					assert(len == n);
				}
				if(len == n){
					visited.pb(now);
				}
			}
			sort(all(visited));
			visited.erase(unique(all(visited)),visited.end());
			ll ans = 0;
			for(NP np : visited){
				ans += dp[np->id];
			}
			cout << ans << endl;
		}
	}

	/*
		https://codeforces.com/contest/316/problem/G3

		(t_i に [l_i,r_i] 回出現する) をすべて満たす s の substr は何通り?
		a が t_i に何回出現するか? は #{where(a) -> t_i.terminal} を考えればよかった

		実は str := s + '0' + t_1 + '1' + .. + t_Q + 'Q' という文字列を SA にかけると解ける
		各ノード内では、t_i が何回出てくるかは(そのノードへの到達方法によらず) 一定
		こうやって str を作ると、 v -> '1' への path が何通りあるか? みたいなものになってほしいが、
		当然 '0' のあとのものを数えたり substr -> '0' -> '1' みたいに s の内側に収まってないものを数えてもしょうがない
		なので答えに値を足し込むのは '0' の前 (v -> '0' path exists) で、
		dp の遷移は区切り文字のときはやらないようにする と達成できる

		区切り文字で文字列たちをつなぎ、区切り文字のとこでは dp の遷移をしないようにすると、
		各文字列の内側だけの何らかに注目できる、というのは典型っぽい

		debug() のしやすさを考えると、dpとかは Node 内部に持つほうがいい気がするなあ
		というわけでそういう実装にした、 Node の中身や debug() を適宜書き換える
	*/

	ll solveCF316G(int Q, V<int> L, V<int> R){
		string special;
		rep(i,Q+1) special += (char)('z'+1+i);

		ll res = 0;
		for(int v = sz-1; v>=0; v--){
			NP n = nodes[v];
            n -> dp = V<int>(Q+1,0);
			rep(t,Q+1){
				if(n -> hasNext(special[t])){
					n -> dp[t]++;					// #{v->terminal} ( = the # of appearance of this node in t)
				}
			}
			auto trans = n -> getAllTransitions();
			for(auto it: trans){
                if(!islower(it.fs)) continue;
				rep(t,Q+1) n->dp[t] += it.sc->dp[t];
			}
			if(v != 0 && n->dp[0]){
				bool valid = true;
				rep(t,Q){
					if( !(L[t]<=n->dp[t+1] && n->dp[t+1]<=R[t]) ) valid = false;
				}
				if(valid) res += n->getLongest() - n->getShortest() + 1;
			}
		}
//        debug();
		return res;
	}

	/*
		https://www.spoj.com/problems/LCS/
		longest common substring
		これも区切り文字系
	*/
	int getLongestLCS(){
		int res = 0;
//		debug();
		for(int v = sz-1; v>=0; v--){
			NP n = nodes[v];
			n -> reach = V<bool>(2,false);
			rep(t,2){
				if(n -> hasNext('0'+t)){
					n -> reach[t] = true;
				}
			}
			auto trans = n -> getAllTransitions();
			for(auto it: trans){
				if(!islower(it.fs)) continue;
				rep(t,2){
					if(it.sc->reach[t]) n->reach[t] = true;
				}
			}
			if(n->reach[0] && n->reach[1]){
				chmax(res,n->getLongest());
			}
		}
		return res;
	}
	
};

struct Timer{
	clock_t st;
	void start(){
		st = clock();
	}
	int ms(){
		return (clock()-st)*1000 / CLOCKS_PER_SEC;
	}
};

void test(string s){
	Timer timer;
	timer.start();

	SuffixAutomaton SA(s);

	V<string> substrs;
	int N = s.size();
	rep(i,N) for(int j=i;j<=N;j++){
		substrs.pb(s.substr(i,j-i));
	}
	sort(all(substrs));
	substrs.erase(unique(all(substrs)),substrs.end());
	int sz = SA.sz;
	VV<string> node2strs(sz);
	show(sz);
	SA.TopologicalSort();
	SA.debug();

	for(string t: substrs){
		int v = SA.where(t);
		assert(v != -1);
		node2strs[v].pb(t);
	}
	rep(v,sz){
		cerr << "-- v = " << v << " ----" << endl;
		for(string t: node2strs[v]) cerr << t << endl;
	}

	show(timer.ms());
}

int main(){
	// srand((unsigned)time(NULL));
	// for(int N: {1,10,100,1000,10000,100000,200000,500000,1000000}){
	// 	string s(N,'.');
	// 	rep(i,N) s[i] = 'a' + rand()%26;
	// 	test(s);
	// }

	// while(true){
	// 	string s;
	// 	cin>>s;
	// 	test(s);
	// }

	string s;
	int Q;
	cin>>s>>Q;
	V<string> t(Q);
	V<int> L(Q),R(Q);
	rep(i,Q){
		cin>>t[i];
		cin>>L[i]>>R[i];
	}
	string str = s;
	str += char('z'+1);
	rep(i,Q){
		str += t[i];
		str += char('z'+1+i);
	}
	SuffixAutomaton SA(str);
	cout << SA.solve(Q,L,R) << endl;
}