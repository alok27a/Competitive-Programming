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
    vector<int> v;
    int maxlevel=0;
    int findBottomLeftValue(TreeNode* root) {
            leftView(root,1);
        return v[v.size()-1];
    }
    void leftView(TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        if(maxlevel<level)
        {
            v.push_back(root->val);
            maxlevel=level;
        }
        leftView(root->left, level+1);
        leftView(root->right, level+1);
    }
};