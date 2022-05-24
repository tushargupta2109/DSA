class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        
        int ans;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int cargoSum = 0;
            int daysCount = 1;
            for(auto cargo: weights)
            {
                cargoSum += cargo;
                
                if(cargoSum > mid)
                {
                    daysCount++;
                    cargoSum = cargo;
                }
            }
            
            if(daysCount <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};