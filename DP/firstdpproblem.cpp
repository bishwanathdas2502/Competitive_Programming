/*

problem link: https://atcoder.jp/contests/abc286/tasks/abc286_d

*/

const int N = 1e5+5;
int coins[105];
int dp[105][N];
bool func(int ind,int sum){
    if(sum == 0)return dp[ind][sum] = true;
    if(sum < 0)return dp[ind][sum] = false;
    if(ind == 101)return dp[ind][sum] = false;
    if(dp[ind][sum] != -1)return dp[ind][sum];
    if(coins[ind] ==  0){
        return dp[ind][sum] = func(ind+1,sum);
    }
    for(int take = 0;take <= coins[ind];take++ ){
        if(func(ind+1,sum - take*ind) == true){
            return dp[ind][sum] = true;
        }
    }
    return dp[ind][sum] = false;
}


void solve()
{
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin >> n >>x;

    rep(i,0,n){
        int a,b;cin>>a>>b;

        coins[a] = b;
    }

    bool ans = func(1,x);
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    

}

int32_t main()
{
    FIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    freopen("error.txt","w",stderr);

#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
