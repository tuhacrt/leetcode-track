class Solution {
public:
    unordered_map<char, char> map;
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';

        for (int i = 0; i < n; i++) {
            if (!map.contains(s[i])) st.push(s[i]);
            else {
                if (st.empty() || st.top() != map[s[i]]) return false;
                st.pop();
            }
        }
        
        return st.size() == 0;
    }
};