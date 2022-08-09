class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n = arr.size(), mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        
        vector<long> dp(n, 1);
        
        unordered_map<int, int> idx;
        for(int i=0;i<n;i++){
            
            idx[arr[i]] = i; 
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(arr[i] % arr[j] == 0){
                    
                    int right = arr[i]/arr[j];
                    if(idx.find(right) != idx.end()){
                        
                        dp[i] += dp[j]*dp[idx[right]];
                    }
                }
                
            }
        }
        
        long ans = 0;
        for(int i=0;i<n;i++){
            ans += dp[i];
        }
        
        return ans%mod;
    }
};