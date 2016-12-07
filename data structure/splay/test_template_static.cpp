#include <bits/stdc++.h>
using namespace std;
/*	OK
template<class T>
struct A{
	static int i;
	T x;
};
template<> int A<int>::i=0;
*/
/*	OK
template<class T>
struct A{
	static int i;
	T x;
};
template<class T> int A<T>::i=0;
*/
template<class T>
struct A{
	struct Ta{
		T t;
		Ta(){}
	};
	static Ta x;
};
template<class T> typename A<T>::Ta A<T>::x=Ta();

int main(){
	cout << A<int>::x.t <<endl;
}
