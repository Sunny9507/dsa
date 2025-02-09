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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;

        // Count number of nodes
        while(temp){
            cnt++;
            temp = temp->next;
        }
        cnt -= n;
        ListNode* curr = head, * prev = NULL;

        if(cnt == NULL){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(cnt--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};