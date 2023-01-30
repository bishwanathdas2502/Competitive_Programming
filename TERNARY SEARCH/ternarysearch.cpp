
void ternary(int ele,vector<int> &arr){
    int n = arr.size();


    int l = 0;
    int r = n - 1;

    while(l <= r){
        //divide the search space into 3
        int m1 = l + (r-l)/3;
        int m2 = r -  (r-l)/3;

        if(arr[m1] == ele || arr[m2] ==  ele){
            cout<<"Found"<<endl;
            return;
        }

        else if(ele < arr[m1]){
            r = m1 - 1;
        }
        else if(ele > arr[m2]){
            l = m2 + 1;
        }
        else{
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    cout<<"Not Found"<<endl;


}


