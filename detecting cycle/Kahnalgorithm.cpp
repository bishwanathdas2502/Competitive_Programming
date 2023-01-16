vector<int> G[200000];
int indeg[200000] = {0};


bool cycle(int n){
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
    int vertex_cnt = 0;
    while(!q.empty()){
        int node = q.front();
        vertex_cnt++;
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
    if(vertex_cnt == n)return false;
    return true;
}
