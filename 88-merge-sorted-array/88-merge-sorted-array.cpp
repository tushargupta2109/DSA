class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0,j;
        for(j=m;j<(n+m);j++){
            nums1[j] = nums2[i++];
        }
        
        int gap = ceil(float(n+m)/2);
        while(gap>0){
            
            i=0, j=gap;
            while(j<(n+m)){
                if(nums1[i]>nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
                i++, j++;
            }
            if(gap == 1){
                gap = 0;
            }
            else{
                gap = ceil(float(gap)/2);
            }
        }
    }
};