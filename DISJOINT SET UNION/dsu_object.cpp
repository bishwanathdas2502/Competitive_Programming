class DSU{
    
    public:
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
	    
	    
	// 0 based indexing now
        for(int i = 0;i<=n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int findPar(int node){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node]);
    }
    
    
    void UnionbyRank(int a,int b){
        a = findPar(a);
        b = findPar(b);
        
        if(rank[a] > rank[b]){
            par[b] = a;
        }
        else if(rank[a] < rank[b]){
            par[a] = b;
        }
        else{
            par[b] = a;
            rank[a]++;
        }
    }


    void UnionbySize(int node1,int node2){
        int a = findPar(node1);
        int b = findPar(node2);

        if(size[a] > size[b]){
            par[b] = a;
            size[a] += size[b];
        }
        else{
            par[a] = b;
            size[b] += size[a]; 
        }
    }
};
