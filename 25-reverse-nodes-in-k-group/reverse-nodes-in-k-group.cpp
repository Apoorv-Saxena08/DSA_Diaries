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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int c = 0;

        while(curr && c<k){
            curr = curr->next;
            c++;
        }
        if(c<k)return head;

        curr = reverseKGroup(curr , k);

        //rev
        while(c--){
            ListNode* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
        }

        return curr;
    }
};