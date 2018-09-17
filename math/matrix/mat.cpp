/*
O(n!) 一生使わないやろなあ
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP0(i,n) for(int i=0;i<(n);++i)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define ALL(c) (c).begin(),(c).end()
typedef vector< vector<double> > mat;
const double eps=1e-9;
mat pro(mat a,mat b,int n){
	mat p(n,vector<double>(n));
	REP0(i,n){
		REP0(j,n){
			p[i][j]=0;
			REP0(k,n){
				p[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return p;
}
double det(mat a,int n){
	double ret=0;
	vector<int> s;
	REP0(i,n) s.push_back(i);
	int cnt=0;
	do{
		double part=1-cnt*(cnt+1)%4;
		REP0(i,n) part*=a[i][s[i]];
		ret+=part;
		cnt++;
	}while(next_permutation(ALL(s)));
	return ret;
}
double cof(mat a,int n,int x,int y){		//cofactor
	mat b(n-1,vector<double>(n-1));
	int cntx=0;
	REP0(i,n-1){
		if(cntx==x) cntx++;
		int cnty=0;
		REP0(j,n-1){
			if(cnty==y) cnty++;
			b[i][j]=a[cntx][cnty];
			cnty++;
		}
		cntx++;
	}
	return det(b,n-1);
}
mat inv(mat a,int n){
	mat b(n,vector<double>(n));
	double dt=det(a,n);
	if(abs(dt)<eps){
		cout << "no inverse matrix" << endl;
		//dousiyou
		return a;
	}
	REP0(i,n){
		REP0(j,n){
			b[j][i]=cof(a,n,i,j)/dt;
			if((i+j)%2) b[j][i]*=-1;
		}
	}
	return b;
}
int main(){
	int n;
	cin >> n;
	mat a(n,vector<double>(n));
	REP0(i,n){
		REP0(j,n){
			int p;
			cin >> a[i][j];
		}
	}
	mat b=inv(a,n);
	REP0(i,n){
		REP0(j,n){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}