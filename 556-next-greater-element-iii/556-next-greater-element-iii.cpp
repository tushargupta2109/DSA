class Solution {
public:
    int nextGreaterElement(int n) {
        int temp = n;

        vector<int> v;

        while (n)
        {
            int digit = n % 10;
            n = n / 10;
            v.push_back(digit);
        }

        long long int ans = 0;
        reverse(v.begin(), v.end());
        int i;

        for (i = v.size() - 1; i > 0; i--)
        {
            if (v[i - 1] < v[i])
            {
                break;
            }
        }

        if (i == 0)
        {
            return -1;
        }

        int smallest = i, x = v[i - 1];
        for (int k = i + 1; k < v.size(); k++)
        {
            if (v[k] > x && v[k] < v[smallest])
            {
                smallest = k;
            }
        }

        int t = v[smallest];
        v[smallest] = v[i - 1];
        v[i - 1] = t;

        sort(v.begin() + i, v.end());

        for (int i = 0; i < v.size(); i++)
        {
            ans = ans * 10 + v[i];
        }

        if (ans > INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};