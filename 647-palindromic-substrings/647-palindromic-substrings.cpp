class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i=0;i<n;i++){
            
            for(int d=0,j=i;j<n;j++,d++){
                
                if(i==0){
                    dp[d][j] = true;
                    ans++;
                }
                else if(i==1){
                    if(s[d] == s[j]){
                        dp[d][j] = true;
                        ans++;
                    }
                }
                else{
                   if(s[d] == s[j]){
                       if(dp[d+1][j-1]){
                           ans++;
                           dp[d][j] = true;
                       }
                   } 
                }
            }
        }
        
        return ans;
    }
};