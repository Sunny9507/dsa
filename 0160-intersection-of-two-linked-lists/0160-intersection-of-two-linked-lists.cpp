class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode* a = headA; a != NULL; a=a->next){
            for(ListNode* b = headB; b != NULL; b = b->next){
                if(a == b){
                    return a;
                }
            }
        }
        return NULL;
    }
};