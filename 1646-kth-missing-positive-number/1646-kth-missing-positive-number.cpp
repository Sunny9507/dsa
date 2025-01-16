class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
        int i = 1, j = 0; // i tracks actual numbers, j iterates through arr

        while (v.size() < k) {
            if (j < arr.size() && arr[j] == i) {
                j++; // Skip present numbers in arr
            } else {
                v.push_back(i); // Collect missing numbers
            }
            i++; // Move to the next number
        }
        return v[k - 1]; // Return the kth missing number
    }
};
