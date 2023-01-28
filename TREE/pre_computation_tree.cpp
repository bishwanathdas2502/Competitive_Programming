
//delete one edge to maximise the product



// computer subtree_sum of all the node

//check for every edge if we delete the edge what is the product of two subtree
// one part = subtree_sum[node]
//othe part = subtree_sum[root] - subtree_sum[node]
//return max(one_part * other_part)

//precomutation_technique
//subtree_sum_precomputation
const int N = 1e5+10;
vector<int> g[N];

//sum of subtree
int subtree_sum[N];
//value stored at each node
int val[N];


// dfs on tree
void dfs(int v,int p=-1){

    subtree_sum[v] = val[v];
    for(auto child : g[v]){
        if(child == p)continue;

        dfs(child,v);
        //from leaf to up
        subtree_sum[v] += subtree_sum[child];
    }
}

void solve()
{
    int n;
    cin >> n;
    
    for(int i = 0;i<n-1;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    //dfs will store the par of every node
    dfs(1);
    ll ans = 0;
    for(int i = 2;i<=n;i++){
        int first_subtree_sum = subtree_sum[i];
        int other_subtree_sum = subtree_sum[1] - first_subtree_sum;
        ans = max(ans,first_subtree_sum*1LL*other_subtree_sum);
    }

    cout<<ans<<endl;

}
