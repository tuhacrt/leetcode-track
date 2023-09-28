class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res = 0;
        stack<int> st;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                res += i - st.top();
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            res += nums.size() - st.top();
            st.pop();
        }
        
        return res;
    }
};