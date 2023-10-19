class Solution {
public:
    vector<string> ans;
    int n;
    vector<string> generateParenthesis(int n) {
        this->ans = {};
        this->n = n;
        bt("", 0, 0);
        return ans;
    }

    void bt(string cur, int l, int r) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (l < n) {
            cur += "(";
            bt(cur, l + 1, r);
            cur.pop_back();
        }
        if (l > r) {
            cur += ")";
            bt(cur, l, r + 1);
            cur.pop_back();
        }
    }
};