class Solution {
public:
    bool divisorGame(int n) {
        
        vector<bool> dp(n+1, false);
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=(i/2);j++){
                
                if(i%j == 0){
                    if(dp[i-j] == false){
                        dp[i] = true;
                        break;
                    }   
                }
            }
        }
        
        return dp[n];
    }
};