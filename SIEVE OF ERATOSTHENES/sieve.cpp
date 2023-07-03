int primes[1000006]
//doing it in opposite way primes[n] == 1 -> not primes


void sieve(int n){
	primes[1] = 1;

	for(int i = 2;i<=n;i++){
		if(!primes[i]){
			for(int j = 2*i;j<=n;j+=i){
				primes[j] = 1;
			}
		}
	}
}


bool checkPrime(int n){
	if(!primes[i]){
		return true;
	}
	else{
		return false;
	}
}
