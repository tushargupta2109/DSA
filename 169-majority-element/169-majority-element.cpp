class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans = nums[0], freq = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans){
                freq++;
            }
            else{
                if(freq == 1){
                    ans = nums[i];
                }
                else{
                    freq--;
                }
            }
        }
        
        return ans;
    }
};