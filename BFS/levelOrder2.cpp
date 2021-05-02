// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
      vector<int> ret;
      if (!root){
        return {};
      }
      // 新建队列
      queue<TreeNode *> q;
      // 压入根节点
      q.push(root);
      while(!q.empty()){
        int size = q.size();
        // 遍历当前的整个队列，也就是这一层
        for (int i = 0; i < size; ++i){
          auto node = q.front();
          q.pop();
          ret.push_back(node->val);
          // 加入左右节点
          if (node->left) q.push(node->left);
          if (node->right) q.push(node->right);
        }
      }
      return ret;
    }
};