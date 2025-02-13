/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Step 1: Count total nodes
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // Step 2: Find k-th node from the start
        temp = head;
        ListNode* first = nullptr;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        first = temp;

        // Step 3: Find k-th node from the end (cnt - k + 1)
        temp = head;
        for (int i = 1; i < (cnt - k + 1); i++) {
            temp = temp->next;
        }
        ListNode* second = temp;

        // Step 4: Swap values
        swap(first->val, second->val);

        return head;
    }
};
