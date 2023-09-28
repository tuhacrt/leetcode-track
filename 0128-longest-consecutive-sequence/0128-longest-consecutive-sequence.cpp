class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        
        for (int num : nums) {
            set.insert(num);
        }
        
        int res = 0;
        
        for (int num: set) {
            if (!set.contains(num - 1)) {
                int cur = num;
                int streak = 1;
                
                while (set.contains(cur + 1)) {
                    cur++;
                    streak++;
                }
                
                res = max(res, streak);
            }
        }
        
        return res;
    }
};