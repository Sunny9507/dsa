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
ListNode* removeZeroSumSublists(ListNode* head) {
    // Create a dummy node to handle edge cases easily
    ListNode* dummy = new ListNode(0);
    dummy->next = head;  // Dummy node points to head to simplify logic

    unordered_map<int, ListNode*> seen;  // HashMap to store prefix sum and last occurrence of nodes
    int prefixSum = 0;  // Variable to store cumulative sum
    ListNode* curr = dummy;  // Pointer to traverse the list

    // **First Pass: Compute prefix sums and store last occurrence in HashMap**
    while (curr) {  // Traverse through the linked list
        prefixSum += curr->val;  // Compute prefix sum at each node
        seen[prefixSum] = curr;  // Store the latest node where this sum appears
        curr = curr->next;  // Move to the next node
    }

    // Reset variables for the second pass
    prefixSum = 0;
    curr = dummy;  // Reset pointer to start from the dummy node again

    // **Second Pass: Remove zero-sum sublists**
    while (curr) {  // Traverse the list again
        prefixSum += curr->val;  // Compute prefix sum
        curr->next = seen[prefixSum]->next;  // Skip nodes that sum to zero
        curr = curr->next;  // Move to the next node
    }

    return dummy->next;  // Return modified list (skip dummy node)
}

};