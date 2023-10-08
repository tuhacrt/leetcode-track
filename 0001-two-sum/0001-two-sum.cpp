class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (map.contains(n)) return {map[n], i};
            map[target - n] = i;
        }

        return {-1, -1};
    }
};