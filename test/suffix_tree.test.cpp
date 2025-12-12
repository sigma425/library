#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template.hpp"
#include "string/suffix_array.hpp"
#include "string/suffix_tree.hpp"

void test(){
	string s = "aabbabbaa";
	SuffixArray SA(s);
	SuffixTree ST(SA);
	ST.debug(s);
}

int main(){
	test();
}