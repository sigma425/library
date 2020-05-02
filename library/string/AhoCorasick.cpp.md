---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/AhoCorasick.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/AhoCorasick.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-01 15:15:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	Aho-Corasick
	複数文字列の trie + failure link

	build(p) : O(|p0| + |p1| + ..)

	match(s,op) : O(|s| + マッチ回数 * opのコスト)

		マッチ回数 :
			パターン文字列が
				suffix free(葉にしかmatchedがない) : 1
				distinct : O(sqrt(|s|))
				"a" がいっぱい → クビ

			マッチ回数かけたくないなら、「このノードに来たときにマッチする集合」 ( <=> skipで辿れるノード)
			に対する答えの和とかを持てばいい、総出現回数とかならできる、各パターンごとに・・・だときつい

		r昇順 (r一緒ならlength降順) に op(string_id,r) が呼ばれる

	V<string> p(N);
	auto AC = Aho::build(p);

	V<mint> dp(s.size()+1);
	dp[0] = 1;
	AC -> match(s,[&](int id,int r){
		int l = r - (int)p[id].size();
		dp[r] += dp[l];
	});

	verified at: RUPC2018-day3 G
				 JSC2019-final E

*/
struct Aho{
	using NP = Aho*;
	map<char,NP> nx;
	NP fail = nullptr, skip = nullptr;
	V<int> matched;		//string ids for this node

	void add(const string& s, int id, int i = 0){
		if(i == (int)s.size()){
			matched.pb(id);
			return;
		}
		if(nx[s[i]] == nullptr){
			nx[s[i]] = new Aho();
		}
		nx[s[i]] -> add(s,id,i+1);
	}
	template<class OP> NP count(OP op, int r){
		if(fail == nullptr) return this;	//root now
		for(int id: matched){
			op(id,r);
		}
		if(skip){
			skip -> count(op,r);
		}else{
			skip = fail -> count(op,r);
		}
		return matched.empty() ? skip : this;
	}

	template<class OP> void match(const string& s, OP op, int i = 0){
		if(i == (int)s.size()) return;
		if(nx.count(s[i]) && nx[s[i]] != nullptr){
			nx[s[i]] -> count(op,i+1);
			nx[s[i]] -> match(s,op,i+1);
		}else{
			if(fail == nullptr){	//root now
				match(s,op,i+1);
			}else{
				fail -> match(s,op,i);
			}
		}
	}

	static NP build(V<string> ss){
		NP r = new Aho();
		rep(i,ss.size()){
			r -> add(ss[i],i);
		}
		queue<NP> que;
		que.push(r);
		assert(r -> fail == nullptr);
		while(!que.empty()){
			NP v = que.front(); que.pop();
			for(auto e: v->nx){
				auto c = e.fs;
				NP u = e.sc;
				NP fail = v -> fail;
				while(fail != nullptr && !fail->nx.count(c)){
					fail = fail -> fail;
				}
				u -> fail = (fail == nullptr) ? r : fail -> nx[c];
				que.push(u);
			}
		}
		return r;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/AhoCorasick.cpp"
/*
	Aho-Corasick
	複数文字列の trie + failure link

	build(p) : O(|p0| + |p1| + ..)

	match(s,op) : O(|s| + マッチ回数 * opのコスト)

		マッチ回数 :
			パターン文字列が
				suffix free(葉にしかmatchedがない) : 1
				distinct : O(sqrt(|s|))
				"a" がいっぱい → クビ

			マッチ回数かけたくないなら、「このノードに来たときにマッチする集合」 ( <=> skipで辿れるノード)
			に対する答えの和とかを持てばいい、総出現回数とかならできる、各パターンごとに・・・だときつい

		r昇順 (r一緒ならlength降順) に op(string_id,r) が呼ばれる

	V<string> p(N);
	auto AC = Aho::build(p);

	V<mint> dp(s.size()+1);
	dp[0] = 1;
	AC -> match(s,[&](int id,int r){
		int l = r - (int)p[id].size();
		dp[r] += dp[l];
	});

	verified at: RUPC2018-day3 G
				 JSC2019-final E

*/
struct Aho{
	using NP = Aho*;
	map<char,NP> nx;
	NP fail = nullptr, skip = nullptr;
	V<int> matched;		//string ids for this node

	void add(const string& s, int id, int i = 0){
		if(i == (int)s.size()){
			matched.pb(id);
			return;
		}
		if(nx[s[i]] == nullptr){
			nx[s[i]] = new Aho();
		}
		nx[s[i]] -> add(s,id,i+1);
	}
	template<class OP> NP count(OP op, int r){
		if(fail == nullptr) return this;	//root now
		for(int id: matched){
			op(id,r);
		}
		if(skip){
			skip -> count(op,r);
		}else{
			skip = fail -> count(op,r);
		}
		return matched.empty() ? skip : this;
	}

	template<class OP> void match(const string& s, OP op, int i = 0){
		if(i == (int)s.size()) return;
		if(nx.count(s[i]) && nx[s[i]] != nullptr){
			nx[s[i]] -> count(op,i+1);
			nx[s[i]] -> match(s,op,i+1);
		}else{
			if(fail == nullptr){	//root now
				match(s,op,i+1);
			}else{
				fail -> match(s,op,i);
			}
		}
	}

	static NP build(V<string> ss){
		NP r = new Aho();
		rep(i,ss.size()){
			r -> add(ss[i],i);
		}
		queue<NP> que;
		que.push(r);
		assert(r -> fail == nullptr);
		while(!que.empty()){
			NP v = que.front(); que.pop();
			for(auto e: v->nx){
				auto c = e.fs;
				NP u = e.sc;
				NP fail = v -> fail;
				while(fail != nullptr && !fail->nx.count(c)){
					fail = fail -> fail;
				}
				u -> fail = (fail == nullptr) ? r : fail -> nx[c];
				que.push(u);
			}
		}
		return r;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

