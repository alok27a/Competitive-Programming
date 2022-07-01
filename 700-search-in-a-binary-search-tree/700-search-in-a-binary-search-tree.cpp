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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        
        TreeNode* curr = root;
        
        while(curr!=NULL)
        {
            if(curr->val>val)
                curr=curr->left;
            else if(curr->val<val)
                curr=curr->right;
            else if(curr->val==val)
            {
                return curr;
            }
            else
            {
                break;
            }
        }
        return NULL;
    }
};