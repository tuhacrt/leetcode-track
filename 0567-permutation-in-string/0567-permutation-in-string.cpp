class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> w1 (26, 0), w2 (26, 0);

        for (char c: s1) w1[c - 'a']++;

        for (int l = 0, r = 0; r < n2; r++) {
            int n = r - l + 1;
            w2[s2[r] - 'a']++;
            
            if (n == n1 && w1 == w2) return true;
            if (n >= n1) w2[s2[l++] - 'a']--;
        }

        return false;
    }
};