class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        // Push all values of l1 into stack s1
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all values of l2 into stack s2
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* ans = NULL;  // Start with NULL instead of an empty node

        // Process both stacks until empty
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            // Create a new node and add it to the front
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = ans;
            ans = newNode;
        }

        return ans; // No need for additional carry checks
    }
};
