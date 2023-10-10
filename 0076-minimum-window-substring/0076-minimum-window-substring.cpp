class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int count = t.size(), len = INT_MAX, head = 0;
        int begin = 0, end = 0;

        for (char c: t) map[c]++;

        while (end < s.size()) {

            if (map[s[end++]]--  > 0) count--;

            while (count == 0) {
                if (end - begin < len) len = end - (head = begin);
                if (map[s[begin++]]++ == 0) count++;
            }
        }

        return len == INT_MAX ? "" : s.substr(head, len);
    }
};