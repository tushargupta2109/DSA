class Solution {
public:
    int numTeams(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for(int i=1;i<n;i++){
            int count = 0;
            
            for(int j=0;j<i;j++){
                
                if(arr[j] < arr[i])
                    count++;
            }
            
            left[i] = count;
        }
        
        for(int i=n-2;i>=0;i--){
            int count = 0;
            
            for(int j=n-1;j>i;j--){
                
                if(arr[j] < arr[i])
                    count++;
            }
            
            right[i] = count;
        }
        
        int ans = 0;
        for(int i=1;i<n;i++){
            
            for(int j=0;j<i;j++){
                
                if(arr[j] < arr[i])
                    ans += left[j];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            
            for(int j=n-1;j>i;j--){
                
                if(arr[j] < arr[i])
                     ans += right[j];
            }
        }
        
        return ans;
    }
};