class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<int> prev(amount+1, INT_MAX - 1);
        prev[0] = 0;
        
        for(int i=1;i<=n;i++){
            
            vector<int> curr(amount+1, -1);
            curr[0] = 0;
            
            for(int j=1;j<=amount;j++){
                
                int taken = INT_MAX - 1;
                if(coins[i-1]<= j){
                    taken = 1 + curr[j-coins[i-1]];
                }
                int not_taken = prev[j];
                
                curr[j] = min(not_taken, taken);
            }
            
            prev = curr;
        }
        
        int ans = prev[amount];
        if(ans == INT_MAX-1){
            return -1;
        }
        return ans;
    }
};