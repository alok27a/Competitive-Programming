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
    void printRight(vector<int> &v,TreeNode* root, int level,int &max_level)
    {
        if(root==NULL)
            return;
        if(max_level<level)
        {
            v.push_back(root->val);
            max_level = level;
        }
        printRight(v,root->right,level+1,max_level);
        printRight(v,root->left,level+1,max_level);
    }
    
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        int max_level = 0;
        printRight(v,root,1,max_level);
        return v;
    }
};