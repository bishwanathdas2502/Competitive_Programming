int offset = 100000;
        
vector<int> pref(300005,0);

int n = nums.size();
for(int i = 0;i<n;i++){
    int l = nums[i] - k;
    int h = nums[i] + k;
    
    pref[l+offset]++;
    pref[h+offset+1]--;
}

int mx = pref[0];
for(int i = 1;i<300005;i++){
    pref[i] += pref[i-1];
    mx = max(mx,pref[i]);
}
return mx;
}
