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
