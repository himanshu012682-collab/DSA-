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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        TreeNode*left=root;
        TreeNode*right=root;
        int leftheight=0;

        int rightheight=0;
        while(left!=NULL){
            left=left->left;
            leftheight++;

        }
        while(right!=NULL){
            right=right->right;
            rightheight++;
        }
        if(leftheight==rightheight){
            return pow(2,leftheight)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
        
    }
};