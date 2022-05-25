class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int sum = 0;
            int sub = 1;
            
            for(auto element: nums){
                sum += element;
                
                if(sum>mid){
                    sum = element;
                    sub++;
                }
            }
            
            if(sub<=m){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};