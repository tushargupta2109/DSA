class Solution {
public:
    
    int solve(int k, vector<int> prices, int idx, int bs, vector<vector<vector<int>>> &dp){
        
        int n = prices.size();
        
        if(idx == n){
            return 0;
        }
        
        if(idx == n-1 && bs == 0){
            return 0;
        }
        
        if(k==0){
            return 0;
        }
        
        if(dp[idx][bs][k] != -1){
            return dp[idx][bs][k];
        }
        
        int ans = 0;
        if(bs == 0){
            
            ans = max(solve(k, prices, idx+1, 0, dp), -prices[idx] + solve(k, prices, idx+1, 1, dp));
        }
        else{
            ans = max(solve(k, prices, idx+1, 1, dp), prices[idx] + solve(k-1, prices, idx+1, 0, dp));
        }
        
        return dp[idx][bs][k] = ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(k, prices, 0, 0, dp);
    }
};