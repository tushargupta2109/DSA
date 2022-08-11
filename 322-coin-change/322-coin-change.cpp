class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        
        sort(coins.begin(), coins.end());
        for(int i=0;i<=amount;i++){
            dp[0][i] = INT_MAX - 1; 
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 0; 
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                
                int taken = INT_MAX - 1;
                if(coins[i-1]<= j){
                    taken = 1 + dp[i][j-coins[i-1]];
                }
                int not_taken = dp[i-1][j];
                
                dp[i][j] = min(not_taken, taken);
            }
        }
        
        int ans = dp[n][amount];
        if(ans == INT_MAX-1){
            return -1;
        }
        return ans;
    }
};