/*
Z-algorithm
the longest length of prefix of S and S[i~]
S:aaabaaaab
A:921034210
*/
calcZ(){
	A[0]=s.size();
	int i=1,j=0;
	while(i<s.size()){
		while(i+j<s.size()&&s[j]==s[i+j]) ++j;
		A[i]=j;
		if(j==0){
			++i;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+A[k]<j) A[i+k]=A[k],++k;
		i+=k,j-=k;
	}
}
/*
you can calc pfx of s[i~] and T
*/
calc(string s,string t){
	calcZ(t+"$"+s);
}