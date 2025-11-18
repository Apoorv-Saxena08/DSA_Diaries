/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;

    Node* dfs(Node* curr){
        vector<Node*>neib;
        Node* clone = new Node(curr->val);
        mp[curr] = clone;

        for(auto it : curr->neighbors){
            //agr already clone h to neib m daldo 
            if(mp.find(it) != mp.end()){
                neib.push_back(mp[it]);
            }
            else{
                //call dfs
                neib.push_back(dfs(it));
            }
        }
        clone->neighbors = neib;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        //dfs + hashmap (old , new)
        if(!node)return nullptr;
        if(node->neighbors.size()==0){
            //only 1 node
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node);
    }
};