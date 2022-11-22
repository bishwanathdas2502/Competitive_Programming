int nw = 1;
while(nw<=n && arr[nw] <= arr[nw-1])nw++;

while(nw<=n&& arr[nw] >= arr[nw-1])nw++;


if(nw == n+1){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
