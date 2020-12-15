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


# :warning: string/PalindromicTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/PalindromicTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
struct PalindromicTree{
	static const int Z = 26;
	struct Node{
		vector<int> next;
		int len;
		int suflink;
		string s;
		Node(vector<int> next,int len,int suflink):next(next),len(len),suflink(suflink){}
		// have string for debug
		Node(vector<int> next,int len,int suflink,string s):next(next),len(len),suflink(suflink),s(s){}
	};
	int V;
	vector<Node> ns;

	PalindromicTree(){}
	PalindromicTree(string s){
		V = 2;	// ns[0]: len -1    ns[1]: len 0
		int suf = 1;
		ns.pb( Node(vector<int>(Z,-1),-1,0,"-1") );
		ns.pb( Node(vector<int>(Z,-1), 0,0,"") );

		int N = s.size();
		rep(i,N){
			show(i);
			int c = s[i] - 'a';
			while(true){
				int len = ns[suf].len;
				if(i-1-len>=0 && s[i-1-len] == s[i]){
					break;
				}
				suf = ns[suf].suflink;
			}

			if(ns[suf].next[c] == -1){
				V++;
				ns[suf].next[c] = V-1;
				
				vector<int> nnext(Z,-1);
				int nlen = ns[suf].len+2;
				int nsuflink = -1;
				show(suf);
				show(nlen);
				if(nlen == 1){
					nsuflink = 1;
				}else{
					while(true){
						suf = ns[suf].suflink;
						int len = ns[suf].len;
						if(i-1-len>=0 && s[i-1-len] == s[i]){
							break;
						}
					}
					nsuflink = ns[suf].next[c];
				}

				Node n(nnext,nlen,nsuflink,s.substr(i+1-nlen,nlen));
				ns.pb(n);
				suf = V-1;
			}else{
				suf = ns[suf].next[c];
			}
		}

	}
};
int main(){
	while(true){
		string s;
		cin>>s;
		PalindromicTree PTree(s);
		int V = PTree.V;
		show(V);
		rep(i,V){
			show(PTree.ns[i].s);
		}
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/PalindromicTree.cpp"
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
struct PalindromicTree{
	static const int Z = 26;
	struct Node{
		vector<int> next;
		int len;
		int suflink;
		string s;
		Node(vector<int> next,int len,int suflink):next(next),len(len),suflink(suflink){}
		// have string for debug
		Node(vector<int> next,int len,int suflink,string s):next(next),len(len),suflink(suflink),s(s){}
	};
	int V;
	vector<Node> ns;

	PalindromicTree(){}
	PalindromicTree(string s){
		V = 2;	// ns[0]: len -1    ns[1]: len 0
		int suf = 1;
		ns.pb( Node(vector<int>(Z,-1),-1,0,"-1") );
		ns.pb( Node(vector<int>(Z,-1), 0,0,"") );

		int N = s.size();
		rep(i,N){
			show(i);
			int c = s[i] - 'a';
			while(true){
				int len = ns[suf].len;
				if(i-1-len>=0 && s[i-1-len] == s[i]){
					break;
				}
				suf = ns[suf].suflink;
			}

			if(ns[suf].next[c] == -1){
				V++;
				ns[suf].next[c] = V-1;
				
				vector<int> nnext(Z,-1);
				int nlen = ns[suf].len+2;
				int nsuflink = -1;
				show(suf);
				show(nlen);
				if(nlen == 1){
					nsuflink = 1;
				}else{
					while(true){
						suf = ns[suf].suflink;
						int len = ns[suf].len;
						if(i-1-len>=0 && s[i-1-len] == s[i]){
							break;
						}
					}
					nsuflink = ns[suf].next[c];
				}

				Node n(nnext,nlen,nsuflink,s.substr(i+1-nlen,nlen));
				ns.pb(n);
				suf = V-1;
			}else{
				suf = ns[suf].next[c];
			}
		}

	}
};
int main(){
	while(true){
		string s;
		cin>>s;
		PalindromicTree PTree(s);
		int V = PTree.V;
		show(V);
		rep(i,V){
			show(PTree.ns[i].s);
		}
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

