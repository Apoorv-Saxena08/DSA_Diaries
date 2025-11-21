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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            tuple<int,int,ListNode*> // curr val , currRow , heads
            ,vector<tuple<int,int,ListNode*>>,
            greater<tuple<int,int,ListNode*>>
        >pq;

        int k = lists.size();
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        for(int i = 0 ; i<k;i++){
            if (lists[i] != nullptr) {
                pq.push({ lists[i]->val, i, lists[i] });
            }
        }

        while(!pq.empty()){
            auto [val,row,head] = pq.top();
            pq.pop();
            temp->next = head;
            temp = temp->next;
            if(head->next != nullptr){
                pq.push({
                    head->next->val,
                    row,
                    head->next
                });
            }
        }
        return ans->next;
    }
};