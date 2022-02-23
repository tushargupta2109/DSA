class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        
        vector<int> answer;
        
        vector<int> v(26,0);
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'] = i;
        }
        
        int start=0, end=0;
            
        for(int i=0;i<n;i++)
        {
            end = max(end, v[s[i]-'a']);
            if(end == i)
            {
                answer.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return answer;
    }
};