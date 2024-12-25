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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> res;
        
        while(!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode* u = q.front();
                maxi = max(u->val,maxi);
                q.pop();
                if(u->left!=NULL) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};