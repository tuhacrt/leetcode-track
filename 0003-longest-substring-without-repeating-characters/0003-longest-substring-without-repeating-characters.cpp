class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0;
        int ans=0;
        unordered_set<char> set;
        
        while (r < n) {
            char cur = s[r];
            
            while (set.contains(cur)) {
                set.erase(s[l]);
                l++;
            }
            set.insert(cur);
            
            ans = max(ans, r - l + 1);
            r++;
        }
        ans = max(ans, r - l);
        
        return ans;
    }
};