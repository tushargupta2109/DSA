class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        int count = 0;
        long long int sum1=0,sum2=0;
        
        vector<int>sorted (n,0);
        for(int i=0;i<n;i++){
            sorted[i]=arr[i];
        }
        sort(sorted.begin(), sorted.end());
        
        for(int i=0;i<n;i++)
        {
            sum1 += sorted[i];
            sum2 += arr[i];
            
            if(sum1 == sum2)
            {
                count++;
            }
        }
        
        return count;
    }
};