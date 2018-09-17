/*
無理そう
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define REP0(i,n) for(int i=0;i<(n);++i)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define ALL(c) (c).begin(),(c).end()
const double eps=1e-9;
class Mat{
	public:
		Mat(int n);
/*		Mat(int m,int n);
		Mat operator+(const Mat& obj);
		Mat& operator+=(const Mat& obj);
		Mat operator-(const Mat& obj);
		Mat& operator-=(const Mat& obj);
		Mat operator*(const Mat& obj);
		Mat& operator*=(const Mat& obj);
*/
		vector< vector<double> > mat;

};
Mat::Mat(int n){
	vector< vector<double> > mat(n,vector<double>(n));
}
int main(){
	Mat x(4);
	cout << x.mat[2][3];
	return 0;
}