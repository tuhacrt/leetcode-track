class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int m=0;
        unordered_map<char, int> map;
        
        for (int l=0, r=0; r<s.size(); r++) {
            map[s[r]]++;
            m = max(m, map[s[r]]);
            if (r - l + 1 - m > k) {
                map[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        
        // for (auto& [key, value]: map) {
        //     cout << key << value << endl;
        // }
        
        return ans;
    }
};