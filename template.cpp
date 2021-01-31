#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
void debug(string t,T input){
    cout<<t<<"->"<<input<<"\n";
}
//for loop
template<typename T>
void debug(int i,string t,T input){
    cout<<"Case#"<<i<<" "<<t<<"->"<<input<<"\n";
}

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


void solve(){

}



int32_t main(){
    FIO;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}