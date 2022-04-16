class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n= nums.size();
        
        int ans = nums[0];
        int max_till_now = nums[0], min_till_now=nums[0];
        
        for(int i=1;i<n;i++)
        {
            int temp = max({nums[i], max_till_now*nums[i], min_till_now*nums[i]});
            min_till_now = min({nums[i], max_till_now*nums[i], min_till_now*nums[i]});
            max_till_now = temp;
            ans = max(ans, max_till_now);
        }
        return ans;
    }
};