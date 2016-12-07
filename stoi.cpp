#include <sstream>
int To_int(string s){
	istringstream is(s);
	int ret;
	is>>ret;
	return ret;
}
string To_string(int a){
	ostringstream os;
	os << a;
	return os.str();
}