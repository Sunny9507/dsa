class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode tmp(0, head);
    unordered_set<int> s(begin(nums), end(nums));
    for (auto *p = &tmp; p->next != nullptr; )
        if (s.contains(p->next->val))
            p->next = p->next->next;
        else
            p = p->next;
    return tmp.next;
}
};