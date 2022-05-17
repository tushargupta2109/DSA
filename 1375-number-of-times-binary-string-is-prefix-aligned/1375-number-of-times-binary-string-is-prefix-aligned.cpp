class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        
        int n = flips.size();
        
        int answer = 0, max_n = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(flips[i] > max_n)
            {
                max_n = flips[i];
            }
            
            if(max_n == i+1)
                answer++;
        }
        
        return answer;
    }
};