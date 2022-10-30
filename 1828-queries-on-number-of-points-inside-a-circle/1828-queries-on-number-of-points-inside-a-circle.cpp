class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        int queries_size = queries.size(), point_size = points.size();
        vector<int> ans;
        
        for(int i=0;i<queries_size;i++){
            
            int count = 0;
            for(int j=0;j<point_size;j++){
                
                if(sqrt(pow((queries[i][0] - points[j][0]), 2) + pow((queries[i][1] - points[j][1]), 2)) <= queries[i][2]){
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};