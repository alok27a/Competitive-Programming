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
TreeNode* reverseOddLevels(TreeNode* root) {
//      level Order Traversal
    queue<TreeNode*> q;
    q.push(root);
    bool reverse = false;
    while(!q.empty()){
        int size = q.size();
        vector<TreeNode*> level;
        for(int i =0;i< size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node -> left)
                q.push(node -> left);
            if(node -> right)
                q.push(node -> right);
            level.push_back(node);
        }
//          Swap the values of odd level
        if(reverse){
            int l =0, r = level.size()-1;
            while(l<r){
                int x = level[l] -> val;
                int y = level[r]-> val;
                level[l] -> val = y;
                level[r] -> val = x;
                l++; r--;
            }
            reverse = false;
        }
        else{
            reverse = true;
        }
    } 
    return root;
   }
};