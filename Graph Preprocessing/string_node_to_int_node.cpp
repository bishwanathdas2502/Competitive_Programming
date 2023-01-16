
//global part
map<string,int> mp;
vector<int> G[200000];
int id = 0;




//local part
int n;
cin >> n;

rep(i,0,n){
    string a,b;cin>>a>>b;

    //tranforming string based node to int
    auto it =  mp.find(a);
    auto it2 = mp.find(b);

    //if new node encountered give it a new index
    if(it == mp.end()){
        mp[a] = ++id;
    }

    if(it2 == mp.end()){
        mp[b] = ++id;
    }

    //push it to adjacency list

    //Directed graph here
    G[mp[a]].push_back(mp[b]);


}
