class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX, second = INT_MAX, n = nums.size();
        if(n < 3){
            return false;
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i] > second && second > first){
                return true;
            }
            else if(nums[i] > first && nums[i] < second){
                second = nums[i];
            }
            else if(nums[i] < first){
                first = nums[i];
            }
        }
        
        return false;
    }
};