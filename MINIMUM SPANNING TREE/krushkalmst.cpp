class DSU{
	public:
	vector<int> par;
	vector<int> rank;

	DSU(int n){
		par.resize(n+1);
		rank.resize(n+1);

		for(int i = 0;i<=n;i++){
			par[i] = i;
		}
	}


	int findPar(int node){
		if(node == par[node]){
			return node;
		}

		return par[node] = findPar(par[node]);
	}


	void Union(int node1,int node2){
		int u = findPar(int node1);
		int v = findPar(int node2);


		if(rank[u] > rank[v]){
			par[v] = u;
		}
		else if(rank[u] < rank[v]){
			par[u] = v;
		}
		else{
			par[v] = u;
			rank[u]++;
		}
	}

};

vector<vector<int>> el;
DSU dsu(n);
for(auto it : connections){
  int u = it[0];
  int v = it[1];
  int w = it[2];

  el.push_back({w,u,v});
}

sort(el.begin(),el.end());

int ans = 0;
int comp = n;     // n is number of nodes
for(auto e : el){
  int w = e[0];
  int u = e[1];
  int v = e[2];


  if(dsu.findPar(u) != dsu.findPar(v)){
    comp--;
    ans += w;
    dsu.Union(u,v);
  }

}

//if all node can't be connected return -1
if(comp > 1){
  return -1;
}
return ans;
























