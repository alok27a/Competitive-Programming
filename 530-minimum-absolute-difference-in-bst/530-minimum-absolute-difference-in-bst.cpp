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
    
    void inorder(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        
        
         int diff = INT_MAX;
         for (int i=0; i<arr.size()-1; i++)
             if (abs(arr[i+1] - arr[i]) < diff)
                 diff = arr[i+1] - arr[i];
        return diff;
    }
};