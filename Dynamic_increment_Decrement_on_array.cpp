
//Two associated array
//update k with minimum of remaining element after deleting all lesser element than threshold k 
rep(i,0,n){
  cin>>h[i];
}
rep(i,0,n){
  cin>>p[i];
}
// debug(p)

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

rep(i,0,n){
  pq.push({p[i],h[i]});
}

int cur_h = k;

while(k>0 && !pq.empty()){



  while(!pq.empty() && pq.top().second <= cur_h){
    pq.pop();
  }

  //update k with minimum of remaining element
  int pi = pq.top().first;

  k = k - pi;
  cur_h  += k;


}

(!pq.empty())?cout<<"NO\n":cout<<"YES\n";

	
