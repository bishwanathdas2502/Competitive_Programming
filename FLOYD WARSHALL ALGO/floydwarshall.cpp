

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



// When we want to minimise the distance along with that we want to minimise/maximise other value
const int N = 505;

int dist[N][N];
int val[N][N];

int arr[N];
void floyd(int n){

    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int prev = dist[i][j];
                int new_d = dist[i][k] + dist[k][j];


                if(prev < new_d){
                    continue;
                }
                //here we want to minimse or maximise the other value
                else if(prev == new_d){
                    val[i][j] = max(val[i][j],val[i][k] + val[k][j]);
                }
                else{
                    dist[i][j] = new_d;
                    val[i][j] = val[i][k] + val[k][j];
                }
            }
        }
    }

}
