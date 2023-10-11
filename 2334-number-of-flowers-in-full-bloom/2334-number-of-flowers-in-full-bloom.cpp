class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> diff;
        diff[0] = 0;

        for (vector<int>& f: flowers) {
            diff[f[0]]++;
            diff[f[1] + 1]--;
        }

        vector<int> posi;
        vector<int> prefix;
        int curr = 0;

        for (auto& p: diff) {
            posi.push_back(p.first);
            curr += p.second;
            prefix.push_back(curr);
        }

        vector<int> ans;
        for (int p: people) {
            int i = upper_bound(posi.begin(), posi.end(), p) 
                    - posi.begin() - 1;
            ans.push_back(prefix[i]);
        }

        return ans;
    }
};