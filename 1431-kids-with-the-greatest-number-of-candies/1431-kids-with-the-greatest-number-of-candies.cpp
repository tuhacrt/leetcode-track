class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans = {};
        int m=0;
        
        for (int i=0;i<n;i++) {
            m = max(m, candies[i]);
        }
        
        for (int i=0;i<n;i++) {
            ans.push_back(candies[i] + extraCandies >= m);
        }
        
        return ans;
    }
};