/*
SA-IS
O(長さN+文字種K)で、どうせ圧縮できるからO(N)
s[]に数字でもいいしcharでもいいし渡せばいい
sa_lcp.cppと同じように
sa[0]=Nになっている

charなら,
string s;
s.c_str()

lcpもO(N)

*/
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#define rep1(i,N) for(int i=1;i<=(int)N;i++)
#define pb push_back
using namespace std;
namespace SuffixArray{
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
//			printf("lcp[%d]=%d\n",isa[i]-1,h);
		}
	}
}
int main(){
	string s;
	int sa[100],lcp[100];
	cin>>s;
	int N=s.size();
	SuffixArray::SA(N,s.c_str(),sa,256);
	SuffixArray::LCP(N,s.c_str(),sa,lcp);
	rep(i,N+1) cout<<sa[i]<<" ";

}
