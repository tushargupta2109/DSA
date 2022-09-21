class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int max_length = 0;
        for(int i=0;i<sentences.size();i++){
            
            int curr_length = 1;
            for(int j=0;j<sentences[i].length();j++){
                
                if(sentences[i][j] == ' '){
                    curr_length++;
                }
            }
            max_length = max(max_length, curr_length);
        }
        
        return max_length;
    }
};