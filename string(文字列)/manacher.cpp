/*
R[i]:the radius of longest palindrome which of center is S[i]
S:abaaababa
R:121412321
if you want to get even length too, insert dummy like this:
S:a$b$a$a$a$b$a$b$a

文字列じゃないものに使うとき,1文字を回分とみなしてはいけない場合もある
その場合は
R[i]=j;
if(R[i]==0){
	i++,j=0;
	continue;
}
でOK

*/
vector<int> manacher(string s){
	int N = s.size();
	vector<int> R(N);
	int i=0,j=0;
	while(i<s.size()){
		while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j]) ++j;
		R[i]=j;
		int k=1;
		while(i-k>=0&&i+k<s.size()&&k+R[i-k]<j) R[i+k]=R[i-k],++k;
		i+=k,j-=k;
	}
	return R;
}