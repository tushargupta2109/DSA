class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> a;
        
        for(int i=0;i<=rowIndex;i++)
        {  
            vector<int> b(i+1, 1);
            
            for(int j=1;j<i;j++)
            {
                b[j] = a[i-1][j-1] + a[i-1][j];
            }
            a.push_back(b);
        }
        
        return a[rowIndex];
    }
};