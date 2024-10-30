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
    vector<int> result;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left); 
        result.push_back(root->val);
        inorder(root->right); 
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        
        int mini = INT_MAX;
        
        for(int i=1;i<result.size();i++)
        {
            mini = min(mini,result[i] - result[i-1]);    
        }
        return mini;
    }
};