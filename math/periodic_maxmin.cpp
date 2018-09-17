/*
	a[i] = sin(2pi*i/N) みたいに、
	- 周期的であって
	- 適当な場所から見ると up down を一度する

	a という配列があって、それをクエリで取得できる時に、log回呼び出しでargmax,argminを特定する

	前提: 連続する二箇所で=になってはいけない

	例: 凸多角形の各頂点と直線との距離
	    凸多角形と点が与えられて、点からどの頂点達が見えるか(偏角)
*/
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define rep1(i,N) for(int i=1;i<=(int)(N);i++)
#define show(x) cout<<#x<<" = "<<x<<endl
#define all(c) c.begin(),c.end()
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define pb push_back
using namespace std;

D query(int i,int N){
	i%=N;
	//
}

template<class D>
int getArgmax(int N){
	if(N==1) return 0;

	D h = query(0);
	bool up = h < query(1);

	int lb = 0, ub = N;
	while(ub-lb>1){
		int m = (ub+lb)/2;
		if(query(m) < h){
			if(up) ub = m;
			else lb = m;
		}else{
			D a = query(m);
			D b = query(m+1);
			if(a<b) lb = m;
			else ub = m;
		}
	}
	return query(lb)<query(ub) ? ub : lb;
}

template<class D>
int getArgmin(int N){
	if(N==1) return 0;

	D h = query(0);
	bool up = h < query(1);

	int lb = 0, ub = N;
	while(ub-lb>1){
		int m = (ub+lb)/2;
		if(query(m) > h){
			if(up) lb = m;
			else ub = m;
		}else{
			D a = query(m);
			D b = query(m+1);
			if(a>b) lb = m;
			else ub = m;
		}
	}
	return query(lb)<query(ub) ? lb : ub;
}

