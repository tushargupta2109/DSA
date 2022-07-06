class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), min_element = INT_MAX, max_sum = INT_MIN;
        
        for(int i=0;i<n;i++){
            min_element = min(min_element, prices[i]);
            max_sum = max(max_sum, prices[i]-min_element);
        }
        
        return max_sum;
    }
};