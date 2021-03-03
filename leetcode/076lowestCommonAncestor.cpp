// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。


// 分别进行两次遍历，存储经过的节点，然后比较
class Solution {
public:
    vector<TreeNode* > treeTraverse(TreeNode* root, TreeNode* toFind){
      vector<TreeNode* > ret;
      TreeNode *curr = root;
      ret.emplace_back(root);
      while (curr != toFind){
        if (curr->val > toFind->val){
          curr = curr->left;
          ret.emplace_back(curr);
        }else {
          curr = curr->right;
          ret.emplace_back(curr);
        }
      }
      return ret;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector<TreeNode* > pathP = treeTraverse(root, p);
      vector<TreeNode* > pathQ = treeTraverse(root, q);
      TreeNode *ancestor;
      for (int i = 0; i != pathP.size() && i != pathQ.size(); ++i){
        if (pathP[i] == pathQ[i]){
          ancestor = pathP[i];
        }else {
          break;
        }
      }
      return ancestor;
    }
};


// 一次遍历，找到两个值的的分叉点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode *ancestor = root;
      while (true){
        if (ancestor->val > p->val && ancestor->val > q->val){
          ancestor = ancestor->left;
        }else if (ancestor->val < p->val && ancestor->val < q->val){
          ancestor = ancestor->right;
        }else{
          break;
        }

      }
      return ancestor;
    }
};