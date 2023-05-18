
prefix suffix of OR
for(int i = 1;i<n;i++){
	prefix[i] = prefix[i-1] | nums[i-1];
	suffix[n-i-1] = suffix[n-i] | nums[n-i];
}


for(int i = 1;i<n;i++){
	prefix[i] = prefix[i-1] + nums[i-1];
	suffix[n-i-1] = suffix[n-i] + nums[n-i];
}

// accessing suffix or prefix
//for ith element 
prefix[i] or suffix[i]
