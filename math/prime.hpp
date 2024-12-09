V<bool> isp;
V<int> pr;
V<int> sf; //smallest factor, sf[9*5*11] = 3
V<int> mu;	//[1,-1,0,0,...]
V<int> tot;	//[1,p-1,(p-1)p,(p-1)p^2,..]
V<int> sig;	// [1,1+p,1+p+p^2,...]
void linear_sieve(int X){		// <= X
	isp = V<bool>(X+1,true); isp[0] = isp[1] = false;
	sf = V<int>(X+1);
	pr.clear();
	for(int i=2;i<=X;i++){
		if(isp[i]){
			pr.pb(i);
			sf[i] = i;
		}
		for(int j=0;i*pr[j]<=X;j++){
			isp[i*pr[j]] = false;
			sf[i*pr[j]] = pr[j];
			if(i%pr[j] == 0) break;
		}
	}
	// mu = V<int>(X+1);
	// mu[1] = 1;
	// for(int i=2;i<=X;i++){
	// 	int p = sf[i];
	// 	if(i/p%p == 0) mu[i] = 0;
	// 	else mu[i] = -mu[i/p];
	// }
	// tot = V<int>(X+1);
	// tot[1] = 1;
	// for(int i=2;i<=X;i++){
	// 	int p = sf[i];
	// 	if(i/p%p == 0) tot[i] = tot[i/p] * p;
	// 	else tot[i] = tot[i/p] * (p-1);
	// }
	// sig = V<int>(X+1);
	// sig[1] = 1;
	// for(int i=2;i<=X;i++){
	// 	int p = sf[i];
	// 	int x = i;
	// 	int w = 1;
	// 	while(x%p == 0){
	// 		x /= p; w = w*p+1;
	// 	}
	// 	sig[i] = sig[x] * w;
	// }
}
