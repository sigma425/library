/*
	suffix array
	sa[i]= i番目に小さいsuffixがはじまるindex (sa[0]=N)
	_k,_Nはグローバルに使っている(compareを2引数にするため)

	RMQと使えば s中で最も左にtが出てくる場所 みたいなのもわかる(jag2014summerday4F)

	lcp[i]= len of common prefix of s[sa[i]..],s[sa[i+1]..]
	同様にRMQを使えば任意のsubstringのcommon prefixの長さがわかる
*/
const int MAX_N=;
int _k,_N,_rank[MAX_N+1],tmp[MAX_N+1],sa[MAX_N+1],lcp[MAX_N];
bool compare_sa(int i,int j){
	if(_rank[i]!=_rank[j]) return _rank[i]<_rank[j];
	else{
		int ri= i+_k<=_N ? _rank[i+_k] : -1;
		int rj= j+_k<=_N ? _rank[j+_k] : -1;
		return ri<rj;
	}
}
void make_sa(string s){		//(string s,int *sa)
	_N=s.length();
	rep(i,_N+1){
		sa[i]=i;
		_rank[i]= i<_N?s[i]:-1;
	}
	for(_k=1;_k<=_N;_k*=2){
		sort(sa,sa+_N+1,compare_sa);
		tmp[sa[0]]=0;
		rep1(i,_N){
			tmp[sa[i]]=tmp[sa[i-1]]+( compare_sa(sa[i-1],sa[i]) ? 1 : 0 );
		}
		rep(i,_N+1) _rank[i]=tmp[i];
	}
}
void make_lcp(string s){
	int N=s.length();
	rep(i,N+1) _rank[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	rep(i,N){
		int j=sa[_rank[i]-1];
		if(h>0) h--;
		for(;j+h<N&&i+h<N;h++){
			if(s[j+h]!=s[i+h]) break;
		}
		lcp[_rank[i]-1]=h;
	}
}
/*
	tがでてくるsaの区間[lo,hi)を計算する
	出てこない時はlo==hiになってる
*/
int lo(int *sa,string& s,string& t){
	int N=s.size()+1;
	int l=-1,r=N+1;
	while(r-l>1){
		int m=(r+l)/2;
		if(s.compare(sa[m],t.length(),t)<0) l=m;
		else r=m;
	}
	return r;
}
int hi(int *sa,string& s,string& t){
	int N=s.size()+1;
	int l=-1,r=N+1;
	while(r-l>1){
		int m=(r+l)/2;
		if(s.compare(sa[m],t.length(),t)<=0) l=m;
		else r=m;
	}
	return r;
}