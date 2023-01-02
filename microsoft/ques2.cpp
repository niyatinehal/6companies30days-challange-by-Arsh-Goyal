//combination sum III
//https://leetcode.com/problems/combination-sum-iii/submissions/869578530/

class Solution {
    private:
    void helper(int index,int sum,int n,int k, vector<int>& ans1,vector<vector<int>>& ans2){
        if(sum==n && k==0){
            ans2.push_back(ans1);
            return;
        }
        if(sum>n){
            return;
        }
        for(int i=index;i<=9; i++){
            if(i>n){
                break;
            }
            ans1.push_back(i);
            helper(i+1,sum+i,n,k-1,ans1,ans2);
            ans1.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int>ans1;
         vector<vector<int>>ans2;
         helper(1,0,n,k,ans1,ans2);
         return ans2;
    }
};