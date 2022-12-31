
//pass an array of size 3 not vector
void extendedGCD(ll a,ll b,ll *v){
    //v[0] = x
    //v[1] = y
    //v[2] = gcd
    if(b == 0){
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }

    extendedGCD(b,a%b,v);
    ll x = v[1];
    ll y = v[0] - (a/b)*v[1];
    v[0] = x;
    v[1] = y;
    return;
}
