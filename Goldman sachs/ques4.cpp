//447. Number of Boomerangs
//https://leetcode.com/problems/number-of-boomerangs/description/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int ans=0;
         for(int i=0;i<points.size();i++)
         {
             unordered_map<int,int>mp;
             for(int j=0;j<points.size();j++)
             {
                 if (i==j)
                 {
                    continue;
                 }
                 else
                 {
                    int dis= pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                    mp[dis]++;

                 }
             }
             for(auto &it:mp)
             {
                ans+=it.second*(it.second-1);
             }
         }   
         return ans;
    }
};