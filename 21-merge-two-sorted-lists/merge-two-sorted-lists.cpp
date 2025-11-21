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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(0);
        ListNode* temp = newList;
        //edge cases
        if(!l1 && l2)return l2;

        if(l1 && !l2)return l1;

        if(!l1 && !l2)return nullptr;

        while(l1 && l2){
            if(l1->val == l2->val){
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
                l2= l2->next;
            }
            else if(l1->val < l2->val){
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
            }
            else{
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2 = l2->next;
            }
        }

        if(l1){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }

        return newList->next;
    }
};