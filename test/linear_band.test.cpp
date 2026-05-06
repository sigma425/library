#include "template.hpp"
#include "math/matrix/linear.cpp"
#include "math/mint.hpp"

int main(){
	{
		BandMatrix<mint> a(4,5,1);
		a[0][1] = 3;
		a[1][1] = 4;
		a[2][1] = 5;
		assert(mint(a[0][1]) == mint(3));
		assert(mint(a[1][1]) == mint(4));
		assert(mint(a[2][1]) == mint(5));
		assert(mint(a[0][3]) == mint(0));
		assert(mint(a[3][0]) == mint(0));
	}
	mt19937 rng(0);
	for(int h=0;h<=16;h++){
		for(int w=0;w<=16;w++){
			if(h == 0 && w == 0) continue;
			for(int width=0;width<=max(h,w);width++){
				rep(_,200){
					BandMatrix<mint> a(h,w,width);
					vector<vector<mint>> dense(h,vector<mint>(w));
					rep(i,h){
						for(int j=max(0,i-width);j<=min(w-1,i+width);j++){
							mint v = rng()%5;
							a[i][j] = v;
							dense[i][j] = v;
						}
					}
					vector<mint> b(h);
					rep(i,h) b[i] = rng()%5;

					auto ans_dense = linearEquation(dense,w,b);
					auto band = linearEquation(a,b);
					auto band2 = linearEquation_band(a,b);
					assert(band == band2);
					if(ans_dense.empty() != band.empty()){
						cerr << "exist h=" << h << " w=" << w << " width=" << width << endl;
						rep(ii,h){
							rep(jj,w) cerr << dense[ii][jj] << " ";
							cerr << "| " << b[ii] << endl;
						}
					}
					assert(ans_dense.empty() == band.empty());
					if(band.empty()) continue;

					rep(i,h){
						mint s = 0;
						rep(j,w) s += dense[i][j] * band[j];
						if(!(s == b[i])){
							cerr << "h=" << h << " w=" << w << " width=" << width << endl;
							rep(ii,h){
								rep(jj,w) cerr << dense[ii][jj] << " ";
								cerr << "| " << b[ii] << endl;
							}
							cerr << "x:";
							for(auto v:band) cerr << " " << v;
							cerr << endl;
						}
						assert(s == b[i]);
					}
				}
			}
		}
	}
}
