class Solution {
public:
    
    int dp[101][101][601];
    
    int solve(vector<string>& strs, int m, int n, int idx){
        
        if(idx == strs.size()){
            return 0;
        }
        
        if(dp[m][n][idx] != -1){
            return dp[m][n][idx];
        }
        
        string word = strs[idx];
        int one_count = 0, zero_count = 0;
        for(int i=0; i<word.length();i++){
            
            if(word[i] == '1'){
                one_count += 1;
            }
            else{
                zero_count += 1;
            }
        }
        
        if(n-one_count>=0 && m-zero_count>=0){
            return dp[m][n][idx] = max(1 + solve(strs, m-zero_count, n-one_count, idx+1), solve(strs, m, n, idx+1));
        }
        else{
            return dp[m][n][idx] = solve(strs, m, n, idx+1);
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs, m, n, 0);
    }
};