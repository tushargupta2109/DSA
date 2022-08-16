class Solution {
public:
    int romanToInt(string s) {
        
        int  n = 0;
        for(int i=0;i<s.length();i++){
            
            if(s[i] == 'I'){
                if(s[i+1] == 'V' || s[i+1] == 'X'){
                    n -= 1;
                }
                else{
                    n += 1;   
                }
            }
            else if(s[i] == 'V'){
                n += 5;
            }
            else if(s[i]=='X')
            {
                if(s[i+1]=='L' || s[i+1]=='C')
                {
                    n = n-10;
                }
                else
                    n = n+10;
            }
            else if(s[i]=='L')
            {
                n += 50;
            }
            else if(s[i]=='C')
            {
                if(s[i+1]=='M' || s[i+1]=='D')
                {
                    n = n-100;
                }
                else
                    n = n+100;
            }
            else if(s[i]=='D')
            {
                n += 500;
            }
            else if(s[i]== 'M')
            {
                n+= 1000;
            }
        }
        
        return n;
    }
};