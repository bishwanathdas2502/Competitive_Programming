//count number of subarray with given xor
ll count_subarray(vector<int> &arr,int num){
    unordered_map<int,int> mp;
    //initial xor = 0
    mp[0]=1;
    int Xor = 0;
    ll cnt = 0 ;
    for(ll i = 0 ;i<arr.size();i++){
        Xor ^= arr[i];
        cnt += mp[Xor ^ num];
        mp[Xor]++;
    }
    
    return cnt;

}


ll count_subarray_sum(vector<int> &arr,int sum){
    unordered_map<int,int> mp;
    //initial sum = 0
    mp[0] = 1;
    ll cnt =0;
    int curSum = 0;

    for(ll i = 0;i<arr.size();i++){
        curSum += arr[i];

        cnt += mp[curSum - sum];

        mp[curSum]++;
    }

    return cnt;
}
