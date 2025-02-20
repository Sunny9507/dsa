class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;

        vector<int> v1, v2;

        // Step 1: Traverse the linked list and store values in v1
        ListNode* temp = head;
        while (temp) {
            v1.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Calculate sums between zeros and store in v2
        int i = 0, sum = 0;
        while (i < v1.size()) {
            if (v1[i] != 0) {
                sum += v1[i]; // Accumulate non-zero values
            } else if (sum > 0) {
                v2.push_back(sum); // Store the sum when a zero is encountered
                sum = 0; // Reset the sum
            }
            i++;
        }

        // Step 3: Update the original linked list with values from v2
        temp = head;
        i = 0;
        ListNode* prev = nullptr; // To keep track of the previous node
        while (temp && i < v2.size()) {
            temp->val = v2[i]; // Update the current node's value
            prev = temp; // Update the previous node
            temp = temp->next; // Move to the next node
            i++;
        }

        // Step 4: Truncate the list after the last updated node
        if (prev) {
            prev->next = nullptr; // Remove the remaining nodes
        }

        return head;
    }
};