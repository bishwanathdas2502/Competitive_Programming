#define N 100005
    int seg[4*N+1];

    void buildTree(int index,int start,int end,vector<int> &arr){
        if(start == end){
            seg[index] = arr[start];
            return;
        }
        int mid = start + (end - start)/2;

        buildTree(2*index+1,start,mid,arr);
        buildTree(2*index+2,mid+1,end,arr);
        seg[index] = seg[2*index+1] + seg[2*index + 2];
    }

    int calPeak(int index,int start,int end,int l,int r){
        if(l <= start && end <= r){
            return seg[index];
        }
        else if(end < l || r < start){
            return 0;
        }
        else{
            int mid = start + (end-start)/2;
            return calPeak(2*index + 1,start,mid,l,r) + calPeak(2*index+2,mid+1,end,l,r);
        }
    }

    void update(int index,int start,int end,int id,int val){
        if(start == end){

            seg[index] = val;
            return;
        }

        int mid = start + (end-start)/2;
        if(id <= mid){
            update(2*index+1,start,mid,id,val);
        }
        else{
            update(2*index+2,mid+1,end,id,val);
        }
        seg[index] = seg[2*index+1] + seg[2*index + 2];
    }
