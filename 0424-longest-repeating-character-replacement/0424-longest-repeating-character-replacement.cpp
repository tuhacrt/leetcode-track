class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxf = 0;
        unordered_map<char, int> map;
        
        for (int l=0, r=0; r<s.size(); r++) {
            maxf = max(maxf, ++map[s[r]]);
            if (r - l + 1 - maxf > k) {
                map[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};