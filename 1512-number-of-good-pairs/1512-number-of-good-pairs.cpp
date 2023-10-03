class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        
        for (int n: nums) {
            if (m.contains(n)) {
                ans += m[n];
                m[n]++;
            } else {
                m[n] = 1;
            }
        }
        
        return ans;
    }
};