//2344. Minimum Deletions to Make Array Divisible
//https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int n = nums.size(), nd = numsDivide.size();
        sort(nums.begin(), nums.end());
        int g = numsDivide[0];
        for (int i = 0; i < nd; i++)
            g = gcd(g, numsDivide[i]);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > g)
                return -1;
            if (g % nums[i] == 0)
                return i;
        }
        return -1;
    }
};;