int lo = 1;
int hi = 1e9;
int mid;

while(hi - lo > 1){
    mid = lo + (hi - lo)/2;

    if(predicatefn(mid)){
      //current low should be considered in answer
        lo = mid;
    }
    else{
        hi = mid - 1;
    }
}


//when maximum is the answer consider hi first then lo

if(predicatefn(hi)){
    cout<<hi<<endl;
}
else if(isufficient(lo)){
    cout<<lo<<endl;
}
else{
    cout<<"-1"<<endl;
}
