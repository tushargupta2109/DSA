class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
    
        int result=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])<=abs(result))
            {
                if(abs(nums[i])==result)
                {
                    result=max(nums[i],result);
                }
                else{
                    result=nums[i];
                }
            }
        }
        return result; 
    }
};