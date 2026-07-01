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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(!l1 && !l2)return nullptr;
       if(l1 && !l2)return l1;
       if(!l1 && l2)return l2;
        
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        int carry = 0 , sum;
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            ptr->next = new ListNode(sum%10);//rem in node
            carry = sum/10; //carry fwd
            ptr = ptr->next;
            l1 = l1->next; l2= l2->next;
        }
        //jo bchega uska carry handle krlenge

        while(l1){
            sum = l1->val + carry;
            ptr->next = new ListNode(sum%10);//rem in node
            carry = sum/10; //carry fwd
            ptr = ptr->next;
            l1 = l1->next;
        }

        while(l2){
            sum = l2->val + carry;
            ptr->next = new ListNode(sum%10);//rem in node
            carry = sum/10; //carry fwd
            ptr = ptr->next;
            l2 = l2->next;
        }
        if(carry){
            ptr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};