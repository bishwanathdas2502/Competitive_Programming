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
