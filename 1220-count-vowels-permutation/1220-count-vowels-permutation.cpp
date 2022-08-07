class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<int> prev(5,1);
        int mod  = 1e9 + 7;
        
        for(int i=1;i<n;i++){
            
            vector<int> curr(5,0);
            for(int j=0;j<5;j++){
                
                switch(j){
                    case 0:
                        curr[1] = (curr[1] + prev[0])%mod;
                        break;
                    case 1:
                        curr[0] = (curr[0] + prev[1])%mod;
                        curr[2] = (curr[2] + prev[1])%mod;
                        break;
                    case 2:
                        curr[0] = (curr[0] + prev[2])%mod;
                        curr[1] = (curr[1] + prev[2])%mod;
                        curr[3] = (curr[3] + prev[2])%mod;
                        curr[4] = (curr[4] + prev[2])%mod;
                        break;
                    case 3:
                        curr[2] = (curr[2] + prev[3])%mod;
                        curr[4] = (curr[4] + prev[3])%mod;
                        break;
                    case 4:
                        curr[0] = (curr[0] + prev[4])%mod;
                        break;
                }
            }
            prev = curr;
        }
        
        int sum = 0;
        for(int i=0;i<5;i++){
            sum = (sum + prev[i])%mod;
        }
        
        return sum;
    }
};