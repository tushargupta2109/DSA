class Solution {
public:
    
    bool matches(string s, string pattern){
        
        vector<char> s_hash(26, 0);
        vector<char> pattern_hash(26,0);
        
        for(int i=0;i<s.length();i++){
            
            if(s_hash[s[i] - 'a'] == 0){
                s_hash[s[i] - 'a'] = pattern[i];
            }
            
            if(pattern_hash[pattern[i] - 'a'] == 0){
                pattern_hash[pattern[i] - 'a'] = s[i];   
            }
            
            if(pattern_hash[pattern[i] - 'a'] !=  s[i] || s_hash[s[i] - 'a'] != pattern[i]){
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            if(matches(words[i], pattern)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};