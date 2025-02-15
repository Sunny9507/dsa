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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1, v2, v3;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                v1.push_back(temp->val);
            }
            else{
                v2.push_back(temp->val);
            }
            temp = temp->next;
        }
        int i=0;
        while(i<v1.size()){
            v3.push_back(v1[i]);
            i++;
        }
        i=0;
        while(i<v2.size()){
            v3.push_back(v2[i]);
            i++;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int i = 0; i < v3.size(); i++){
            tail->next = new ListNode(v3[i]);
            tail = tail->next;
        }
        return dummy->next;
    }
};