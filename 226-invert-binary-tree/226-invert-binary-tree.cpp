/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* u = q.front();
            q.pop();
            // cout<<u->val<<" " ;
            
            if(u->left!=NULL)
                q.push(u->left);
          
            if(u->right!=NULL)
                q.push(u->right);
            
            TreeNode* u_l = u->left;
            u->left = u->right;
            u->right = u_l;
        }
        
        return root;
    }
};