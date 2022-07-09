class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        int n = intervals.size();
        
        if(n==0){
            return ans;
        }
        
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        
        for(auto itr : intervals){
            if(itr[0] <= tempInterval[1]){
                tempInterval[1] = max(itr[1], tempInterval[1]);
            }
            else{
                ans.push_back(tempInterval);
                tempInterval = itr;
            }
        }
        ans.push_back(tempInterval);
        return ans;
    }
};