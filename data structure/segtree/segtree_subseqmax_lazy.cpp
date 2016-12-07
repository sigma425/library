/*

*/
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

struct segtree_lazy{
	struct Node{
		int mx,l,r,sum;
	};
	Node merge(Node& a,Node& b){
		Node ret;
		ret.sum=a.sum+b.sum;
		ret.l=max(a.l,a.sum+b.l);
		ret.r=max(b.r,b.sum+a.r);
		ret.mx=max(a.r+b.l,max(a.mx,b.mx));
		return ret;
	}
	int N;
	segtree_lazy(int n){

	}
	vector<Node> seg;
	vector<bool> same;
	vector<int> val;
	void dosame(int k,int v,int len){
		if(len==0) return;
		same[k]=1,val[k]=v;
		show(k);
		show(v);
		show(len);
		puts("");
		if(v>=0) seg[k].l=seg[k].r=seg[k].mx=seg[k].sum=v*len;
		else seg[k].l=seg[k].r=seg[k].mx=0,seg[k].sum=v*len;
	}
	Node calc(int a,int b,int l,int r,int k){
		if(r<=a||b<=l) return Node();
		if(a<=l&&r<=b) return seg[k];
		if(same[k]){
			dosame(k*2,val[k],(r-l)/2);
			dosame(k*2+1,val[k],(r-l)/2);
		}
		return merge(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));
	}
	Node calc(int a,int b){
		return calc(a,b,0,p2,1);
	}
	void change(int a,int b,int l,int r,int k,int v){
		if(r<=a||b<=l) return;
		if(a<=l&&r<=b){
			dosame(k,v,r-l);
			return;
		}
		if(same[k]){
			dosame(k*2,val[k],(r-l)/2);
			dosame(k*2+1,val[k],(r-l)/2);
		}
		same[k]=0;
		change(a,b,l,(l+r)/2,k*2,v);
		change(a,b,(l+r)/2,r,k*2+1,v);
		seg[k]=merge(seg[k*2],seg[k*2+1]);
	}
	void change(int a,int b,int v){
		change(a,b,0,p2,1,v);
	}
};
int main(){
	int N;
	cin>>N;
	segtree seg(N);
	int Q;
	cin>>Q;
	rep(i,Q){
		int t;
		cin>>t;
		if(t==0){
			int a,b,v;
			cin>>a>>b>>v;
			seg.change(a,b,v);
		}else{
			int a,b;
			cin>>a>>b;
			cout<<seg.calc(a,b).mx<<endl;
		}
	}
}
