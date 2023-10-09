class Solution {
public:
    vector<int> nums;
    int target;
    
    vector<int> searchRange(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;

        return {findFirst(), findLast()};
    }

private:
    int findFirst() {
        int left = 0, right = nums.size() - 1;
        int first = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    first = mid;
                    break;
                }
                else right = mid - 1;
            }
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return first;
    }

    int findLast() {
        int left = 0, right = nums.size() - 1;
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    last = mid;
                    break;
                }
                else left = mid + 1;
            }
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return last;
    }
};