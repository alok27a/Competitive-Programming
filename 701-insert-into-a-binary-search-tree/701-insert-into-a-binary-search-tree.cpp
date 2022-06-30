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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        TreeNode* temp = new TreeNode(x);
        TreeNode* parent = NULL;
        TreeNode* curr = root;
        
        if(root == NULL)
            return temp;
        
        while(curr!=NULL)
        {
            parent = curr;
            if(curr->val>x)
                curr = curr->left; 
            else if(curr->val<x)
                curr = curr->right; 
            else 
                return root;
        }
        
        if(parent->val>x)
            parent->left = temp;
        else
            parent->right = temp;
        return root;        
    }
};