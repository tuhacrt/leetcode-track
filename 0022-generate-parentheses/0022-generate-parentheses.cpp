class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans = {};
        bt(ans, {}, 0, 0, n);
        return ans;
    }

    void bt(vector<string>& ans, string cur, int l, int r, int n) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (l < n) {
            cur += "(";
            bt(ans, cur, l + 1, r, n);
            cur.pop_back();
        }
        if (l > r) {
            cur += ")";
            bt(ans, cur, l, r + 1, n);
            cur.pop_back();
        }
    }
};