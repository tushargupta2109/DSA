class Solution {
public:
    
    int solve(vector<vector<vector<int>>> &dp, vector<int>& piles, int f_idx, int b_idx, bool turn){
        
        if(f_idx > b_idx){
            return 0;
        }
        
        if(dp[f_idx][b_idx][turn] != -1){
            return dp[f_idx][b_idx][turn];
        }
        
        int sum = 0;
        if(!turn){
            
            sum = max(piles[f_idx] + solve(dp, piles, f_idx+1, b_idx, 1), piles[b_idx] + solve(dp, piles, f_idx, b_idx-1, 1));
        }
        else{
            sum = max(piles[f_idx] + solve(dp, piles, f_idx+1, b_idx, 0), piles[b_idx] + solve(dp, piles, f_idx, b_idx-1, 0));
        }
        
        return dp[f_idx][b_idx][turn] = sum;
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        
        int alice_score = solve(dp, piles, 0, n-1, 0);
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += piles[i];
        }
        
        int bob_score=sum-alice_score;
        return bob_score>alice_score ? false : true;
    }
};