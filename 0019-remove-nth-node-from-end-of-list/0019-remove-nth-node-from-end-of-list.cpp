class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;

        while(temp){
            cnt++;
            temp = temp->next;
        }
        cnt -= n;

        if(cnt == 0){
            temp = head->next;
            delete head;
            return temp;
        }

        ListNode* prev = NULL;
        temp = head;
        while(cnt--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;

        return head;
    }
};