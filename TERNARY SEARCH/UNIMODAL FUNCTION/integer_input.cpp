double a,b;

double f(double x){
    //write the function here
    //bx + a/sqrt(x+1)

    return (double)b*x + (double)a/sqrt(x+1);
}

double ternary(){
    ll l = 0;
    ll r = 1e18;
    
  
    //for finding minimum
    //for integer input can run till (r-l)<3
    while(r - l > 2){
        ll m1 = l + (r - l)/3;
        ll m2 = r - (r - l)/3;

        double fm1 = f(m1);
        double fm2 = f(m2);

        if(fm1 > fm2){
            l = m1;
        }
        else if(fm2 > fm1){
            r = m2;
        }
        else{
            l = m1;
            r = m2;
        }

    }
    
    //check for all (l,r) remaining
    double ans = a;
    for(ll i = l;i<=r;i++){
        ans = min(ans,f(i));
    }
    return ans;
   

}
