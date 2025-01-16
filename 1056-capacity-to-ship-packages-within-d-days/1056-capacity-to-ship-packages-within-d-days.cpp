class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] + load > cap) {
                days += 1; // Need another day
                load = weights[i]; // Start new load with current weight
            } else {
                load += weights[i]; // Add current weight to load
            }
        }
        return days; // Return total number of days needed
    }

    int shipWithinDays(vector<int>& weights, int d) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);

        while(l < h) { // Use < instead of <= for binary search
            int mid = l + (h - l) / 2; // Avoid overflow

            int NoOfDays = findDays(weights, mid);
            if(NoOfDays <= d) {
                h = mid; // Try for a smaller capacity
            } else {
                l = mid + 1; // Increase capacity
            }
        }
        return l; // Minimum capacity that allows shipping within d days
    }
};