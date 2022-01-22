class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
    int n = nums.size();
    vector<int> ans(n, 0);
    int i = 0, j = n - 1;

    for (int k = 0; k < n; k++)
    {
        if (nums[k] < 0)
        {
            nums[k] *= -1;
        }
        else
        {
            break;
        }
    }

    for (int k = n - 1; k >= 0 && i <= j; k--)
    {
        if (nums[i] <= nums[j])
        {
            ans[k] = nums[j];
            j--;
        }
        else
        {
            ans[k] = nums[i];
            i++;
        }
    }

    for (int k = 0; k < n; k++)
    {
        ans[k] *= ans[k];
    }

    return ans;
    }
};