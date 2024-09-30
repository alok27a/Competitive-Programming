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
    
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Queue stores pairs of (TreeNode, index)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        int maxWidth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = left; // Track the rightmost position
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                right = index; // Update rightmost position
                
                // Push the left and right children with their respective positions
                if (node->left != nullptr) {
                    q.push({node->left, 2 * index});
                }
                if (node->right != nullptr) {
                    q.push({node->right, 2 * index + 1});
                }
            }
            
            // The width of the current level is the difference between right and left plus 1
            maxWidth = max(maxWidth, int(right - left + 1));
        }
        
        return maxWidth;

    }
};