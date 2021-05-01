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
// 二叉树的层序遍历
#include <vector>
using std::vector;

class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if (!root){
        return ret;
      }
      queue<TreeNode* > q;
      q.push(root);
      while(!q.empty()){
        int currentLevelSize = q.size();
        ret.push_back(vector<int> ());
        for (int i = 1; i <= currentLevelSize; ++i){
          auto node = q.front();
          q.pop();
          ret.back().push_back(node->val);
          if (node->left) {
            q.push(node->left);
          }
          if (node->right){
            q.push(node->right);
          }
        }
      }
      return ret;
    }
};