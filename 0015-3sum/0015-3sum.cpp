class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i])
                twoSum(nums, i, res);
        }
        
        return res;
    }
    
    void twoSum(vector<int>& nums, int idx, vector<vector<int>> &res) {
        int n = nums.size();
        for (int i = idx + 1, j = n - 1; i < j;) {
            int sum = nums[i] + nums[j] + nums[idx];
            if (sum == 0) {
                res.push_back({ nums[i++], nums[idx], nums[j--]});
                while (i < j && nums[i] == nums[i - 1]) {
                    i++;
                }
            } else if (sum > 0) {
                j--;
            } else {
                i++;
            }
        }
    }
};