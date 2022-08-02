class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        
        while(low<=high){
            
            int mid = (low+high)/2;
            int count = getRank(matrix, mid);
            
            if(count<k){
                low = mid +1;
            }
            else{
                high = mid - 1;
            }
        }  
        return low;
    }
    
    int getRank(vector<vector<int>>& matrix, int target){
        
        int n = matrix.size();
        int i = n-1, j = 0, count = 0;
        
        while(i>=0 && j<n){
            
            if(matrix[i][j] > target){
                i--;
            }
            else{
                count += i+1;
                j++;
            }
        }
        
        return count;
    }
};