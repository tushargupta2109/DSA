class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        int ans = 1, helper = 1, prev = nums[0];
        for(int i=1;i<n;i++)
        {
            if( nums[i] == prev+1){
                helper++;
            }
            else if(nums[i]!=prev){
                helper = 1;
            }
            prev = nums[i];
            ans = max(ans, helper);
        }
        
        return ans;
    }
};