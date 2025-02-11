/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                ListNode* entry = head; // New pointer at head
                while (entry != slow) { // Find start of cycle
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry; // Start of cycle
            }
        }

        return NULL; // No cycle
    }
};
