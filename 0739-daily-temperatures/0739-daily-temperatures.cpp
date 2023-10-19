class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int> st({ n - 1 });
        vector<int> ans(n, 0);        

        for (int i = n - 2; i >= 0; i--) {
            while (st.size() != 0 && t[i] >= t[st.top()]) 
                st.pop();   
            if (st.size() != 0) 
                ans[i] = st.top() - i;
            
            st.push(i);
        }

        return ans;
    }
};