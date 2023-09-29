class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> cur = {};
        
        bt(nums, res, cur, 0);
        return res;
    }
    
    void bt(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int idx) {
        res.push_back(cur);
        
        for (int i = idx; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            bt(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};