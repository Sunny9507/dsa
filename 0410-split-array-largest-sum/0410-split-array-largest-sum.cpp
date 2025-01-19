class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxAllow) {
        int subarrays = 1, currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] <= maxAllow) {
                currentSum += nums[i];
            } else {
                subarrays++;
                currentSum = nums[i];
                if (subarrays > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);

        while (l <= h) {
            int mid = (l + h) / 2;

            if (isValid(nums, k, mid)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};