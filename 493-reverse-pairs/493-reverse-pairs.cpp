class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums, 0, nums.size()-1);
    }
    
    int mergeSort(vector<int> &nums, int start, int end)
    {
        if(start>=end){
            return 0;
        }
        
        int mid = (start+end)/2, ans = 0;
        
        ans += mergeSort(nums, start, mid);
        ans += mergeSort(nums, mid+1, end);
        ans += merge(nums, start, mid, end);
        
        return ans;
    }
    
    int merge(vector<int>& nums, int start, int mid, int end)
    {
        int n1 = mid-start+1, n2 = end - mid, ans = 0;
        vector<int> left(n1,0);
        vector<int> right(n2,0);
        
        for(int i=0;i<n1;i++){
          left[i] = nums[start+i];  
        }
        for(int j=0;j<n2;j++){
            right[j] = nums[mid+j+1];
        }
        
         int j = mid + 1;
         for (int i = start; i <= mid; i++) {
            while (j <= end && nums[i] > (long long) 2 * nums[j]) {
                j++;
            }
            ans += (j - (mid + 1));
        }
        
        int i = 0, k=start;
        j=0;
        while(i<n1 && j<n2)
        {
            if(left[i]<=right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }
        while(i<n1){
            nums[k++] = left[i++];
        }
        while(j<n2){
            nums[k++] = right[j++];
        }
        return ans;
    }
};