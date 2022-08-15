/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        if(root==NULL)
            return res;
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                Node* u = q.front();
                v.push_back(u->val);
                for(auto v : u->children)
                {
                    q.push(v);
                }
                q.pop();
            }
            res.push_back(v);
            v={};
        }
        return res;
    }
};