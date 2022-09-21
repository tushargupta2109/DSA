class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size(), max_candies = 0;
        vector<bool> ans(n);
        
        for(int i=0;i<n;i++){
            
            max_candies = max(max_candies, candies[i]);
        }
        
        for(int i=0;i<n;i++){
            
            ans[i] = candies[i] + extraCandies >= max_candies ? true : false;
        }
        
        return ans;
    }
};