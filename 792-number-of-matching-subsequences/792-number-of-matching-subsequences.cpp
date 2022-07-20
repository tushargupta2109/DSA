class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int count = 0;
        vector<int> cache[26];
        
        for(int i=0;i<s.length();i++){
            cache[s[i] - 'a'].push_back(i);
        }
        
        for(auto str:words){
            
            int prev_char_index = -1;
            for(int i=0;i<str.length();i++){
                
                auto itr = upper_bound(cache[str[i] - 'a'].begin(), cache[str[i] - 'a'].end(), prev_char_index);
                if(itr == cache[str[i] - 'a'].end()){
                  goto h;  
                }
                
                prev_char_index = *itr;
            }
            count++;
            h:;
        }
        
        return count;
    }
};