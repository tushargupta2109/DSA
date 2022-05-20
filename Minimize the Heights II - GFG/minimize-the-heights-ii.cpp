// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr, arr+n);
        int min_n = arr[0]+k;
        int max_n = arr[n-1]-k;
        int ans = arr[n-1]-arr[0];
        
        for(int i=0;i<n-1;i++)
        {
            int max_a = max(max_n, arr[i]+k);
            int min_a = min(min_n, arr[i+1]-k);
            
            if(min_a < 0)
            {
                continue;
            }
            
            ans = min(ans, max_a - min_a);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends