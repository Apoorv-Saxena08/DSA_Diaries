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
    ListNode* merge(ListNode* a , ListNode* b){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(a && b){
            if(a->val < b->val){
                curr->next = a;
                a = a->next;
            }else{
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }

        if(a != nullptr){
            curr->next = a;
        }else{
            curr->next = b;
        }
        
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        //split done

        //recusive call
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left , right);

    }
};