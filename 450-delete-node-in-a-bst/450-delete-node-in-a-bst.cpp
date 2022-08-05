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
    TreeNode* parent;
    TreeNode* findnode(TreeNode* root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            return root;
        }
        parent = root;
        if (root->val > key)
            return findnode(root->left, key);
        else
            return findnode(root->right, key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        parent = NULL;
        TreeNode* node = findnode(root, key);
        if (node == NULL) // key not found, so no node to delete
        {
            return root;
        }
        if (node->left != NULL && node->right != NULL)
        {
            parent = node;
            TreeNode* last = node->right; // Here what we want is to find the next smaller element to node, which is clearly its inorder successor and we will swap them, then it becomes either a node with 1 child or no child.
            while (last->left != NULL)
            {
                parent = last;
                last = last->left;
            }
            swap(node->val, last->val);
            node = last;
        }
        if (node->left == NULL && node->right == NULL) // Leaf node to be deleted
        {
            if (parent == NULL)
            {
                return NULL;
            }
            else if (parent->left == node)
            {
                parent->left = NULL; // Simply put NULL there
            }
            else
            {
                parent->right = NULL;
            }
        }
        else if (node->left == NULL || node->right == NULL) // Node to be deleted has only either left or right child, not both.
        {
            if (parent == NULL)
            {
                return (node->left == NULL)?node->right:node->left;
            }
            else if (parent->left == node)
            {
                parent->left = (node->left == NULL)?node->right:node->left; // Depending upon which child is not null, we will assign it to the parent
            }
            else
            {
                parent->right = (node->left == NULL)?node->right:node->left;
            }
        }
        return root;
    }
};