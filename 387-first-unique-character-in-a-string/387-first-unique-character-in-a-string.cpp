class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> char_map(26, 0);
        int n = s.length();
        
        for(int i=0;i<n;i++){
            
            char_map[s[i] - 'a']++;
        }
        
        for(int i=0;i<n;i++){
            
            if(char_map[s[i]- 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};