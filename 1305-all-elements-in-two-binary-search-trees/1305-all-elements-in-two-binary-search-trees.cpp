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
    void inorderTrav(TreeNode* root,vector<int> &v)
    {
        if(root!=NULL)
        {
            inorderTrav(root->left,v);
            v.push_back(root->val);
            inorderTrav(root->right,v);   
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> A,B;
        inorderTrav(root1,A);   
        inorderTrav(root2,B);
        
        vector<int> AB;
        AB.reserve( A.size() + B.size() ); // preallocate memory
        AB.insert( AB.end(), A.begin(), A.end() );
        AB.insert( AB.end(), B.begin(), B.end() );
        
        sort(AB.begin(),AB.end());
        return AB;
    }
};