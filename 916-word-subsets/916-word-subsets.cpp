class Solution {
public:
    
    bool check(string word, vector<int> freq){
            
        for(auto ch:word){
            
            if(freq[ch - 'a'] == 0){
                continue;
            }
            else{
                freq[ch - 'a']--;
            }
        }
        
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i] != 0){
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> freq(26,0);
        vector<string> ans;
        
        for(char i='a'; i<= 'z'; i++)
        {
            for(auto j:words2){
                
                int cnt = 0;
                for(auto k:j){

                    if(k==i){
                        cnt++;
                    }
                }
                
                freq[i-'a'] = max(freq[i - 'a'], cnt);
            }
        }
        
        for(auto word:words1){
            
            if(check(word, freq)){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};