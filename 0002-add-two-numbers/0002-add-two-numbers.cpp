class Solution {
public:    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l3 = new ListNode(-1);
        ListNode* l3Head = l3;
        int carry = 0;

        while(l1 || l2){

            int l1Val = 0;
            if(l1){
                l1Val = l1->val;
                l1 = l1->next;
            }
            
            int l2Val = 0;
            if(l2){
                l2Val = l2->val;
                l2 = l2->next;
            }

            int value = l1Val + l2Val + carry;
            l3->next = new ListNode(value % 10);
            carry = value/10;

            l3 = l3->next;
        }
        if(carry != 0){
            l3->next = new ListNode(carry);
        }

        return l3Head->next;
    }
};