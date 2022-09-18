/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        
        vector<vector<Node*>> op;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<Node*> temp;
            for(int i=0;i<n;i++)
            {
                Node* u = q.front();
                q.pop();
                temp.push_back(u);

                if(u->left!=NULL)
                {
                    q.push(u->left);
                }
                if(u->right!=NULL)
                {
                    q.push(u->right);
                }   
            }
            op.push_back(temp);
            temp={};
        }
        
        for(int i = 0 ;i<op.size();i++)
        {
            for(int j=0;j<op[i].size()-1;j++)
            {
                op[i][j]->next = op[i][j+1];
            }
            op[i][op[i].size()-1] = NULL;
        }
        
        return root;
    }
};