class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int re = n-1;
        int rf = 0;
        int cf = 0;
        int ce =m-1;
        
        vector<int> ans;
        
        while(rf<=re && cf<=ce)
        {
            for(int i=cf;i<=ce;i++)
            {
                ans.push_back(matrix[rf][i]);
            }
            rf++;
            
            for(int i=rf;i<=re;i++)
            {
                ans.push_back(matrix[i][ce]);
            }
            ce--;
            
            if(rf<=re && cf<=ce)
            {
                for(int i=ce;i>=cf;i--)
                {
                    ans.push_back(matrix[re][i]);
                }
                re--;
                
                for(int i=re;i>=rf;i--)
                {
                    ans.push_back(matrix[i][cf]);
                }
                cf++;
            }
        }
        return ans;
    }
};