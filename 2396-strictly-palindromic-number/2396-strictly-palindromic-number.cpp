class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2;i<=n-2;i++){
            
            int temp = n;
            vector<int> num;
            while(temp){
                
                num.push_back(temp%i);
                temp = temp/i;
            }
            
            int j = 0, k = num.size()-1;
            while(j<=k){
                
                if(num[j++] != num[k--]){
                    return false;
                }
            }
        }
        
        return true;
    }
};