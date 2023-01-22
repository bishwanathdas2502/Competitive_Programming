

//graph input
rep(i,0,m){
        int a,b,wt;cin>>a>>b>>wt;
        dist[a][b] = wt;

    }



//uncomment the if condition in case of negative weight in graph
for(int k = 1;k<=n;k++){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            // if(dist[i][k] != INF && dist[k][j] != INF)
            dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        }
    }
}
