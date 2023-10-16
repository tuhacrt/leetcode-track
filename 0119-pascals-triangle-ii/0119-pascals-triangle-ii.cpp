class Solution {
    unordered_map<int, vector<int>> memo;
public:
    vector<int> getRow(int r) {
        if (r == 0) {
            memo[0] = {1};
            return {1};
        }
        if (r == 1) {
            memo[1] = {1, 1};
            return {1, 1};
        }

        vector<int> last = getRow(r - 1);
        vector<int> ans = vector(r + 1, 1);
        for (int i = 1; i < r; i++) {
            ans[i] = last[i - 1] + last[i];
        }
        memo[r] = ans;
        return ans;
    }
};