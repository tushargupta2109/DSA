class Solution {
public:
    int getSecondSum(vector<int>& nums, int i, int j, int secondLen)
    {
        int n = nums.size(), sum;
        int k=i, z = i+secondLen-1;
        
        int max_sum = INT_MIN;
        
        while(z<=j)
        {
            sum=0;
            
            for(int q=k;q<=z;q++)
            {
                sum += nums[q];
            }
                
            max_sum = max(max_sum, sum);
            
            k++;
            z++;
        }
        return max_sum;
    }
    
    int maxSumTwoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int i=0, j=(firstLen - 1);
        int n = nums.size();
        
        int max_sum = INT_MIN;
        
        while(j<n)
        {
            int sum=0;
            
            for(int k=i;k<=j;k++)
            {
                sum += nums[k];
            }
            
            int sum_second = 0;
            if(secondLen <=i)
            {
                sum_second = getSecondSum(nums, 0, i-1, secondLen);
            }
            
            if(secondLen < (n-j)){
                sum_second = getSecondSum(nums, j+1, n-1, secondLen);
            }
            sum += sum_second;
                
            max_sum = max(max_sum, sum);
            
            i++;
            j++;
        }
        return max_sum;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int sum1 = maxSumTwoOverlap(nums,firstLen, secondLen);
        int sum2 = maxSumTwoOverlap(nums,secondLen, firstLen);
        
        int max_sum = max(sum1, sum2);
        return max_sum;
    }
};