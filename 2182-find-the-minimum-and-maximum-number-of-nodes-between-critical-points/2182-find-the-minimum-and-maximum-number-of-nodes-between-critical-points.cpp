class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v, v1;

        ListNode* temp = head;

        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        
        for (int i = 1; i < v.size() - 1; i++) {
            if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1])) {
                v1.push_back(i);
            }
        }

        
        if (v1.size() < 2) {
            return {-1, -1};
        }

        
        int maxi = v1.back() - v1.front(); 
        int mini = INT_MAX;

        for (int i = 1; i < v1.size(); i++) {
            mini = min(mini, v1[i] - v1[i - 1]); 
        }

        return {mini, maxi};
        
    }
};