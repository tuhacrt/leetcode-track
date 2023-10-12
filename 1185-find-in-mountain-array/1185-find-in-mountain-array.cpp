/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l = 1, r = n - 2;

        while (l != r) {
            int i = (l + r) >> 1;
            int curr = mountainArr.get(i);
            int next = mountainArr.get(i + 1);

            if (curr < next) {
                if (curr == target) return i;
                if (next == target) return i + 1;
                l = i + 1;
            } else r = i;
        }

        int peak = l;

        l = 0, r = peak;

        while (l <= r) {
            int i = (l + r) >> 1;
            int curr = mountainArr.get(i);

            if (curr == target) return i;
            else if (curr < target) l = i + 1;
            else r = i - 1;
        }

        l = peak + 1, r = n - 1;

        while (l <= r) {
            int i = (l + r) >> 1;
            int curr = mountainArr.get(i);

            if (curr == target) return i;
            else if (curr > target) l = i + 1;
            else r = i - 1;
        }

        return -1;
    }
};