class NumMatrix {
public:

    vector<vector<int>> arr;


    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        arr.resize(n+1,vector<int>(m+1));
        arr[1][1] = matrix[0][0];
        for(int i = 2;i<=n;i++){
            arr[i][1] = arr[i-1][1] + matrix[i-1][0]; 
        }

        for(int j = 2;j<=m;j++){
            arr[1][j] += arr[1][j-1] + matrix[0][j-1];
        }

        for(int i = 2;i<=n;i++){
            for(int j = 2;j<=m;j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + matrix[i-1][j-1];
            }
        }

        // for(int i=0;i<=n;i++){
        //     for(int j = 0;j<=m;j++){
        //         cout<<arr[i][j]<<" ";
        //     }cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout<<" ->"<<arr[row2+1][col2+1]<<endl;
        // cout<<" ->"<<arr[row1+1][col2+1]<<endl;
        // cout<<" ->"<<arr[row2+1][col1+1]<<endl;
        // cout<<" ->"<<arr[row1+1][col1+1]<<endl;

        int ans = arr[row2+1][col2+1] - arr[row1][col2+1] - arr[row2+1][col1] + arr[row1][col1];
        return ans;
    }
};
