class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

 
    }
};
