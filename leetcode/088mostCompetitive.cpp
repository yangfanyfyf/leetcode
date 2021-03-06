// 给你一个整数数组 nums 和一个正整数 k ，返回长度为 k 且最具 竞争力 的 nums 子序列。

// 数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。

// 在子序列 a 和子序列 b 第一个不相同的位置上，如果 a 中的数字小于 b 中对应的数字，那么我们称子序列 a 比子序列 b（相同长度下）更具 竞争力 。 例如，[1,3,4] 比 [1,3,5] 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， 4 小于 5 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-the-most-competitive-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      stack<int> myStack;
      int n = nums.size();
      vector<int> ret(k, 0);
      if (n == k){
        return nums;
      }
      // 最多可以弹出的数字个数
      int len = n - k;
      for (int i = 0; i != n; ++i){
        while (!myStack.empty() && len > 0 && nums[i] < nums[myStack.top()]){
          myStack.pop();
          --len;
        }
        myStack.push(i);
      }
      for (int i = 0; i != len; ++i){
        myStack.pop();
      }
      for (int i = k - 1; i >= 0; --i){
        ret[i] = nums[myStack.top()];
        myStack.pop();
      }
      return ret;
    }
};