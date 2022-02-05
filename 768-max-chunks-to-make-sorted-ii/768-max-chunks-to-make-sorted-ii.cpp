class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        int answer = 1;
        
        vector<int> Max = arr, Min=arr;
        
        for(int i=1;i<n;i++)
        {
            Max[i]=max(arr[i], Max[i-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            Min[i]=min(arr[i], Min[i+1]);
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(Max[i]<=Min[i+1])
            {
                answer++;
            }
        }
        
        return answer;
    }
};