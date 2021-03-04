// 给定一个二叉树，判断它是否是高度平衡的二叉树。


class Solution {
public:
    int height(TreeNode* root){
      if (root == nullptr){
        return 0;
      }else {
        return max(height(root->left), height(root->right)) + 1;
      }
    }
    bool isBalanced(TreeNode* root) {
      if (root == nullptr){
        return true;
      }else{
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
      }
    }
};