class Solution {
public:
    
//     int solve(vector<int> arr, int k, int idx, vector<int> dp){
        
//         int n = arr.size();
//         if(idx == n){
//             return 0;
//         }
        
//         if(dp[idx] != -1){
//             return dp[idx];
//         }
        
//         int temp = INT_MIN, len = 0, res = INT_MIN;
//         for(int i=idx;i<min(n, idx+k);i++){
            
//             len++;
//             temp = max(temp, arr[i]);
//             res = max(res, temp*len + solve(arr, k, i+1, dp));
//         }
        
//         return dp[idx] = res;
//     }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1;i>=0;i--){
            int temp = INT_MIN, len = 0, res = INT_MIN;
            for(int j=i;j<min(n, i+k);j++){

                len++;
                temp = max(temp, arr[j]);
                res = max(res, temp*len + dp[j+1]);
            }
            dp[i] = res;
        }
                          
        return dp[0];
    }
};