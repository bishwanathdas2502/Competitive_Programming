//let the tuple consist of {a,b,c}

priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;  //min heap
pq.push({a,b,c});


while(!pq.empty()){
  auto [a,b,c] = pq.top(); //accessing tuple in one line
  pq.pop();
  //other operation
    
    

}
