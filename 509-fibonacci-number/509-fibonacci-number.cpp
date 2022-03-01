class Solution {
public:
    int fib(int n) {
        
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }
        
        int a = 0;
        int b = 1;
        int fib = 1;
        
        for(int i=2;i<n;i++)
        {
            a = b;
            b = fib;
            fib = a+b;
        }
        return fib;
    }
};