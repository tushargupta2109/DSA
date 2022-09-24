class Solution {
public:
    string reverseWords(string s) {
        
        int start = 0, end = 0, n = s.length();
        for(int i=0;i<n;i++){
            
            if(s[i]!= ' '){
                
                end++;
            }
            
            if(s[i] == ' ' || i==n-1){
                
                end = end - 1;
                while(end>start){
                    
                    swap(s[start++], s[end--]);
                }
                
                start = i+1;
                end = i+1;
            }
        }
        
        return s;
    }
};