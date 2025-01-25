class Solution {
public:
    TreeNode *prev = NULL; // Pointer to keep track of the previously processed node

    void convertToDLL(TreeNode* root) {
        if (root == NULL) return;

        convertToDLL(root->right);

        convertToDLL(root->left);

        root->right = prev; 
        root->left = NULL;  
        prev = root;        
    }

    void flatten(TreeNode* root) {
        prev = NULL; // Reset the prev pointer
        convertToDLL(root);
    }
};
