const int N = 1e5+10;
vector<int> g[N];
int depth[N];


// dfs on tree

void dfs(int v,int par = -1){
    for(auto child : g[v]){
        if(child == par)continue;
        depth[child] = depth[v] + 1;
        dfs(child,v);
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
    dfs(1);

    //find the max_depth node
    int mx_depth = -1;
    int mx_depth_node;


    for(int i = 1;i<=n;i++){
        if(depth[i] > mx_depth){
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        //reset the depth array
        depth[i] = 0;
    }

    //calculate the mx_depth node from the prev mx_depth node and it will give the diameter
    //in short find the max depth node by take the prev max_depth node as root
    dfs(mx_depth_node);

    int diameter = 0;
    for(int i= 1;i<=n;i++){
        diameter = max(diameter,depth[i]);
    }

    cout<<diameter<<endl;
    

}
