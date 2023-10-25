class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, r = m * n - 1;

        while (l <= r) {
            int m = l + (int)((r - l) / 2);
            int curr = mat[m / n][m % n];
            if (curr == t) return true;
            if (curr > t) r = m - 1;
            else l = m + 1;
        }

        return false;
    }
};