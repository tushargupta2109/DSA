class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n==1){
            return true;
        }
        if(n<=2){
            return false;
        }
        
        int rem = 0;
        
        while(n>2){
            rem = n%3;
            n=n/3;
            if(rem!=0){
                return false;
            }
        }
        
        if(rem == 0 && n==1){
            return true;
        }
        return false;
    }
};