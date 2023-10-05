class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        vector<int> ans = {};
        
        for (int n: nums) {
            if (map.contains(n)) map[n]++;
            else map[n] = 1;
        }
        
        for (auto const& [key, val] : map) {
            if (val > int(n / 3)) ans.push_back(key);
        }
        
        return ans;
    }
};