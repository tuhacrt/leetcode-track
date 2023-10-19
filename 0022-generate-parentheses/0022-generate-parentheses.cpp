class Solution {
public:
    vector<string> ans = {};
    int n;

    vector<string> generateParenthesis(int n) {
        this-> n = n;
        bt("", 0, 0);
        return ans;
    }

    void bt(string str, int l, int r) {
        if (str.size() == 2 * n) 
            return ans.push_back(str);

        if (l < n) 
            bt(str + "(", l + 1, r);

        if (l > r) 
            bt(str + ")", l, r + 1);
    }
};