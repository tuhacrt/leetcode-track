class Solution {
public:
    vector<vector<vector<int>>> memo;
    int MOD = 1e9 + 7;
    int n, m;
    
    int numOfArrays(int n, int m, int k) {
        memo = vector(n, vector(m + 1, vector(k + 1, -1)));
        this->n = n;
        this->m = m;
        return dp(0, 0, k);
    }
    
    int dp(int i, int maxN, int remain) {
        if (i == n) {
            if (remain == 0) return 1;
            return 0;
        }
        if (remain < 0) return 0;
        if (memo[i][maxN][remain] != -1) return memo[i][maxN][remain];
        
        int ans = 0;
        
        for (int j = 1; j <= maxN; j++) {
            ans = (ans + dp(i + 1, maxN, remain)) % MOD;
        }
        
        for (int j = maxN + 1; j <= m; j++) {
            ans = (ans + dp(i + 1, j, remain - 1)) % MOD;
        }
        
        memo[i][maxN][remain] = ans;
        return ans;
    }
};