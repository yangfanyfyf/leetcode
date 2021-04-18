// 根据前序遍历和后续的结果重建二叉树


class Solution {
private:
  unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
      int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        if (preorder_left > preorder_right){
          return nullptr;
        }
        int preorder_root = preorder_left;
        // 取出根节点在中序遍历中对应的点
        int inorder_root = index[preorder[preorder_root]];
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree,
          inorder_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1,
          preorder_right, inorder_root + 1, inorder_right);
        return root;
      }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n = preorder.size();
      // 将中序排列存储到哈希表中
      // 重复了怎么办？
      for (int i = 0; i != n; ++i){
        index[inorder[i]] = i;
      }
      return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};