
V<bool> isp;
V<int> pr;
V<int> sf; //smallest factor, sf[9*5*11] = 3
void linear_sieve(int X){		// <= X
	isp = V<bool>(X+1,true); isp[0] = isp[1] = false;
	sf = V<int>(X+1);
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
}