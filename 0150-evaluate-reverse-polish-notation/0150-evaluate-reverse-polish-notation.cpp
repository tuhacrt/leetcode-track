class Solution {
    long resolves(int a, int b, char op){
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '*') return (long)a * b;
        return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;

        for (string& s : tokens) {
            if (s.size() == 1 and s[0] < 48) {
                long b = st.top();
                st.pop();
                long a = st.top();
                st.pop();

                st.push((long)resolves(a, b, s[0]));
            } else 
                st.push(stoi(s));
        }

        return st.top();
    }
};