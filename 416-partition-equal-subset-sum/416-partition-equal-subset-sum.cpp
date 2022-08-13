class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2) return false;
        int target = sum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));
        for(int i=0;i<n;i++) dp[i][0] = 1;
        if(nums[0]<=target) dp[0][nums[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j = 1;j<=target;j++){
                bool notake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i])
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = take or notake;
            }
        }
        return dp[n-1][target];
    }
};