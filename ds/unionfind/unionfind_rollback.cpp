/*	
	int w = snapshot() O(1) をとっとくと、rollback(w) でその時点に戻る
	weighted union rule O(log N) なのでならし計算量じゃない、から、大丈夫

	p: par (root では -1)
	s: sz
	c: # component

	double mn とか持ちたかったら・・・　どうしようね
	any は面倒そうなので
	buf は pair<int*,int> なので、
	もういっそのことすべてをdoubleで管理とかかな
	
	verify: https://codeforces.com/contest/891/problem/C
*/

struct UnionFindRollback{
	V<int> p,s;
	int c;
	UnionFindRollback(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:find(p[a]);
	}
	V<pair<int*,int>> buf;
	void save(int& a){
		buf.emplace_back(&a,a);
	}
	int snapshot(){
		return si(buf);
	}
	void rollback(int w){
		while(si(buf)>w){
			int*a,b;tie(a,b)=buf.back();buf.pop_back();
			*a=b;
		}
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		if(s[a]<s[b])swap(a,b);
		save(p[b]);
		save(s[a]);
		save(c);
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};