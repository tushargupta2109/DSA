// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        
        int w = 0, h = 0;
        for (int i = 0; i < n; i++) if (arr[i] <= k) w++;
        for (int i = 0; i < w; i++) if (arr[i] > k) h++;
        int min_h = h;
        for (int i = 0; i + w < n; i++) {
            if (arr[i] > k) h--;
            if (arr[i + w] > k) h++;
            min_h = min(min_h, h);
        }
        return min_h;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends