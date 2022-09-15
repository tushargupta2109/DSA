class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n = changed.size();
        vector<int> ans;
        
        if(n%2 != 0){
            return ans;
        }
        
        sort(changed.rbegin(), changed.rend());
        unordered_map<int, int> mp;
        int cnt = 0; 
        
        for(int i=0;i<n;i++){
            
            if(mp.find(2*changed[i]) != mp.end()){
                
                ans.push_back(changed[i]);
                if(mp[2*changed[i]] > 1){
                    mp[2*changed[i]]--;
                }
                else{
                    mp.erase(2*changed[i]);
                }
            }
            else{
                mp[changed[i]]++;
            }
        }
        
        if(ans.size() != n/2){
            ans.clear();
            return ans;
        }
        return ans;
    }
};