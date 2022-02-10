class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int n = nums.size();
        int count = 0;
        int Max = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                count++;
            }
            Max = max(Max,nums[i]);
        }
        
        if(count == n)
        {
            return Max;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        int max_sum = INT_MIN;
        int curr_sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            curr_sum += nums[i]; 
            if(curr_sum<0)
            {
                curr_sum = 0;
            }
            max_sum = max(max_sum, curr_sum);
        }
        
        return max_sum;
    }
};