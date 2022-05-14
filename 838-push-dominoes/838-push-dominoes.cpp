class Solution {
public:
    void solveConfiguration(char arr[], int j, int k)
    {
        if(arr[j] == 'L' && arr[k] == 'L')
        {
            for(int i=j+1;i<k;i++)
            {
                arr[i] = 'L';
            }
        }
        else if(arr[j] == 'R' && arr[k] == 'R')
        {
            for(int i=j+1;i<k;i++)
            {
                arr[i] = 'R';
            }
        }
        else if(arr[j] == 'L' && arr[k] == 'R')
        {
        }
        else
        {
            int n = k-j;
            int mid = (j+k)/2;
            if(n%2==0)
            {
                for(int i=j+1;i<mid;i++)
                {
                    arr[i] = 'R';
                }
                for(int i=mid+1;i<k;i++)
                {
                    arr[i] = 'L';
                }
            }
            else{
               for(int i=j+1;i<=mid;i++)
                {
                    arr[i] = 'R';
                }
                for(int i=mid+1;i<k;i++)
                {
                    arr[i] = 'L';
                }
            }
        }
    }
    
    string pushDominoes(string dominoes) {
        
        int n = dominoes.length();
        
        char arr[n+2];
        arr[0] = 'L', arr[n+1] = 'R';
        
        for(int i=1;i<n+1;i++)
        {
            arr[i] = dominoes[i-1];
        }
        
        int j=0, k=1;
        
        while(k < n+2)
        {
            while(arr[k]=='.')
                k++;
            
            solveConfiguration(arr,j,k);
            j = k;
            k++;
        }
        
        string ans = "";
        for(int i=1;i<n+1;i++)
        {
            ans += arr[i];
        }
        
        return ans;
    }
};