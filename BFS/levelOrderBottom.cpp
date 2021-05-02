// 给定一个二叉树，返回其节点值自底向上的层序遍历。 

// （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> levelOrder;
      if (!root){
        return {};
      }
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()){
        vector<int> level;
        int size = q.size();
        for (int i = 0; i != size; ++i){
          auto cur = q.front();
          q.pop();
          level.push_back(cur->val);
          if (cur->left){
            q.push(cur->left);
          }
          if (cur->right){
            q.push(cur->right);
          }
        }
        levelOrder.push_back(level);
      }
      reverse(levelOrder.begin(), levelOrder.end());
      return levelOrder;
    }
};