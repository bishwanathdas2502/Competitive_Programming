// finding nCr using pascal triangle



// n = max num
const int mod = 1e9 + 7;

vector<vector<long long>> ncr;
void precompute(int n){
    ncr.resize(n+1);
    
    for(int i = 0 ; i< n+1;i++){
        ncr[i] = vector<long long>(i+1,1);
        
        for(int j = 1;j<i;j++){
             //       j-1 j
            //i-1 =>  x   y
            //i=>       z 
            // z = x + y
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
        }
    }
  
}



//to get ncr value

// due to zero index
ncr(n-1,r)
