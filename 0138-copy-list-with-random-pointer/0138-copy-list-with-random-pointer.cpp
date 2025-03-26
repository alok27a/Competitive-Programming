/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1 -- Create a hash map that maps the old nodes with the nodes of deep copy

        unordered_map<Node*,Node*> mp;
        Node* curr = head;
        while(curr!=NULL)
        {
            Node* cpy = new Node(curr->val);
            mp[curr] = cpy;
            curr = curr->next;
        }
// Step 2 -- Map the next and random pointer for the newly created node
        curr = head;
        while(curr!=NULL)
        {
            Node* cpy = mp[curr];
            cpy->next = mp[curr->next];
            cpy->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};