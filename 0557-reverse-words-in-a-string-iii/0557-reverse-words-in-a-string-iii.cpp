class Solution {
public:
    string reverseWords(string str) {
        int last = -1;
        int n = (int)str.size();
        
        for (int i = 0; i <= n; i++) {
            if (i == n || str[i] == ' ') {
                int s = last + 1;
                int e = i - 1;
                while (s < e) {
                    char temp = str[s];
                    str[s] = str[e];
                    str[e] = temp;
                    s++;
                    e--;
                }
                last = i;
            }
        }
        
        return str;
    }
};