const bool submit = 1;
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) if(!submit) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

struct Timer{
	clock_t st;
	void start(){
		st = clock();
	}
	int ms(){
		return (clock()-st)*1000 / CLOCKS_PER_SEC;
	}
}timer;

using D = double;	//2^V -> D
double eps = 1e-9;
int inf = 1e9;
int sign(double x){
	if(abs(x)<eps) return 0;
	if(x>0) return 1;
	else return -1;
}

vector<double> operator+(const vector<double>& l,const vector<double>& r){
	int N = l.size();
	vector<double> res(N,0);
	rep(i,N) res[i] = l[i]+r[i];
	return res;
}

vector<double> operator*(const vector<double>& v, double c){
	int N = v.size();
	vector<double> res(N,0);
	rep(i,N) res[i] = v[i] * c;
	return res;
}

int N;
D f0;

D f(vector<bool> is){
	int w[7]={1,2,1000,40,3,12,100};
	vector< vector<bool> > mat = {
		{0,1,0,1,1,1,0},
		{0,1,1,0,1,0,1},
		{1,0,1,1,0,0,0},
		{1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1},
		{1,1,0,0,1,0,1},
		{0,0,0,0,1,1,0}
	};
	int K = mat[0].size();
	D q = 0;
	vector<bool> covered(K,0);
	rep(i,N) if(is[i]){
		rep(j,K) if(mat[i][j]) covered[j] = 1;
		q++;
	}
	D res = 0;
	rep(j,K) if(covered[j]) res+=w[j];
	return res+q*(N-q)-100*q;
}

D f_norm(vector<bool> is){
	return f(is) - f0;
}

using Order = vector<int>;	//size N

Order calc_ord_su_withid(Order ord,int sid,int uid){
	rotate(ord.begin()+sid,ord.begin()+uid,ord.begin()+uid+1);
	return ord;
}

D f_minus_b(vector<bool> is, vector<double> b){
	D res = f_norm(is);
	rep(i,N) if(is[i]) res -= b[i];
	return res;
}
vector<double> calc_b(Order ord){
	vector<bool> is(N,false);
	vector<double> acc(N+1,0);
	rep(i,N){
		int v = ord[i];
		is[v] = 1;
		acc[i+1] = f_norm(is);
	}
	vector<double> res(N,0);
	rep(i,N) res[ord[i]] = acc[i+1] - acc[i];
	return res;
}
vector<double> get_b_norm(Order ord, Order base){	//access with v
	vector<bool> is(N,false);
	vector<double> acc(N+1,0);
	vector<double> b = calc_b(base);
	show(b);
	rep(i,N){
		int v = ord[i];
		is[v] = 1;
		acc[i+1] = f_minus_b(is,b);
	}
	vector<double> res(N,0);
	rep(i,N) res[ord[i]] = acc[i+1] - acc[i];
	rep(i,N) if(sign(res[i])==0) res[i] = 0;
	return res;
}
struct Convex_comb{
	vector<Order> b;	//K
	vector<double> c;	//K
	vector<double> x;	//N
	Convex_comb(vector<Order> b, vector<double> c, vector<double> x):b(b),c(c),x(x){}
	Convex_comb(vector<Order> b, vector<double> c):b(b),c(c){
		x = calcx();
	}
	Convex_comb(){}

	vector<double> calcx(){
		int K = b.size();
		int N = b[0].size();
		vector<double> res(N,0);
		rep(k,K){
			vector<double> vec = calc_b(b[k]);
			res = res + vec * c[k];
		}
		return res;
	}

	int size(){
		return b.size();
	}
	int getord(int k,int i){
		return b[k][i];
	}
	void setAlphato0(int s,int t){
		int K = size();
		int ag = -1,mx = 0;
		rep(i,K){
			int sid = -1, tid = -1;
			rep(j,N){
				if(b[i][j] == s) sid = j;
				if(b[i][j] == t) tid = j;
			}
			assert(sid!=-1);
			assert(tid!=-1);
			if(mx<tid-sid){
				mx = tid-sid;
				ag = i;
			}
		}
		swap(b[0],b[ag]);
		swap(c[0],c[ag]);
	}
	void compress(){
		int K = b.size();
		map<Order,double> mp;	//obvious compression
		rep(k,K) mp[b[k]] += c[k];
		vector<Order> nb;
		vector<double> nc;
		for(auto it:mp){
			auto bi = it.fs;
			auto ci = it.sc;
			if(sign(ci)!=0){
				nb.pb(bi);
				nc.pb(ci);
			}
		}
		b = nb, c = nc;

		// K = b.size();		//untrivial
		// calc_b
	}
};

pair<Convex_comb,double> get_comb(Order ord, int s, int t){
	int sid=-1,tid=-1;
	show(N);
	show(ord.size());
	rep(i,N){
		if(ord[i] == s) sid = i;
		if(ord[i] == t) tid = i;
	}
	show(sid);
	show(tid);

	vector<Order> ords;
	vector<double> sum(N,0);
	vector<double> c;
	for(int i=tid;i>sid;i--){
		int v = ord[i];
		Order ord_su = calc_ord_su_withid(ord,sid,i);
		vector<double> vec = get_b_norm(ord_su,ord);
		show(i);
		show(ord_su);
		show(vec);
		if(sign(vec[v])==0){
			Convex_comb cat({ord_su},{1});
			double delta = 0;
			return make_pair(cat,delta);
		}
		double coef = 0;
		if(i==tid) coef = 1.0/vec[v];
		else coef = -sum[v];
		assert(coef>0);
		ords.pb(ord_su);
		c.pb(coef);
		sum = sum + vec * coef;
	}
	int K = c.size();
//	printf("---");
	show(c);
	show(sum);
	double csum = 0;
	rep(k,K) csum += c[k];
	double delta = 1.0/csum;
	rep(i,K) c[i]/=csum;

	Convex_comb cat(ords,c);
	return make_pair(cat,delta);
}

void showcomb(Convex_comb cat){
	return;
	int K = cat.c.size();
	rep(i,N) show(cat.x[i]);
	puts("");
	rep(i,K) show(cat.c[i]);
	puts("");
	rep(i,K) show(cat.b[i]);
	puts("");
	puts("");
}


vector<bool> get_argmin(){
	f0 = f(vector<bool>(N,false));

	Order b_init;
	rep(i,N) b_init.pb(i);
	Convex_comb cat({b_init},vector<double>(1,1));

	int cnt = 0;

	while(true){
//		printf("-------------cnt = %d--------\n",cnt);
		cnt++;
		if(cnt%100==0) cout<<"cnt="<<cnt<<endl;
		// if(cnt==4){
		// 	assert(false);
		// }


		int K = cat.size();

		showcomb(cat);
		
		vector<int> d(N,inf);
		vector<vector<bool>> G(N,vector<bool>(N,false));
		vector<int> type(N);		//-1:N  1:P  0:otherwise
		rep(i,N){
			if(cat.x[i]>0)  type[i] = 1;
			if(cat.x[i]==0) type[i] = 0;
			if(cat.x[i]<0)  type[i] = -1;
		}
		show(type);
		rep(k,K){
			rep(i,N) for(int j=i+1;j<N;j++){
				int s = cat.getord(k,i);
				int t = cat.getord(k,j);
				G[s][t] = true;
			}
		}
		queue<int> que;
		rep(i,N){
			if(type[i]==1){
				que.push(i);
				d[i] = 0;
			}
		}
		while(!que.empty()){
			int v = que.front();
			que.pop();
			rep(u,N) if(G[v][u] && d[u]==inf){
				d[u] = d[v]+1;
				que.push(u);
			}
		}
		bool IsPath = 0;
		rep(t,N){
			if(type[t] == -1 && d[t] != inf) IsPath = 1;
		}
		if(IsPath){	//Case 2
//			printf("Case 2\n");
			int t = -1;
			rep(v,N){
				if(d[v]!=inf && type[v]==-1){	//reachable from P & in N
					if(t == -1 || d[t]<=d[v]) t = v;
				}
			}
			assert(t!=-1);

			show(t);

			int s = -1;
			rep(v,N){
				if(d[v]+1 == d[t] && G[v][t]) s = v;
			}
			assert(s!=-1);

			show(s);
			show(t);

			show(cat.b[0].size());

			cat.setAlphato0(s,t);


			auto tmp = get_comb(cat.b[0],s,t);
			Convex_comb z = tmp.fs;
			double delta = tmp.sc;

//			puts("z=");
			showcomb(z);
			show(delta);

			auto& x = cat;

			vector<Order> zb = z.b;
			vector<double> zc = z.c;
			vector<Order> yb = x.b;
			vector<double> yc = x.c;
			double lambda = yc[0];
			yc[0] = 0;

			int zK = zb.size();
			rep(k,zK){
				yb.pb(zb[k]);
				yc.pb(lambda*zc[k]);

				x.b.pb(zb[k]);
				x.c.pb(0);
			}
			Convex_comb y(yb,yc);

			double tx = x.x[t];
			double ty = y.x[t];
			assert(tx<0);

			Convex_comb nx;

			if(ty<eps){
				nx = y;
			}else{
				int NK = x.b.size();
				vector<Order> nxb = x.b;
				vector<double> nxc(NK,0);
				vector<double> nxx(N,0);
				rep(k,NK){
					nxc[k] = (x.c[k]*ty - y.c[k]*tx)/(ty-tx);
				}
				rep(i,N){
					nxx[i] = (x.x[i]*ty - y.x[i]*tx)/(ty-tx);
				}
				nx = Convex_comb(nxb,nxc,nxx);
			}
			nx.compress();
			x = nx;
		}else{	//Case 1
//			printf("Case 1\n");
			vector<int> dtoN(N,inf);
			queue<int> que;
			rep(i,N){
				if(type[i]==-1){
					que.push(i);
					dtoN[i] = 0;
				}
			}
			while(!que.empty()){
				int v = que.front();
				que.pop();
				rep(u,N) if(G[u][v] && dtoN[u]==inf){
					dtoN[u] = dtoN[v];
					que.push(u);
				}
			}
			vector<bool> U(N,false);
			rep(i,N) if(dtoN[i]!=inf){
				assert(type[i]!=1);
				U[i] = true;
			}
			return U;
		}
	}
}

vector<bool> brute(){
	D mn = 1e9;
	vector<bool> ag;
//	puts("------brute------");
	rep(b,1<<N){
		vector<bool> is(N,0);
		rep(i,N) is[i] = ((b>>i)&1);
		D tmp = f(is);
		// cout<<"f({";
		// rep(i,N) if(is[i]) cout<<i<<" ";
		// cout<<"}) = "<<tmp<<endl;

		if(mn>tmp){
			mn = tmp;
			ag = is;
		}
	}
//	puts("------brute------");
	return ag;
}
int main(){
	cin >> N;

	timer.start();
	vector<bool> ans = get_argmin();
	cout<<"{";
	rep(i,N) if(ans[i]) cout<<i<<" ";
	cout<<"}\n";
	printf("f(ans) = %d\n",(int)f(ans));
	printf("time = %d ms\n",timer.ms());

	string gomi;
	cin>>gomi;

	timer.start();
	vector<bool> br = brute();
	cout<<"{";
	rep(i,N) if(br[i]) cout<<i<<" ";
	cout<<"}\n";
	printf("f(br) = %d\n",(int)f(br));
	printf("time = %d ms\n",timer.ms());

}