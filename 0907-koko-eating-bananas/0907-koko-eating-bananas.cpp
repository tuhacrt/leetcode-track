class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int m = l + (r - l) / 2;
            int hour = 0;

            for (int p: piles) {
                hour += p / m + (p % m != 0);
            }

            hour <= h ? r = m : l = m + 1;
        }

        return l;
    }
};