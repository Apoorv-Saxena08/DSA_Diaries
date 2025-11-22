class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head->next) return head;

        vector<int> vals;
        ListNode* temp = head;

        while (temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        int total = vals.size();

        // Convert to 0-indexed positions
        int i = k - 1;             // k-th from start
        int j = total - k;         // k-th from end

        swap(vals[i], vals[j]);

        // Rebuild the linked list
        ListNode* newHead = new ListNode(0);
        temp = newHead;
        for (int v : vals) {
            temp->next = new ListNode(v);
            temp = temp->next;
        }

        return newHead->next;
    }
};
