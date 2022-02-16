class Solution {
public:
    int kadaneOfFirstTwo(vector<int> arr)
    {
        int n=arr.size(),curr_sum = 0, max_sum = INT_MIN;
        for(int j=0;j<n*2;j++)
        {
            curr_sum += arr[j%n];
            if(curr_sum<0)
            {
               curr_sum = 0;
            }
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    
    int kadaneOfFirstOne(vector<int> arr)
    {
        int n=arr.size(),curr_sum = 0, max_sum = INT_MIN;
        for(int j=0;j<n;j++)
        {
            curr_sum += arr[j];
            if(curr_sum<0)
            {
               curr_sum = 0;
            }
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9 + 7;
        int sum =0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        
        int ans = 0;
        if(k==1)
        {
            ans= kadaneOfFirstOne(arr)%mod;
        }
        else if(sum<=0)
        {
            ans= kadaneOfFirstTwo(arr)%mod;
        }
        else if(sum>0)
        {
             ans= (kadaneOfFirstTwo(arr) + long(k-2)*sum)%mod;
        }
        
        return ans%mod;
    }
};