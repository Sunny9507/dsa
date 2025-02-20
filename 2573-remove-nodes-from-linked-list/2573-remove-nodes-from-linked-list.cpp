class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;

        // Step 1: Store all node values in a vector
        vector<int> v;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Use a stack to find nodes to keep
        stack<int> st;
        for (int i = 0; i < v.size(); i++) {
            // Pop elements from the stack that are smaller than the current value
            while (!st.empty() && st.top() < v[i]) {
                st.pop();
            }
            st.push(v[i]); // Push the current value
        }

        // Step 3: Create a new vector with the remaining values
        vector<int> d;
        while (!st.empty()) {
            d.push_back(st.top());
            st.pop();
        }
        reverse(d.begin(), d.end()); // Reverse to restore original order

        // Step 4: Update the linked list with the remaining values
        temp = head;
        ListNode* prev = nullptr;
        int i = 0;
        while (temp && i < d.size()) {
            temp->val = d[i];
            prev = temp;
            temp = temp->next;
            i++;
        }

        // Step 5: Remove any extra nodes
        if (prev) {
            prev->next = nullptr;
        }

        return head;
    }
};