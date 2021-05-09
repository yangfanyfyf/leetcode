// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 广度优先搜索
class Solution {
public:
    int minDepth(TreeNode* root) {
      if (root == nullptr) return 0;
      queue<pair<TreeNode* , int>> que;
      que.emplace(root, 1);
      while (!que.empty()){
        TreeNode* node = que.front().first;
        int depth = que.front().second;
        que.pop();
        if (node->left == nullptr && node->right == nullptr){
          return depth;
        }
        if (node->left != nullptr){
          que.emplace(node->left, depth + 1);
        }
        if (node->right != nullptr){
          que.emplace(node->right, depth + 1);
        }
      }
      return 0;
    }
};