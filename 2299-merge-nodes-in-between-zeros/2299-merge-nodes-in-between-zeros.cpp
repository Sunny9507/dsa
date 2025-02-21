class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;

        if(head == NULL) return head;
    
        ListNode* temp = head;

        int sum = 0;
        while(temp && temp->val != 0){
            sum += temp->val;
            temp = temp->next;
        }
        head->val = sum;
        head->next = mergeNodes(temp);
            
        return head;
    }
};