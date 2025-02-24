class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int>v;

        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }   

        sort(begin(v), end(v));
        temp = head;
        int i=0;
        while(temp && i < v.size()){
            temp->val = v[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};