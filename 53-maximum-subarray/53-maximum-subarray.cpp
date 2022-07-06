class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(), Max = INT_MIN, count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0){
                count++;
            }
            Max = max(Max,nums[i]);
        }
        
        if(count == n)
        {
            return Max;
        }
        if(n==1)
        {
            return nums[0];
        }
        
        int currSum = 0, maxSum = INT_MIN;
        
        for(int i=0;i<n;i++){
            currSum += nums[i];
            
            if(currSum<0){
                currSum = 0;
            }
            
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};