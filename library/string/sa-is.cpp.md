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


# :heavy_check_mark: string/sa-is.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/sa-is.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-11 10:51:45+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test_oj/sa-is.test.cpp.html">test_oj/sa-is.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	SA-IS + LCP

	SuffixArray SA(V<int,ll>) もしくは SA(string)
	でSA.sa,isa,lcpに入る

	[0,N]   sa[i] = i番目に小さいものは s[ sa[i],N ) なので sa[0] = N
	[0,N]   isa[i] = s[i,N) が何番目にいるか
	[0,N-1] lcp[i] = s[ sa[i],N ) と s[ sa[i+1],N ) のlcp lcp[0] = 0
	任意のprefix同士のlcpがsegtree_minで求まる
	あるsubstringが何回出てくるか? とか

	s = abcabac

		(eps)
		abac
		abcabac
		ac
		bac
		bcabac
		c
		cabac
*/

struct SuffixArray{
	V<int> sa;
	V<int> isa;
	V<int> lcp;

	template<class T>
	SuffixArray(const vector<T>& s){	//int,ll
		int N = s.size();
		T s_arr[N];
		rep(i,N) s_arr[i] = s[i];
		int sa_arr[N+1];
		int lcp_arr[N];
		{	//zaatsu
			V<T> vs = s;
			sort(all(vs));
			vs.erase(unique(all(vs)),vs.end());
			rep(i,N) s_arr[i] = lower_bound(all(vs),s[i]) - vs.begin();
		}
		int K = N;
		SA(N,s_arr,sa_arr,K);
		LCP(N,s_arr,sa_arr,lcp_arr);
		sa = V<int>(sa_arr,sa_arr+(N+1));
		isa.resize(N+1);
		rep(i,N+1) isa[sa[i]] = i;
		lcp = V<int>(lcp_arr,lcp_arr+N);
	}
	SuffixArray(const string& s){
		int N = s.size();
		char s_arr[N];
		rep(i,N) s_arr[i] = s[i];
		int sa_arr[N+1];
		int lcp_arr[N];
		SA(N,s_arr,sa_arr,256);
		LCP(N,s_arr,sa_arr,lcp_arr);
		sa = V<int>(sa_arr,sa_arr+(N+1));
		isa.resize(N+1);
		rep(i,N+1) isa[sa[i]] = i;
		lcp = V<int>(lcp_arr,lcp_arr+N);
	}

	private:

	template<class T>
	void induce(int N,const T s[],bool is[],int sa[],int lbase[],int K){
		int it[K+1];
		copy_n(lbase,K+1,it);
		rep(i,N+1){
			if(sa[i]>=1&&!is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[it[c]++]=sa[i]-1;
			}
		}
		copy_n(lbase,K+1,it);
		for(int i=N;i>0;i--){
			if(sa[i]>=1&&is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[--it[c+1]]=sa[i]-1;
			}
		}
	}
	template<class T>
	void SA(int N,const T s[],int sa[],int K){
		bool is[N+1];		//stype?
		int lcnt[K+1]={},scnt[K+1]={};
		is[N]=1;
		for(int i=N-1;i>=0;i--){
			if(i==N-1||s[i]>s[i+1]) is[i]=0;
			else if(s[i]<s[i+1]) is[i]=1;
			else is[i]=is[i+1];
			if(!is[i]) lcnt[(int)s[i]]++;
			else scnt[(int)s[i]]++;
		}
		vector<int> v;		//LMSs
		int lms[N+1];
		fill_n(lms,N+1,-1);
		int c=0;
		rep1(i,N-1){
			if(!is[i-1]&&is[i]){
				lms[i]=c++;
				v.pb(i);
			}
		}
		int lbase[K+1],sbase[K+1];
		lbase[0]=1,sbase[0]=1+lcnt[0];
		rep1(i,K){
			lbase[i]=sbase[i-1]+scnt[i-1];
			sbase[i]=lbase[i]+lcnt[i];
		}
		if(!v.empty()){
			vector<int> v2=v;
			int it[K+1];			//iterate
			copy_n(sbase,K+1,it);
			fill_n(sa,N+1,-1);
			sa[0]=N;
			rep(i,v.size()){
				int c=s[v[i]];
				sa[it[c]++]=v[i];
			}
			induce(N,s,is,sa,lbase,K);
			int c=0;
			rep1(i,N) if(lms[sa[i]]>=0) v[c++]=sa[i];
			int s2[v.size()],sa2[v.size()+1];
			c=0;
			s2[lms[v[0]]]=0;
			for(int i=1;i<(int)v.size();i++){
				int l=v[i-1],r=v[i];
				while(true){
					if(s[l]!=s[r]){
						c++;
						break;
					}
					l++,r++;
					if(lms[l]>=0||lms[r]>=0){
						if(lms[l]<0||lms[r]<0) c++;
						break;
					}
				}
				s2[lms[v[i]]]=c;
			}
			SA(v.size(),s2,sa2,c);
			rep1(i,v.size()) v[i-1]=v2[sa2[i]];
		}
		int it[K+1];
		copy_n(sbase,K+1,it);
		fill_n(sa,N+1,-1);
		sa[0]=N;
		rep(i,v.size()){
			int c=s[v[i]];
			sa[it[c]++]=v[i];
		}
		induce(N,s,is,sa,lbase,K);
	}
	template<class T>
	void LCP(int N,const T s[],const int sa[],int lcp[]){
		int isa[N+1];
		rep(i,N+1) isa[sa[i]]=i;
		int h=0;
		rep(i,N){
			int j=sa[isa[i]-1];
			if(h>0) h--;
			for(;j+h<N&&i+h<N;h++){
				if(s[j+h]!=s[i+h]) break;
			}
			lcp[isa[i]-1]=h;
		}
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/sa-is.cpp"
/*
	SA-IS + LCP

	SuffixArray SA(V<int,ll>) もしくは SA(string)
	でSA.sa,isa,lcpに入る

	[0,N]   sa[i] = i番目に小さいものは s[ sa[i],N ) なので sa[0] = N
	[0,N]   isa[i] = s[i,N) が何番目にいるか
	[0,N-1] lcp[i] = s[ sa[i],N ) と s[ sa[i+1],N ) のlcp lcp[0] = 0
	任意のprefix同士のlcpがsegtree_minで求まる
	あるsubstringが何回出てくるか? とか

	s = abcabac

		(eps)
		abac
		abcabac
		ac
		bac
		bcabac
		c
		cabac
*/

struct SuffixArray{
	V<int> sa;
	V<int> isa;
	V<int> lcp;

	template<class T>
	SuffixArray(const vector<T>& s){	//int,ll
		int N = s.size();
		T s_arr[N];
		rep(i,N) s_arr[i] = s[i];
		int sa_arr[N+1];
		int lcp_arr[N];
		{	//zaatsu
			V<T> vs = s;
			sort(all(vs));
			vs.erase(unique(all(vs)),vs.end());
			rep(i,N) s_arr[i] = lower_bound(all(vs),s[i]) - vs.begin();
		}
		int K = N;
		SA(N,s_arr,sa_arr,K);
		LCP(N,s_arr,sa_arr,lcp_arr);
		sa = V<int>(sa_arr,sa_arr+(N+1));
		isa.resize(N+1);
		rep(i,N+1) isa[sa[i]] = i;
		lcp = V<int>(lcp_arr,lcp_arr+N);
	}
	SuffixArray(const string& s){
		int N = s.size();
		char s_arr[N];
		rep(i,N) s_arr[i] = s[i];
		int sa_arr[N+1];
		int lcp_arr[N];
		SA(N,s_arr,sa_arr,256);
		LCP(N,s_arr,sa_arr,lcp_arr);
		sa = V<int>(sa_arr,sa_arr+(N+1));
		isa.resize(N+1);
		rep(i,N+1) isa[sa[i]] = i;
		lcp = V<int>(lcp_arr,lcp_arr+N);
	}

	private:

	template<class T>
	void induce(int N,const T s[],bool is[],int sa[],int lbase[],int K){
		int it[K+1];
		copy_n(lbase,K+1,it);
		rep(i,N+1){
			if(sa[i]>=1&&!is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[it[c]++]=sa[i]-1;
			}
		}
		copy_n(lbase,K+1,it);
		for(int i=N;i>0;i--){
			if(sa[i]>=1&&is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[--it[c+1]]=sa[i]-1;
			}
		}
	}
	template<class T>
	void SA(int N,const T s[],int sa[],int K){
		bool is[N+1];		//stype?
		int lcnt[K+1]={},scnt[K+1]={};
		is[N]=1;
		for(int i=N-1;i>=0;i--){
			if(i==N-1||s[i]>s[i+1]) is[i]=0;
			else if(s[i]<s[i+1]) is[i]=1;
			else is[i]=is[i+1];
			if(!is[i]) lcnt[(int)s[i]]++;
			else scnt[(int)s[i]]++;
		}
		vector<int> v;		//LMSs
		int lms[N+1];
		fill_n(lms,N+1,-1);
		int c=0;
		rep1(i,N-1){
			if(!is[i-1]&&is[i]){
				lms[i]=c++;
				v.pb(i);
			}
		}
		int lbase[K+1],sbase[K+1];
		lbase[0]=1,sbase[0]=1+lcnt[0];
		rep1(i,K){
			lbase[i]=sbase[i-1]+scnt[i-1];
			sbase[i]=lbase[i]+lcnt[i];
		}
		if(!v.empty()){
			vector<int> v2=v;
			int it[K+1];			//iterate
			copy_n(sbase,K+1,it);
			fill_n(sa,N+1,-1);
			sa[0]=N;
			rep(i,v.size()){
				int c=s[v[i]];
				sa[it[c]++]=v[i];
			}
			induce(N,s,is,sa,lbase,K);
			int c=0;
			rep1(i,N) if(lms[sa[i]]>=0) v[c++]=sa[i];
			int s2[v.size()],sa2[v.size()+1];
			c=0;
			s2[lms[v[0]]]=0;
			for(int i=1;i<(int)v.size();i++){
				int l=v[i-1],r=v[i];
				while(true){
					if(s[l]!=s[r]){
						c++;
						break;
					}
					l++,r++;
					if(lms[l]>=0||lms[r]>=0){
						if(lms[l]<0||lms[r]<0) c++;
						break;
					}
				}
				s2[lms[v[i]]]=c;
			}
			SA(v.size(),s2,sa2,c);
			rep1(i,v.size()) v[i-1]=v2[sa2[i]];
		}
		int it[K+1];
		copy_n(sbase,K+1,it);
		fill_n(sa,N+1,-1);
		sa[0]=N;
		rep(i,v.size()){
			int c=s[v[i]];
			sa[it[c]++]=v[i];
		}
		induce(N,s,is,sa,lbase,K);
	}
	template<class T>
	void LCP(int N,const T s[],const int sa[],int lcp[]){
		int isa[N+1];
		rep(i,N+1) isa[sa[i]]=i;
		int h=0;
		rep(i,N){
			int j=sa[isa[i]-1];
			if(h>0) h--;
			for(;j+h<N&&i+h<N;h++){
				if(s[j+h]!=s[i+h]) break;
			}
			lcp[isa[i]-1]=h;
		}
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

