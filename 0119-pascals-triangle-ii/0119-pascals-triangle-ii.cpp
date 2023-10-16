class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> curr, prev = {1};

        for (int i = 1; i <= r; i++) {
            curr.assign(i + 1, 1);

            for (int j = 1; j < i ; j++)
                curr[j] = prev[j - 1] + prev[j];

            prev = move(curr);
        }

        return prev;
    }
};