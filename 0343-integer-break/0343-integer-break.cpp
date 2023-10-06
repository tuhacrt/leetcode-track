class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        int ans = 1;
        int m = ceil(sqrt(n)) + 1;
        cout << n << m << endl;
        
        for (int i = 2; i <= max(m, 2); i++) {
            int c=n;
            int p=1;
            while (c > 0) {
                if (c >= i * 1.5) {
                    c-=i;
                    p*=i;
                } else {
                    p*=c;
                    c=0;
                }
            }
            ans = max(ans, p);
        }
        
        return ans;
    }
};