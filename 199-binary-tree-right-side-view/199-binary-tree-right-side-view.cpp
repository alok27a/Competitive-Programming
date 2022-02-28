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
    int maxlevel=0;
    vector<int> v;
    vector<int> rightSideView(TreeNode* root) {
        rightPrint(root,1);
        return v;
    }
    
    void rightPrint(TreeNode* root,int level)
    {
        if(root==NULL)
            return ;
        if(maxlevel<level)
        {
            v.push_back(root->val);
            maxlevel=level;
        }
        rightPrint(root->right,level+1);
        rightPrint(root->left,level+1);
       
    }
};