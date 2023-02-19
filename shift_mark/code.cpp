//mark 0 as visited 
// if x+d is mark then x = x+1
// mark (x + d)mod N mark 

//code


int t;
cin >> t;
while (t--) {
    int n, d, k;
    cin >> n >> d >> k;
    --k;
    int a = n / gcd(n, d);

    int shift = k/a;
    cout << (long long) d * k % n + shift << '\n';
}
