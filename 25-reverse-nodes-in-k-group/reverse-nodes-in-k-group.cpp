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
        int count = 0;

        //count grp
        while(curr && count<k){
            curr =  curr->next;
            count++;
        }

        //if no grp (base case)
        if(count<k){
            return head;
        }

        //rec
        curr = reverseKGroup(curr , k);

        //kaam - reverse
        while(count--){
            ListNode* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
        }

        return curr;
    }
};