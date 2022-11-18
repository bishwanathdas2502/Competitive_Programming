

#define M 1000000007
#define N 100

int fact[N],invfact[N];

void init(){
    fact[0] = 1;
    int i;
    for(i = 1;i<N;i++){
        fact[i] = mod_mul(fact[i-1],i,M);
    }
    
    i--;
    
    invfact[i] = expo(fact[i],M-2,M);
    
    for(i--;i>=0;i--){
        invfact[i] = mod_mul(invfact[i+1],i+1,M);
    }
    
}

int ncr(int n,int r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[n-r]%M * invfact[r]%M;
}
