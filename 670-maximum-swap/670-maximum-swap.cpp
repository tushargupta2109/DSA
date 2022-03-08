class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr(10,0);
        string s = to_string(num);
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            arr[s[i] - '0'] = i;
        }
        
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            int digit = s[i] - '0';
            for(int k = 9; k>digit; k--)
            {
                if(arr[k]>i)
                {
                    int temp = s[i];
                    s[i] = s[arr[k]];
                    s[arr[k]] = temp;
                    flag = true;
                    break;
                }
            }
             if(flag){
                break;
            }
        }
        
        return stoi(s);
    }
};