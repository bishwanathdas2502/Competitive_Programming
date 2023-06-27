// finding kth smallest element using k size max heap

// steps 
// traverse through the array if the size of heap is less than K -> push it
// if the size ==  k and the element is smaller than top element pop the top element ans push the element
// else the number from here onwards will be greater stop the traversal

int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        int n = matrix.size();
        int m = matrix[0].size(); 
        for(int i = 0; i<n;i++){
            for(int j = 0;j<m;j++){
                if(pq.size() < k){
                    pq.push(matrix[i][j]);
                }
                else if(matrix[i][j] < pq.top()){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
                else{
                    break;
                }
            }
        }


        return pq.top();
    }
