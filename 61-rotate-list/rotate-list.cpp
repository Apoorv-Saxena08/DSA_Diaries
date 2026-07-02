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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;

        //count 
        int c = 0 ;
        ListNode* temp = head;
        while(temp){
            c++;
            temp = temp->next;
        }

        k = k%c ;
        if(k == 0)return head;

        ListNode* end = head;
        for(int i= 0 ; i <c-k-1;i++){
            end = end->next;
        }

        ListNode* next = end->next;
        end->next = nullptr;

        temp = next;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;

        return next;
    }
};