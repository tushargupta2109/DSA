class Solution {
public:
    bool checkPalindrome(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int n = s.length();
        int i=0, j=n-1;
        
        while(i<j)
        {
            if(s[i] != s[j])
            {
                bool first = checkPalindrome(s, i+1, j);
                bool second = checkPalindrome(s, i, j-1);
                
                if(first == true || second == true)
                {
                    return true;
                }
                else{
                    return false;
                }
            }
            i++;
            j--;
        }
        
        return true;
    }
};