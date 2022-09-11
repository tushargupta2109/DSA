class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> engineer(n);
        
        for(int i=0;i<n;i++){
            
            engineer.push_back(make_pair(efficiency[i], speed[i]));
        }
        
        sort(engineer.rbegin(), engineer.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int mod = 1e9 + 7;
        long sum = 0, ans = 0;
        
        for(int i=0;i<n;i++){
            
            pq.push(engineer[i].second);
            
            sum += engineer[i].second;
            
            if(pq.size() > k){
                
                sum -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, sum*engineer[i].first);
        }
        
        return ans%mod;
    }
};