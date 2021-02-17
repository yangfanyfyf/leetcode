// 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 

// 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
          return new TreeNode(val);
        }
        TreeNode* pos = root;
        while (pos != nullptr){
          if (val < pos->val){
            if (pos->left == nullptr){
              pos->left = new TreeNode(val);
              break;
            }else {
              pos = pos->left;
            }
          }else{
            if (pos->right == nullptr){
              pos->right = new TreeNode(val);
              break;
            }else {
              pos = pos->right;
            }

          }
        }
        return root;
    }
};