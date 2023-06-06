vector<int> G[200005];
int color[200005];




//bipartite test
pair<int,int> dfs(int node,int par,int c){
	
	pair<int,int> ret = {0,0};
	color[node] = c;

	if(c == 1){
		ret.first++;
	}
	else{
		ret.second++;
	}


	for(auto child : G[node]){

		//if child == parent color of child is opposite to node
		if(child == par||color[child] == -c)continue;

		//if color of child is same as parent return false
		if(color[child] == c) return {-1LL,-1LL};

		pair<int,int> res = dfs(child,node,-c);
		
		//if child is not satisfying 2 coloring
		if(res.first == -1LL)return {-1LL,-1LL};

		//if satisfy and color 1/black to ret.first and 0/white to ret.second
		ret.first += res.first,ret.second += res.second;

	}
	return ret;

}





//only bipartite check

int col[20005];
int vis[20005];
bool checkB(int node,int c){
col[node] = c;
vis[node] = 1;

for(auto child : adj[node]){
    if(vis[child] == 0){
	if(checkB(child,c^1) == false){
	    return false;
	}
    }
    else{
	if(col[child] == col[node]){
	    return false;
	}
    }
}

return true;


}



