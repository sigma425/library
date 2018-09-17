/*
	R[i] = s[i] を中心とする最長回文の半径((len+1)/2)
	s:abaaababa
	R:121412321

 	偶数長も考えたいときは
	s:a$b$a$a$a$b$a$b$a

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
	while(i < N){
		while(i-j>=0 && i+j<N && s[i-j]==s[i+j]) ++j;
		R[i] = j;
		int k = 1;
		while(i-k>=0 && i+k<N && k+R[i-k]<j) R[i+k]=R[i-k],++k;
		i+=k,j-=k;
	}
	return R;
}