class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size();
        int distance = 0, maxDistance = INT_MIN;
        
        int i=0,k=1;
        
        while(k<n)
        {
            while(seats[k]!=1)
            {
                if(k==n-1)
                {
                    k = n-1;
                    break;
                }
                k++;   
            }
            
            if(seats[i] != 1 || seats[k]!= 1)
            {
                distance = (k-i);
            }
            else
            {
                distance = (k-i)/2;
            }
            maxDistance = max(distance, maxDistance);
            
            i=k;
            k++;
        }
        
        return maxDistance;
    }
};