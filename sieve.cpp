#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define rrep(i,a,b)     for(int i=a;i>=b;i--)   
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//pbds similar to sets
// two function are order_of_key(num)--> returns index of number after sorting
//*(itr).find_by_order(3) --> return the num after which the number is inserted
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// vector<int> adj[(int)1e6];
// queue<int> q;
// int col[(int)1e6];
// int vis[(int)1e6];

bool prime[(int)1e6];
// vector<int> num;
void sieve(int n){
    memset(prime,true,sizeof(prime));
    prime[1] = false;
    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            // num.push_back(p);
            for(int i = p*p; i<=n ;i += p){
                prime[i] = false;
            }
        }
    }
}



int32_t main(){
    FIO;
    sieve(20);
    // for(auto it:num){
    //     cout<<it<<" ";
    // }cout<<endl;
    cout<<prime[4]<<endl;
    cout<<prime[5]<<endl;
    cout<<prime[999983]<<endl;
    
    return 0;
}