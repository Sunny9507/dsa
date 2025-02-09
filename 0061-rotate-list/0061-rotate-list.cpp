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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        k %= cnt;
        if(k == NULL) return head;

        cnt -= k;

        ListNode* curr = head, *prev = NULL;
        while(cnt--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;

        ListNode* tail = curr;

        // Second list uske last node pe leakr jao
        while(tail->next){

            tail = tail->next;
        }
        tail->next = head;
        head = curr;
        
        return head;
    }
};