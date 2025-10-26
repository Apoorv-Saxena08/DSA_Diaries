/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        int count = 0 ;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
};