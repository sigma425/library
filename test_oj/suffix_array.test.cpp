#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "template.hpp"
#include "string/suffix_array.hpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
    string s;
    cin >> s;
    int n = s.size();
    SuffixArray sa(s);

    for (int i = 1; i <= n; i++) {
        cout << sa.sa[i] << " ";
    }
    cout << endl;
}
