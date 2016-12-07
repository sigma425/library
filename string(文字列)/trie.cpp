string s;
rep(i,s.size()){
	int x=s[i]-'a';
	if(d[v][x]==-1){
		d[v][x]=d.size();
		d.pb(vi(26,-1));
	}
	v=d[v][x];
}