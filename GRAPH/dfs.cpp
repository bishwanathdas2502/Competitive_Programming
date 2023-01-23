const int N = 1e5 + 10;
vector<int> G[N];
bool vis[N];


void dfs(int node){
    //1. take action on the vertex after entering the vertex
    vis[node] = true;

    for(auto child : G[node]){
        //2. take action on child before entering the child node
        if(vis[child])continue;
        
        dfs(child);

        //3. take action on the child after exiting the child node


    }

    //4. take action on the node before exiting the node
}
