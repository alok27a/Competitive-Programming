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
    
    int findDistance(unordered_map<TreeNode*,TreeNode*> &parent_map, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,int> visited;
        visited[target] = 1;
        int maxi = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            int fl = 0;
            
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left!=NULL && !visited[node->left])
                {
                    fl = 1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right!=NULL && !visited[node->right])
                {
                    fl = 1;
                    visited[node->right] = 1;
                    q.push(node->right);   
                }
                
                if(parent_map[node] && !visited[parent_map[node]])
                {
                    fl = 1;
                    visited[parent_map[node]] = 1;
                    q.push(parent_map[node]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
    
    
    
    TreeNode* parentMapping(unordered_map<TreeNode*,TreeNode*> &parent_map,TreeNode* root ,int start)
    {
        if(root==NULL)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* found;
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start)
            {
                found = curr;   
            }
            if(curr->left !=NULL)
            {
                parent_map[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                parent_map[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return found;    
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*,TreeNode*> parent_map;
        
        TreeNode* nd = parentMapping(parent_map,root,start);
        
        return findDistance(parent_map,nd);
        
    }
};