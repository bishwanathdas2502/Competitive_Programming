int pre[4] = {0};
int psum = 0;

int ans = 0;
rep(i,1,n+1){
    psum += arr[i];
    psum %= MOD1;
    ans += i*expo(psum,3,MOD1);
    ans -= 3*pre[1]*expo(psum,2,MOD1);
    ans += 3*pre[2]*psum;
    ans -= pre[3];

    ans %= MOD1;
    ans = (ans + MOD1)%MOD1;
    pre[1] += psum;
    pre[2] += expo(psum,2,MOD1);
    pre[3] += expo(psum,3,MOD1);

    pre[1] %= MOD1;
    pre[2] %= MOD1;
    pre[3] %= MOD1;
}

	cout<<ans<<endl;
