class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n==0){
            return;
        }
        
        int j;
        for(int i=0;i<m;i++){
            if(nums1[i] > nums2[0]){
                swap(nums1[i], nums2[0]);
            }
            
            int first = nums2[0];
            for(j=1;j<n && nums2[j]<first;j++){
                nums2[j-1] = nums2[j];
            }
            nums2[j-1] = first;
        }
        
        j =0;
        for(int i=m;i<(n+m);i++){
            nums1[i] = nums2[j++];
        }
    }
};