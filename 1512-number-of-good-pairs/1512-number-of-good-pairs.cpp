class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        vector<int> freq(101, 0);
        
        for(int i=0;i<n;i++){
            
            freq[nums[i]]++;
        }
        
        for(int i=1;i<101;i++){
            
            if(freq[i] > 1){
                ans += (freq[i]*(freq[i] - 1))/2;
            }
        }
        
        return ans;
    }
};