map<int,int> factors;
int copy = n; 
for(int p = 2;p*p <= n;p++){
    while(copy % p == 0){
        copy /=p;
        factors[p]++;
    }
}
if(copy != 1){
    factors[copy]++;
}
