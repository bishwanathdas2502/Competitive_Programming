string s;cin>>s;
regex pattern("WUB");

string temp = regex_replace(s,pattern," ");
cout<<temp;
