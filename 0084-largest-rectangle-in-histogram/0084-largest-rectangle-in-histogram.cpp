class Solution {
public:
    int largestRectangleArea(vector<int>& hs) {
        stack<int> st({-1});
        int res = 0;

        for (int i = 0; i < hs.size(); i++) {
            while (st.top() != -1 and hs[i] < hs[st.top()]) {
                int h = hs[st.top()];
                st.pop();
                int w = i - st.top() - 1;
                res = max(res, h * w);
            }
            st.push(i);
        }

        while (st.top() != -1) {
            int h = hs[st.top()];
            st.pop();
            int w = hs.size() - st.top() - 1;
            res = max(res, h * w);
        }
        
        return res;
    }
};