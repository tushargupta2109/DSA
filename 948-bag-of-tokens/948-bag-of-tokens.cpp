class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int n = tokens.size();
        int i=0, j = n-1, score = 0;
        
        while(i<=j){
            
            if(tokens[i] <= power){
                
                power -= tokens[i];
                score++;
                i++;
            }
            else if(score>0 && i!=j){
                power += tokens[j];
                score--;
                j--;
            }
            else{
                return score;
            }
        }
        
        return score;
    }
};