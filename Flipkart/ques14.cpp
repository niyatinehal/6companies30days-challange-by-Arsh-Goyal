// 791. Custom Sort String
//  https://leetcode.com/problems/custom-sort-string/submissions/882558951/
class Solution
{
public:
    string customSortString(string order, string str)
    {
        for (int i = order.size() - 1; i >= 0; i--)
        {
            int n = count(str.begin(), str.end(), order[i]);
            str.erase(remove(str.begin(), str.end(), order[i]), str.end());
            str.insert(0, n, order[i]);
        }
        return str;
    }
};