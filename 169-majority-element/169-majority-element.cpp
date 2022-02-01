class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int answer = nums[0];
        int c = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==answer)
            {
                c++;
            }
            else{
                if(c==1)
                {
                    answer = nums[i];
                }
                else{
                    c--;
                }
            }
        }
        
        return answer;
    }
};