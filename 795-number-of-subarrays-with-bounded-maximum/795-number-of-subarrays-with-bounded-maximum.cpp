class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n = nums.size();
        int check = 0, answer = 0, uncheck=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=right)
            {
                check++;
                answer = answer + check;
            }
            else{
                check=0;
            }
            
            if(nums[i]<left)
            {
                uncheck++;
                answer -= uncheck;
            }
            else{
                uncheck=0;
            }
        }
        
        return answer;
    }
};