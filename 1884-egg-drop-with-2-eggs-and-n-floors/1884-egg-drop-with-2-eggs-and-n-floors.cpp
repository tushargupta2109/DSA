class Solution {
public:
    
    int solve(int floor, int eggs, vector<vector<int>> &dp){
        
        if(dp[floor][eggs] != -1){
            return dp[floor][eggs];
        }
        
        if(floor<=1 || eggs == 1){
            return floor;
        }
        
        int turns = INT_MAX;
        for(int i=1;i<floor;i++){
            
            turns = min(turns, max(solve(floor-i, eggs ,dp), solve(i-1, eggs-1, dp))+1);
        }
        
        return dp[floor][eggs] = turns;
    }
    
    int twoEggDrop(int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(n, 2, dp);
    }
};