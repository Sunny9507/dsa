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
    int pairSum(ListNode* head) {
        vector<int>v;

        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }

        int i=0, j = v.size()-1;
        int result = 0;

        while(i < j){
            result = max(result, v[i]+v[j]); 
            i++;
            j--;
        }
        return result;
    }
};