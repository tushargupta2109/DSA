class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size())
            return false;
        
        vector<int> temp(26, 0);
        
        for(int i=0;i<s.length();i++){
            
            temp[s[i] - 'a']++;
        }
        
        for(int i=0;i<t.size();i++){
            
            if(temp[t[i] - 'a'] > 0){
                temp[t[i] - 'a']--;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};