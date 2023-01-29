const int N =1e5 + 5;
const int INF = 1e9 + 5;

//g contains parameter as
//1st vertex
//2nd weight
vector<pair<int,int>> g[N];

vector<int> dist(N,INF);
vector<bool> vis(N,0);
void dijkstra(int source){

    //set contains parameter as
    //1st as weight
    //2nd as vertex
    set<pair<int,int>> st;
    st.insert({0,source});

    dist[source] = 0;

    while(!st.empty()){


        //processing node after taking it out of set
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if(vis[v])continue;

        vis[v] = 1;

        for(auto child : g[v]){

            //inserting node based on check
            int child_v = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }


}
