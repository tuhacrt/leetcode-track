class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_set<char> set;
        
        for (int l=0,r=0; r < s.size(); r++) {
            while (set.contains(s[r])) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};