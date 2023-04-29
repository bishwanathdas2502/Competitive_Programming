int par[20000];
int rank[20000];

void make_set(int n){
		for(int i = 1;i<=n;i++){
				par[i] = i;
				rank[i] = 0;
		}

}


int findPar(int node){
		if(node == par[node]){
				return node;
		}
		return par[node] = findPar(par[node]);
}

void Union(int u,int v){
		u = findPar(u);
		v = findPar(v);

		if(rank[u] < rank[v]){
				par[u] = v;
		}
		else if(rank[v] < rank[u]){
				par[v] = u;
		} 
		else{
				par[v] = u;
				rank[u]++;
		}
}


//finding number of component of a graph in  DSU


int n = nodes.size; //set to number of nodes
make_set(n);
int cnt = n; //intially n component


//if we add and edge between two nodes whose par are different reduce the count 
for(int i = 0;i<n;i++){
	for(int j = i+1;j<n;j++){
	   int l = sim(strs[i],strs[j]);
	   if((l == 0 || l == 2) && findPar(i) != findPar(j)){
		   cnt--;
		   Union(i,j);
	   }
	}
}

return cnt;
