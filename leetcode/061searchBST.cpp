


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

// 需要返回该节点，以及他的所有分支
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
      if (root == nullptr) return nullptr;
      if (root->val == val){
        return root;
      }else if(root->val > val){
        return searchBST(root->left, val);
      }else{
        return searchBST(root->right, val);
      }
      // return nullptr;
    }
};

