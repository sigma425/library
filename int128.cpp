using Int = __int128;
istream& operator>>(istream& i, Int& x){
	x=0;
	string s;
	i>>s;
	int N=s.size(),it=0;
	if(s[0]=='-') it++;
	for(;it<N;it++) x=(x*10+s[it]-'0');
	if(s[0]=='-') x=-x;
	return i;
}
ostream& operator<<(ostream& o, const Int& x){
	Int tmp=x;
	if(tmp==0) return o<<0;
	if(tmp<0) o<<'-',tmp=-tmp;
	vector<int> ds;
	while(tmp) ds.pb(tmp%10),tmp/=10;
	reverse(all(ds));
	for(int d:ds) o<<d;
	return o;
}
