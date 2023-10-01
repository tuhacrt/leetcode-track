class Solution {
public:
    string reverseWords(string s) {
        int last = -1;
        int n = s.size();
        
        for (int i = 0; i <= n; i++) {
            if (i==n||s[i]==' ') {
                int start = last + 1;
                int end = i - 1;
                
                while (start < end) {
                    char tmp = s[start];
                    s[start] = s[end];
                    s[end] = tmp;
                    start++;
                    end--;
                }
                
                last = i;
            }
        }
        
        return s;
    }
};