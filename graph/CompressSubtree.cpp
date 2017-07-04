/*
	tree と vertex subset S が与えられたときに, 直接先祖関係で辺を張ったSを頂点集合とする木を返す

	Gでeulertourする
	vsをdfs順でsortする
	隣り合う二つのdfsをとる
	vsにこれらを加えたものをまたdfs順でsortする
	隣り合うx,yに対し, w = lca(x,y) として x-w と y-w の辺を張る

	codechef/snackdown/2017/final/universe.cpp
*/

LCA lca(Tr);
EulerTour euler(Tr);
auto comp = [&](int x,int y){return euler.in[x]<euler.in[y];};