class Solution {
public:
    int trap(vector<int>& H) {
        int l=0, r=H.size()-1;
        int ml=0, mr=0;
        int ans=0;
        
        while (l < r) {
            if (H[l] < H[r]) {
                H[l] >= ml ? ml=H[l] : ans+=ml-H[l];
                l++;
            } else {
                H[r] >= mr ? mr=H[r] : ans+=mr-H[r];
                r--;
            }
        }
        
        return ans;
    }
};