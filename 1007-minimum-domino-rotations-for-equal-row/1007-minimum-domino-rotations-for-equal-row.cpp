class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int top[7] = {0};
        int bottom[7] = {0};
        
        for(int i=0;i<tops.size();i++)
        {
            top[tops[i]]++;
        }
        
        for(int i=0;i<bottoms.size();i++)
        {
            bottom[bottoms[i]]++;
        }
        
        int top_max = INT_MIN;
        int bottom_max = INT_MIN;
        int top_index, bottom_index;
        for(int i=1;i<7;i++)
        {
            if(top_max < top[i])
            {
                top_max = top[i];
                top_index = i;
            }
        }
        for(int i=1;i<7;i++)
        {
            if(bottom_max < bottom[i])
            {
                bottom_max = bottom[i];
                bottom_index = i;
            }
        }
        
        int answer = 0;
        if(top_max > bottom_max)
        {
            for(int i=0;i<tops.size();i++)
            {
                if(tops[i]!=top_index)
                {
                    if(bottoms[i]==top_index)
                    {
                        answer++;
                    }
                    else{
                        return -1;
                    }
                }
                else{
                    continue;
                }
            }
        }
        else{
            for(int i=0;i<bottoms.size();i++)
            {
                if(bottoms[i]!=bottom_index)
                {
                    if(tops[i]==bottom_index)
                    {
                        answer++;
                    }
                    else{
                        return -1;
                    }
                }
                else{
                    continue;
                }
            }
        }
        
        return answer;
    }
};