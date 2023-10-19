class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string c1, c2;

        for (auto& c: s) {
            if (c != '#') st.push(c);
            else if (st.size()) st.pop();
        }

        while (st.size()) {
            char c = st.top();
            st.pop();
            c1 += c;
        }
        
        for (auto& c: t) {
            if (c != '#') st.push(c);
            else if (st.size()) st.pop();
        }

        while (st.size()) {
            char c = st.top();
            st.pop();
            c2 += c;
        }

        if (c1.size() != c2.size()) return false;

        for (int i = 0; i < c1.size(); i++) {
            if (c1[i] != c2[i]) return false;
        }

        return true;
    }
};