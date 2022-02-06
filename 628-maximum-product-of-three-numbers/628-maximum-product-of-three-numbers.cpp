class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
      int f, s, t;
		f = s = t = -1001;
    
		int min1, min2;
		min1 = min2 = INT_MAX;

		int size = nums.size();
		for(int i=0; i<size; i++){
			if(nums[i] >= f){
				t = s;
				s = f;
				f = nums[i];
			}else if(nums[i] >= s){
				t = s;
				s = nums[i];
			}else if(nums[i] > t)
				t = nums[i];

			if(nums[i] <= min1){
				min2 = min1;
				min1 = nums[i];
			}else if(nums[i] < min2)
				min2 = nums[i];
		}

		return max(f*s*t, min1*min2*f);
    }
};