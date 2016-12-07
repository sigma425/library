/*
	Binary Indexed Tree
	1次元
	kthはまだ手元で試しただけ
*/
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
struct BIT{
	int N;
	vector<int> bit;
	BIT(int n){		//nは区間幅!!!
		N=n;
		bit.resize(n+1);
	}
	BIT(){}
	void init(int n){
		N=n;
		bit.resize(n+1);
	}
	int sum(int i){		//i個の和a[0]+..a[i-1]
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	int val(int i){	//return a[i]	(0-ind)
		return sum(i+1)-sum(i);
	}
	void add(int i,int x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
	void assign(int i,int x){	//a[i]=x
		add(i,x-val(i));
	}
	/*
	!!!a[i] SHOULD be non-negative!!!
	return min i s.t. sum(i+1)>=s
	a[0]+..a[i] >= s なる最小のiを返す
	s=0 なら-1を返す

	a[i]=1 or 0の時は,s番目(1-INDEXED)が何かを返す(0-indexed) 
	e.g
	a:0 1 1 0 1
	kth(0)=-1,kth(1)=1,kth(2)=2,kth(3)=4,kth(4>=)=5


	*/
	int kth(int s){
		if(s==0) return -1;
		int p=1;
		while(p<=N) p<<=1;
		p>>=1;
		int i=0;
		while(p){
			if(i+p<=N&&s>bit[i+p]) s-=bit[i+p],i|=p;
			p>>=1;
		}
		return i;
	}
}bit;
int main(){
	int N;
	cin>>N;
	BIT bit(N);
	while(true){
		char c;
		cin>>c;
		if(c=='a'){
			int i,x;
			cin>>i>>x;
			bit.assign(i,x);
		}
		if(c=='k'){
			int k;
			cin>>k;
			cout<<"kth="<<bit.kth(k)<<endl;
		}
		cout<<"vals=";
		rep(i,N) cout<<bit.val(i)<<" ";
		puts("");
	}

}