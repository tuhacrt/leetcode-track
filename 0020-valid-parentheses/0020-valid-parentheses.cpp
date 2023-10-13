class Solution {
public:
    unordered_map<char, char> map;
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map = {{'}', '{'},
                                         {')', '('},
                                         {']', '['}};
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (!map.contains(s[i])) st.push(s[i]);
            else {
                if (st.empty() || st.top() != map[s[i]]) return false;
                st.pop();
            }
        }
        
        return st.empty();
    }
};