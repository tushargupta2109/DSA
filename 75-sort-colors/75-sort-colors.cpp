class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0, j = nums.size()-1, mid =0;
        
        while(mid<=j){
            if(nums[mid] == 2){
                swap(nums[mid], nums[j--]);
            }
            else if(nums[mid] == 0){
                swap(nums[mid++], nums[i++]);
            }
            else{
                mid++;
            }
        }
    }
};