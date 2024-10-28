//Approach-2 (Using set)
//T.C : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
//S.C : O(n)
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) {
            int streak = 0;
            long long curr = num;

            while(st.find(curr) != st.end()) {
                streak++;

                if(curr*curr > 1e5) {
                    break;
                }

                curr = curr*curr; //square
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};