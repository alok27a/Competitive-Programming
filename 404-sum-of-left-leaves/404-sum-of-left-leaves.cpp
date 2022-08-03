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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* u = q.front();
            q.pop();
            if(u->left!=NULL)
                q.push(u->left);
            if(u->right!=NULL)
                q.push(u->right);
            
            if(u->left && u->left->left==NULL && u->left->right==NULL)
                sum+=u->left->val;
        }
        return sum ;
    }
};