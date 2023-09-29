class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 2) return true;
        
        int dir = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                if (dir == 0) dir = 1;
                else if (dir == -1) return false;
            } else if (nums[i] < nums[i - 1]) {
                if (dir == 0) dir = -1;
                else if (dir == 1) return false;
            }
        }
       
        return true;
    }
};