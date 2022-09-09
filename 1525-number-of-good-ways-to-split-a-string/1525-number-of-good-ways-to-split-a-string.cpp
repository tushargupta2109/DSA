class Solution {
public:
    int numSplits(string s) {
        
        int n = s.length();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> freq(26, 0);
        
        left[0] = right[n-1] = 1;
        freq[s[0] - 'a']++;
        for(int i=1;i<n;i++){
            
            if(freq[s[i] - 'a'] == 0){
                
                left[i] = left[i-1] + 1;
            }
            else{
                left[i] = left[i-1];
            }
            freq[s[i] - 'a']++;
        }
        
        vector<int> freq2(26, 0);
        freq2[s[n-1] - 'a']++;
        
        for(int i=n-2; i>=0; i--){
        
            if(freq2[s[i] - 'a'] == 0){
                
                right[i] = right[i+1] + 1;
            }
            else{
                right[i] = right[i+1];
            }
            freq2[s[i] - 'a']++;
        }
        
        int count = 0;
        for(int i=0;i<n-1;i++){
            
            if(left[i] == right[i+1])
                count++;
        }
        
        return count;
    }
};