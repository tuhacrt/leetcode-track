class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long res = 0;
        for (int i = 1, j = 0; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1])
                j = i;
            res += i - j;
        }
        return res + nums.size();
    }
};