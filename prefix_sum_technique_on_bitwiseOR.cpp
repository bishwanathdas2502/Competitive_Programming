vector<int> bits(32,0);
int n = arr.size();
//initial window
//k length window
rep(i,0,k){
    rep(j,0,32){
        if(arr[i] & (1LL<<j)){
            bits[j]++; //initialising the bitcnt array for doing sliding window

        }
    }
}


rep(i,k,n){
    //remove prev element;
    rep(j,0,32){
        if(arr[i-k] & (1LL<<j)){
            bits[j]--;

        }
    }

    //add new element;
    rep(j,0,32){
        if(arr[i] & (1LL << j)){
            bits[j]++;

        }
    }

}

