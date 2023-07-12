class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,1));
        
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        
        int ans = 1;
        for(int i = 1;i<n;i++){
            //upper element
            if(nums1[i]>=nums1[i-1] ){
                dp[i][0] = max(dp[i][0],dp[i-1][0]+1);
                ans = max(ans,dp[i][0]);
            }
            if(nums1[i] >= nums2[i-1]){
                dp[i][0] = max(dp[i][0],dp[i-1][1] + 1);
                ans = max(ans,dp[i][0]);
            }
            
            
            
            
            
            //lower element
            if(nums2[i] >= nums1[i-1]){
                dp[i][1] = max(dp[i][1],dp[i-1][0] + 1);
                ans = max(ans,dp[i][1]);
            }
            if(nums2[i] >= nums2[i-1]){
                dp[i][1] = max(dp[i][1],dp[i-1][1] + 1);
                ans = max(ans,dp[i][1]);
            }
            
            
            
            
        }
        
        // for(auto it : dp){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        
        
        
        return ans;
        
        
    }
};
