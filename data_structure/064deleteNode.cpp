// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。

// 返回二叉搜索树（有可能被更新）的根节点的引用。
/*
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
    // 需要被删除的节点的父节点？
    TreeNode* deleteNode(TreeNode* root, int key) {
      TreeNode* keyNode = searchBST(root, key);
      if (keyNode == nullptr) return nullptr;
      if (keyNode->left == nullptr && )
    }
};
*/


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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        // 找到了指定点
        if (root->val == key){
          // 这个返回值会给下面迭代的结果
          if (root->left ==nullptr) {
            return root->right;
          }else if (root->right == nullptr) {
            return root->left;
          }else{
            // 要被删除的节点依旧有左右子树
            TreeNode *rtChild = root->right;
            // 右子树的左子树不为空
            // 循环，直至其左子树为空
            while (rtChild->left != nullptr){
              rtChild = rtChild->left;
            }
            // 移动被删除节点的左子树
            rtChild->left = root->left;
            TreeNode *temp = root;
            // 删除节点
            root = root->right;
            delete temp;
            return root;
          }
        }
        // 节点被删除后会在这里连接
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};


