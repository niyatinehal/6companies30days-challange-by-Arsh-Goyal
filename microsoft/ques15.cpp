//1358. Number of Substrings Containing All Three Characters
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
//sliding window
class Solution {
public:
	int numberOfSubstrings(string s) {
		int n = s.size(), ans = 0;
		map<char,int> mp;
		int left = 0, right = 0;
		while(left<n && right<n){
			mp[s[right]]++;
			while(mp.size()==3){
				ans+=(n-right);
				if(mp[s[left]]>1){
					mp[s[left]]--;
				}
				else{
					mp.erase(s[left]);
				}
				left++;
			}
			right++;
		} 
		return ans;
	}
};