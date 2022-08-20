class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        vector<int> dp(n+1);
        dp[n] = true;
        unordered_map<string, int> mp;
        
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        
        for(int i=n-1;i>=0;i--){
            
            string temp;
            for(int j=i;j<n;j++){
                
                temp += s[j];
                if(mp.find(temp) != mp.end() && dp[j+1] == true){
                    
                    dp[i] = true;
                }
            }
        }
        
        return dp[0];
    }
};