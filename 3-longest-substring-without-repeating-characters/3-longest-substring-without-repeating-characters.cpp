class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mp;
        int ans  = 0, left = 0, right=0;
        
        while(right<s.length())
        {
            if(mp.find(s[right]) != mp.end()){
                left=max(left, mp[s[right]] + 1);
            }
            ans = max(ans, right-left+1);
            
            mp[s[right]] = right;
            right++;
        }
        
        return ans;
    }
};