class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        else{
            return a[1] > b[1];
        }
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        int count = 0, n = properties.size();
        sort(properties.begin(), properties.end(), comp);
        int temp = properties[n-1][1];
        
        for(int i=n-2;i>=0;i--){
            
            if(properties[i][1] < temp)
                count++;
            
            temp = max(temp, properties[i][1]);
        }
        
        return count;
    }
};