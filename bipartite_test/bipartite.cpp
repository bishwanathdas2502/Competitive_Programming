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

int check(int node,int par,int c){
	col[node] = c;
	bool ret = true;
	for(auto child : adj[node]){
		if(child == par || col[child] == -c)continue;
		if(col[child] == c) return false;
		ret = ret & check(child,node,-c);
	}
	return ret;
}




