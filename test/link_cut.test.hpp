#include "template.hpp"
#include "ds/splay/link_cut.hpp"

int main(){
	LinkCutTree<string, [](string a, string b){ return a+b; }, [](string x){ reverse(all(x)); return x;}, false> lct;
	
}