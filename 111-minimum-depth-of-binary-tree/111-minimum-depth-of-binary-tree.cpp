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
    void dfs(TreeNode*root,int l){
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            l++;
            ans = min(ans,l);
            return;
        }
        dfs(root->left,l+1);
        dfs(root->right,l+1);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,0);
        return ans;
    }
private:
    int ans=INT_MAX;
};