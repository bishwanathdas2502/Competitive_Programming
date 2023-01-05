

//mx will store the mx value
//seg will the "starting index -1" and ending index of the segment

//summary 
//store the sum till it is positive and update the maximum once it is negative restart with sum = 0
int mx = -INF;
pair<int,int> kadane(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    pair<int,int> seg;
    int pos = -1;
    rep(i,0,n){
        sum += arr[i];
        
        if(sum > mx){
            mx = sum ;
            seg = {pos,i};

        }
        
        if(sum < 0){
            pos = i;
            sum = 0 ;
            
        }
    }



    
    return seg;
}
