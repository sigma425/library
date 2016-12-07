/*
string s
A[i]="s[0,i-1] suffix & prefix max matching"
S : aabaabaaa
A : _010123452
*/
string s;
int A[];
A[0]=-1;
int j=-1;
rep(i,s.size()){
	while(j>=0&&s[i]!=s[j]) j=A[j];
	j++;
	A[i+1]=j;
}