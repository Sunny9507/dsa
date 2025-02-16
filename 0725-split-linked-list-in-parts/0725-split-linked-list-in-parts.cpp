class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int length = 0;

        while(curr){
            length++;
            curr = curr->next;
        }

        int eachBucket = length/k;
        int extra = length % k;
        
        vector<ListNode* > result(k, NULL); // k nodes hone chahiye or sabhi me null daldo

        curr = head;
        ListNode* prev = NULL;

        for(int i=0; i<k; i++){ 
            result[i] = curr;
            for(int cnt=1; cnt <= eachBucket + (extra > 0 ? 1 : 0); cnt++){
                prev = curr;
                curr = curr->next;
            }
            if(prev)
                prev->next = NULL;
            extra--;
        }
        return result;
    }
};