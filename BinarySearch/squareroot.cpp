//global part
//gives 5 digit precision 
//if n digit precision required then use 1e-(n+1)
double eps = 1e-6;


//local part
double n;
cin >> n;
debug(n)
double lo = 1;
double hi = n,mid;

while(hi - lo > eps){
    mid = (lo + hi)/2;
    // debug(lo)
    // debug(hi)
    if(mid*mid < n){
        lo = mid;
    }
    else{
        hi = mid;
    }
}

    //print anything lo or high
    cout<<lo<<endl;
