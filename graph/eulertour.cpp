/*
	eulertour
	コードですぐわかると思うけど,inで+,outで-
	idが頂点番号,inが+かどうか
	「操作の逆元がある場合のみ」使える
	よくあるのがsegtree,lcaとの組み合わせで,木上のpathに足し合わせとかsumとかができる.
	w=lca(a,b)として,2つのpathにわける.wa,wb,をやったあとwwを引くのも手.
	更新は add(v2id[w][0],v2id[a][0]+1,*) の形 +1に注意
	クエリも同様なんだけど,点クエリが勘違いしやすくて,ちゃんとval(v2id[v][0])-val(v2id[v][1]) と差分を取ること.

	subtreeに対してhoge,みたいなのは出来ないと思う
	
	verified by https://www.codechef.com/LTIME37/problems/TRAVTREE
*/
int I;
int id[MAX_V*2];
bool in[MAX_V*2];
int v2id[MAX_V][2];	//[0]:in [1]:out
void eulertour(int v,int p){
	id[I]=v,in[I]=1,v2id[v][0]=I,I++;
	for(int u:G[v]) if(u!=p) eulertour(u,v);
	id[I]=v,in[I]=0,v2id[v][1]=I,I++;
}