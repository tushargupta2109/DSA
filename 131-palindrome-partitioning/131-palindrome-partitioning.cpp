class Solution {
public:
    
    bool isPalindrome(int idx, int end, string s){
        
        while(idx < end){
            if(s[idx] == s[end]){
                idx++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    void solve(int idx, string s, vector<string> &path, vector<vector<string>> &res){
        
        if(idx == s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(idx, i, s)){
                path.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> path;
        solve(0, s, path, res);
        return res;
    }
};