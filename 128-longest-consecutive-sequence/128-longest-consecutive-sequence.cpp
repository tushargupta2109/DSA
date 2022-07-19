class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> hashSet;
        
        for(int num: nums){
            hashSet.insert(num);
        }
        
        int maxStreak = 0;
        for(int num: nums){
            
            if(!hashSet.count((num-1))){
                
                int currentNum = num, currentStreak = 1;
                while(hashSet.count(currentNum+1)){
                    currentNum++;
                    currentStreak++;
                }
                maxStreak = max(maxStreak, currentStreak);
            }
            
        }
        
        return maxStreak;
    }
};