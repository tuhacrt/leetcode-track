class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums1;
    vector<int> nums2;
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int fMax = INT_MIN, sMax = INT_MIN;
        int fMin = INT_MAX, sMin = INT_MAX;
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int n: nums1) {
            fMax = max(fMax, n);
            fMin = min(fMin, n);
        }

        for (int n: nums2) {
            sMax = max(sMax, n);
            sMin = min(sMin, n);
        }

        if (fMax < 0 && sMin > 0) return fMax * sMin;
        if (fMin > 0 && sMax < 0) return fMin * sMax;

        memo = vector(nums1.size(), vector(nums2.size(), 0));
        return dp(0, 0);
    }

    int dp(int i, int j) {
        if (i == nums1.size() || j == nums2.size()) return 0;
        if (memo[i][j] != 0) return memo[i][j];

        int use = nums1[i] * nums2[j] + dp(i + 1, j + 1);
        memo[i][j] = max(use, max(dp(i + 1, j), dp(i, j + 1)));
        return memo[i][j];
    }
};