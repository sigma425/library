/*
	Z-algorithm
	the longest common prefix of S and S[i~]
	s: aaabaaaab
	Z: 921034210

    s[i~] と t の common prefix も t+"$"+s に対して呼べば求まる
*/
vector<int> Zalgo(string s){
	int N = s.size();
	vector<int> Z(N);
	Z[0] = N;
	int i = 1, j = 0;
	while(i<N){
		while(i+j<N && s[j]==s[i+j]) ++j;
		Z[i] = j;
		if(j==0){
			++i;
			continue;
		}
		int k = 1;
		while(i+k<N && k+Z[k]<j) Z[i+k]=Z[k],++k;
		i += k, j -= k;
	}
	return Z;
}
