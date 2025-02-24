class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next; // Correct initialization
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* l2 = sortList(slow->next);
        slow->next = nullptr; // Break the list
        
        return merge(sortList(head), l2); // Correct recursive call
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};