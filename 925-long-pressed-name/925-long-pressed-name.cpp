class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int i=0, j=0;
        int n = name.size(), m = typed.size();
        
        if(name[0] != typed[0])
        {
            return false;
        }
        
        while(i<n && j<m)
        {
            int count = -1;
            while(typed[j]==name[i] && j<m)
            {
                j++;
                count++;
            }
            
            i++;
            if(name[i] == name[i-1])
            {
                while(name[i] == name[i-1])
                {
                    i++;
                    count--;
                    if(count<0)
                    {
                        return false;
                    }
                }
            }
            if(typed[j] != name[i])
            {
                return false;
            }
        }
        
        return true;
    }
};