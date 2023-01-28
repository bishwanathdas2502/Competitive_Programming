const int N = 1e5+10;
vector<int> g[N];
int par[N];


// dfs on tree

void dfs(int v,int p= -1){

    par[v] = p;
    for(auto child : g[v]){
        if(child == p)continue;
        dfs(child,v);
    }
}

vector<int> path(int v){

    vector<int> trace;
    while(v!=-1){
        trace.push_back(v);
        v = par[v];
    }
    reverse(trace.begin(),trace.end());
    return trace;
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
    int x,y;cin>>x>>y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);



    int lca = -1;
    int ln = min(path_x.size(),path_y.size());

    for(int i = 0;i<ln;i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }

    cout<<lca<<endl;    

}
