class Solution {
public:
    int sumSubseqWidths(vector<int>& arr) {
        
        long ans=0;
        long mod=1000000007;
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        vector<long>pow(n,1);
        
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        
        for(int i=0;i<n;i++){
            
            ans=(ans+arr[i]*(pow[i]-pow[n-i-1]))%mod;
        }
        
        return ans;
    }
};