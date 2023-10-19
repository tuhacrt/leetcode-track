class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<vector<int>> st({ 
            { t[n - 1], n - 1 } 
        });
        vector<int> ans = { 0 };

        for (int i = n - 2; i >= 0; i--) {
            while (st.size() != 0 && t[i] >= st.top()[0]) 
                st.pop();   
            if (st.size() == 0) 
                ans.push_back(0);
            else 
                ans.push_back(st.top()[1] - i);
            
            st.push({ t[i], i });
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};