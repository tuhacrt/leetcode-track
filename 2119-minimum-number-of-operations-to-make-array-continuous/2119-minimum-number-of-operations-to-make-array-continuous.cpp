class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;

        for (int n: unique) newNums.push_back(n);

        for (int i = 0; i < newNums.size(); i++) {
            int l = newNums[i];
            int r = l + n - 1;
            int j = upper_bound(newNums.begin(), newNums.end(), r) 
                    - newNums.begin(); 
            int count = j - i;
            ans = min(ans, n - count);
        }

        return ans;
    }
};