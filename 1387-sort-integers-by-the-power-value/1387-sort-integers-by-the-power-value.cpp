class Solution {
public:
    
    int solve(vector<int> &dp, int n){
        
        if(n==1){
            return 0;
        }
        
        if(dp[n] != 0){
            return dp[n];
        }
        if(n%2 == 0){
            return dp[n] = 1 + solve(dp, n/2);
        }
        else{
            return dp[n] = 1 + solve(dp, 3*n + 1);
        }
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<int> dp(900001, 0);
        
        for(int i=lo;i<=hi;i++){
            
            solve(dp, i);
        }
        
        vector<pair<int,int>> arr;
        for(int i=lo;i<=hi;i++){
            
            arr.push_back(make_pair(dp[i], i));
        }
        
        sort(arr.begin(), arr.end());
        
        return arr[k-1].second;
    }
};