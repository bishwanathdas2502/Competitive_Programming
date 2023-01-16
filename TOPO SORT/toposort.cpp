
//toposort valid for only dag

vector<int> G[200000];
bool vis[200000] = {0};
int indeg[200000] = {0};


vector<int> toposort(int n){
    for(int i = 1;i<=n;i++){
        for(auto it : G[i]){
            indeg[it]++;
        }
    }

    
    queue<int> q;

    for(int i = 1;i<=n;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    

    //there will always a node with indegree as 0
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();
        // debug(node)

        for(auto child : G[node]){
            // debug(child)
            indeg[child]--;
            
            if(indeg[child] == 0){
                q.push(child);
            }
        }
    }
    return topo;
}

