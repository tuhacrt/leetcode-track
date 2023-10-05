class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n = A.size();
        int l=0, r=0;
        int ans = 0;
        
        while (r < n) {
            if (A[r] < A[l]) {
                l=r;
            }
            ans = max(ans, A[r] - A[l]);
            r++;
        }
        
        return ans;
    }
};