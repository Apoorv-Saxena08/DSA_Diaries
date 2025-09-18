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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return ;
        }
        //find middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //break the link
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;//start of 2nd ll
        slow->next = nullptr;

        //reverse second half
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //merge it 
        ListNode* start = head;
        ListNode* second = prev;
        
        while(second){
            ListNode* next1 = start->next;
            ListNode* next2 = second->next;
            start->next = second;
            second->next = next1;
            start = next1;
            second = next2;
        }
        
    }
};