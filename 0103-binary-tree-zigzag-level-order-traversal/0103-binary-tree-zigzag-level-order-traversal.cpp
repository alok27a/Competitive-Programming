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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        
        while(!q.empty())
        {
            int count = q.size();
            
            vector<int> v;
            
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            if(i%2!=0)
                reverse(v.begin(),v.end());
            i++;
            ans.push_back(v);
        }
        return ans;
    }
};