class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        if(n==1){
            return "";
        }
        
        for(int i=0;i<n;i++){
            
            if(i==n-1 && palindrome[i] == 'a'){
                palindrome[i] = 'b';
                break;
            }
            if(palindrome[i] != 'a' && palindrome[n-i-1] != 'a' && i!=n/2){
                
                palindrome[i] = 'a';
                break;
            }
        }
        
        return palindrome;
    }
};