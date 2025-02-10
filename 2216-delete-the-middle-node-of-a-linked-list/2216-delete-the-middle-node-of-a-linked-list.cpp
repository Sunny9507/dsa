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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || head->next == nullptr){ 
            return nullptr; 
        }
        ListNode* temp = head;
        int cnt = 1;

        while(temp->next){
            cnt++;
            temp=temp->next;
        }
        cnt/=2;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(cnt--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};