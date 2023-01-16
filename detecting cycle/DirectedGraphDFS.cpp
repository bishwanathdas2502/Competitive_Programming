const int N =1e5;
vector<int> G[N];
bool vis[N] = {0};
bool pathvis[N] = {0};




bool dfsCheck(int node){
    vis[node] = 1;
    pathvis[node] = 1;



    for(auto child : G[node]){

        //when node is not visited
        if(!vis[child]){
            if(dfsCheck(child)){
                return true;
            }
            
        }

        //check on the same path
        else if(pathvis[child]){
                return true;
        }
    }

    pathvis[node] = 0;
    return false;

}
