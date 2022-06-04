class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int target) {
        
        int n = arr.size();
        double low = arr[0]/(double)arr[n-1];
        double high = 1;
        
        while(low<high){
            double mid = (low+high)/2;
            
            vector<int> count = f(arr, mid);
            
            if(count[0]< target){
                low = mid;
            }
            else if(count[0]>target){
                high = mid;
            }
            else{
                return {count[1], count[2]};
            }
        }
        
        return {0,0};
    }
    
    vector<int> f(vector<int> arr, double mid)
    {
        int count = 0;
        int n = arr.size();
        int i=0;
        int num = arr[0], deno = arr[n-1];
        
        for(int j=1;j<n;j++){
            while(arr[i] <= arr[j]*mid){
                i++;
            }
            count += i;
            
            if(i>0 && arr[i-1]*deno > arr[j]*num){
                num = arr[i-1];
                deno = arr[j];
            }
        }
        
        return {count, num, deno};
    }
};