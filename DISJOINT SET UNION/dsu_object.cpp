



class DSU{
	
vector<int> par;
vector<int> rank;

public:
    DSU(int n){
        par.push_back(0);
        rank.push_back(0);
	    
	//check for indexing whether 0-based or 1-based
        for(int i=1;i<=n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int findPar(int node){
        if(node == par[node]){
            return node;
        }

        return par[node] = findPar(par[node]);
    }

    void Union(int node1,int node2){
        int u  = findPar(node1);
        int v = findPar(node2);

        if(rank[u] < rank[v]){
            par[u] = v;
        }
        else if(rank[u] > rank[v]){
            par[v] = u;
        }
        else{
            par[v] = u;
            rank[u]++;
        }
    }



};
