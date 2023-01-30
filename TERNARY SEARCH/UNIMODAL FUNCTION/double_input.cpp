
double f(){
 //write function here 
  
}

double ternary_search() {
    double l = 0;
    double r = 1e9;
    double eps = 1e-6;              //set the error limit here
    while (r - l > eps) {
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
    return f(l);                    //return the minimum of f(x) in [l, r]
}
