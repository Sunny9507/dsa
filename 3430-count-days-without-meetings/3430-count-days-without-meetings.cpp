class Solution {
public:

    int countDays(int days, vector<vector<int>>& meetings) {
            map<int, int> eventMap;
        for (const auto& meeting : meetings) {
            eventMap[meeting[0]]++;  // Start of meeting
            eventMap[meeting[1]]--;  // End of meeting
        }

        int daysCount = 0, numberOfOnGoingMeeting = 0, lastMeetingDay = 0;
        for (auto [day, change] : eventMap) {
            if (numberOfOnGoingMeeting == 0) {
                // Middle case, where there is empty window b/w meetings
                daysCount += (day - lastMeetingDay - 1);
            }
            lastMeetingDay = day;
            numberOfOnGoingMeeting += change;
        }
        // Case when after all meeting has ended, we still have some free working days
        return daysCount + (days - lastMeetingDay);
    }
};