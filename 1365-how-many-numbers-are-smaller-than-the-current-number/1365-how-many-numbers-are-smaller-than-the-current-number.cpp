class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        vector<int> temp = nums;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
        }
        
        for(int i=0;i<n;i++){
            
            nums[i] = mp[temp[i]];
        }
        
        return nums;
    }
};