class Solution {
public:
    vector<int> memo;
    
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        memo = vector(n+1, 0);
        return dp(n);
    }
    
    int dp(int n){
        if (n <= 3) return n;
        if (memo[n] != 0) return memo[n];
        int ans = n;
        for (int i = 2; i < n; i++) {
            ans = max(ans, i*dp(n - i));
        }
        memo[n] = ans;
        return ans;
    } 
};