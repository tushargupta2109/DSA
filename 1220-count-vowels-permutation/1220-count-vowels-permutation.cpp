class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<vector<int>> dp(n, vector<int> (5, 0));
        int mod  = 1e9 + 7;
        
        for(int i=0;i<5;i++){
            
            dp[0][i] = 1;
        }
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<5;j++){
                
                switch(j){
                    case 0:
                        dp[i][1] = (dp[i][1] + dp[i-1][0])%mod;
                        break;
                    case 1:
                        dp[i][0] = (dp[i][0] + dp[i-1][1])%mod;
                        dp[i][2] = (dp[i][2] + dp[i-1][1])%mod;
                        break;
                    case 2:
                        dp[i][0] = (dp[i][0] + dp[i-1][2])%mod;
                        dp[i][1] = (dp[i][1] + dp[i-1][2])%mod;
                        dp[i][3] = (dp[i][3] + dp[i-1][2])%mod;
                        dp[i][4] = (dp[i][4] + dp[i-1][2])%mod;
                        break;
                    case 3:
                        dp[i][2] = (dp[i][2] + dp[i-1][3])%mod;
                        dp[i][4] = (dp[i][4] + dp[i-1][3])%mod;
                        break;
                    case 4:
                        dp[i][0] = (dp[i][0] + dp[i-1][4])%mod;
                        break;
                }
            }
        }
        
        long long int sum = 0;
        for(int i=0;i<5;i++){
            sum = (sum + dp[n-1][i])%mod;
        }
        
        return sum;
    }
};