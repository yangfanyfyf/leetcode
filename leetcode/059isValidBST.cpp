// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

// 每个节点的子树也必须是BST
bool helper(TreeNode *root, long long lower, long long upper){
  if (root == nullptr){
    return true;
  }
  if (root->val <= lower || root->val >= upper) {
    return false;
  }
  // 对两侧的值做出限制，左侧的值必须小于root的值，右侧的值必须要大于root的值
  return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}


bool isValidBST(TreeNode* root){
  return helper(root, LONG_MIN, LONG_MAX);
}