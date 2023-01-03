//396. Rotate Function
//https://leetcode.com/problems/rotate-function/submissions/870539281/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=i*nums[i];
            sum+=nums[i];
        }
        int res=curr;
        for(int i=0;i<n;i++)
        {
            // remove the last item n times (as 1 times it is also added in sum && n-1 for index)
            curr-=n*nums[n-i-1];
            curr+=sum;
            res=max(res,curr);
        }
        return res;
    }
};