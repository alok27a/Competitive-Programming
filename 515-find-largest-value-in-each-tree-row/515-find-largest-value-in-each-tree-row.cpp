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
        vector<int> res;
        vector<vector<int>> v1;
        vector<int> v2;
        
        if(root==NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* u = q.front();
                v2.push_back(u->val);
                
                if(u->left!=NULL)
                    q.push(u->left);
                if(u->right!=NULL)
                    q.push(u->right);
                q.pop();
            }
            v1.push_back(v2);
            v2={};
        }
        
        for(int i=0;i<v1.size();i++)
        {
            res.push_back(*max_element(v1[i].begin(),v1[i].end()));   
        }
        return res;
    }
};