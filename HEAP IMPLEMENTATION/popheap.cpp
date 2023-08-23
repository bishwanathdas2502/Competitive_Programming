int pop(vector<int> &heap)
{
    // Write you code here.
    if(heap.size() == 0)return -1;

    int ans = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    if(heap.size() == 0){
        return ans;
    }

    int pos = 0;

    while(true){
        int left = 2*pos + 1;
        int right = 2*pos + 2;

        int leftvalue = 0,rightvalue = 0;
        if(left < heap.size())leftvalue = heap[left];
        if(right < heap.size())rightvalue = heap[right];

        if(leftvalue <= heap[pos] && rightvalue <= heap[pos]){
            break;
        }
        else if(leftvalue <= rightvalue){
            swap(heap[pos],heap[right]);
            pos = right;
        }
        else{
            swap(heap[pos],heap[left]);
            pos = left;
        }
    }

    return ans;

}
