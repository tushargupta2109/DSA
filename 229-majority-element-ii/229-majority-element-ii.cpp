class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int first=-1,second=-1;
        int a=0, b=0;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==first){
                a++;
            }
            else if(nums[i]==second)
            {
                b++;
            }
            else if(a==0){
                first = nums[i];
                a=1;
            }
            else if(b==0)
            {
                second = nums[i];
                b=1;
            }
            else{
                a--;
                b--;
            }
        }
        
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==first)
            {
                c1++;
            }
            else if(nums[i]==second)
            {
                c2++;
            }
        }
        
        vector<int> ans;
        if(c1>n/3)
        {
            ans.push_back(first);
        }
        if(c2>n/3)
        {
            ans.push_back(second);
        }
        
        return ans;
    }
};