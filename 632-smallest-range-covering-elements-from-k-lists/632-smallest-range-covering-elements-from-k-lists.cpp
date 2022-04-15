class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int> ans;
        int mx = INT_MIN, minlen = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],i,0});
            mx = max(mx,nums[i][0]);
        }
        
        while(pq.size())
        {
            if(mx-pq.top()[0]<minlen)
            {
                ans = {pq.top()[0],mx};
                minlen =  mx-pq.top()[0];
            }
            
            int i = pq.top()[1], j = pq.top()[2];
            pq.pop();
            
            if(j+1<nums[i].size())
            {
                pq.push({nums[i][j+1],i,j+1});
                mx=max(mx,nums[i][j+1]);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};