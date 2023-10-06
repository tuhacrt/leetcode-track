class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0;
        int ans=0;
        unordered_set<char> set;
        
        while (r < n) {
            while (set.contains(s[r])) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};