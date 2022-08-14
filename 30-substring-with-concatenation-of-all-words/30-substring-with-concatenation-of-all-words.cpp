class Solution {
public:
    
    bool checkSubstring(unordered_map<string, int> mp, string s, int wordLength){
        
        for(int i=0;i<s.size();i+=wordLength){
            
            string str = s.substr(i, wordLength);
            if(mp.find(str) != mp.end()){
                if(--mp[str] == -1){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map<string, int> mp;
        vector<int> res;
        int Wordlength = words[0].size();
        int Wordwindow = Wordlength*words.size();
        int sLength = s.size();
        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        int i=0;
        while(i+Wordwindow <= sLength){
            if(checkSubstring(mp, s.substr(i,Wordwindow),Wordlength)){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};