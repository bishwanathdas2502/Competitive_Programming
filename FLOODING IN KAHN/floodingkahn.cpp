    vector<int> adj[200005];
    
    int indeg[200005];
    vector<int> start;
    map<char,int> mp;
    int mx = 0;


    int kahn(int n,string colors){
        vector<vector<int>> count(n,vector<int>(26));
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indeg[i] == 0){
                q.push(i);
                start.push_back(i);
            }
        }
        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            //update the current node
            count[node][colors[node]-'a']++;
            mx = max(mx,count[node][colors[node]-'a']);

            //flooding the neighbors
            for(auto child : adj[node]){
                for(int i = 0;i<26;i++){
                    count[child][i] = max(count[child][i],count[node][i]);
                }
                
                indeg[child]--;
                if(indeg[child] == 0){
                    q.push(child);
                }
            }

        } 

        return (cnt == n)?mx:-1;
    }
