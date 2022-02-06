class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
        {
            return 0;
        }
        
        int value = INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>value)
            {
                value = nums[i];
                index = i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==index)
            {
                continue;
            }
            
            if(value>=2*nums[i]){
                continue;
            }
            else{
                return -1;
            }
        }
        
        return index;
        
    }
};