class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        int answer = 0;
        vector<int> max(n,0);
        max[0]=arr[0];
        if(arr[0]==0)
        {
            answer++;
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max[i-1])
            {
                max[i]=arr[i];
            }else{
                max[i]=max[i-1];
            }
            if(max[i]==i)
            {
                answer++;
            }
        }
        
        return answer;
    }
};