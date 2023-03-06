    int src;
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();


        for(auto child : g[node]){
            if(vis[child]) continue;
            q.push(child);
            vis[child] = 1;
        }
    }
