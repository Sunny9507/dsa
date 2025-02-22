class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp = insertGreatestCommonDivisors(head->next);

        ListNode* gcdNode = new ListNode(__gcd(head->val, head->next->val));

        head->next = gcdNode;
        gcdNode->next = temp;

        return head;
    }
};