// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。

// 数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。

// 如果不存在，则输出 -1。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/next-greater-element-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      vector<int> ret(n, -1);
      if (n == 0){
        return {};
      }
      for (int i = 0; i != n; ++i){
        int j = i + 1;
        j = (j == n) ? 0 : i + 1;
        while (j != i){
          if (nums[j] > nums[i]){
            ret[i] = nums[j];
            break;
          }
          j = (j + 1 == n) ? 0 : j + 1;
        }
      }
      return ret;
    }
};


// 单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      if (n == 0){
        return {};
      }
      vector<int> ret(n, -1);
      stack<int> stk;
      // 使用求余数的方法保证了从尾部到头部的循环
      for(int i = 0; i != n * 2 - 1; ++i){
        // 会弹出比当前位置小的值？
        while (!stk.empty() && nums[stk.top()] < nums[i % n]){
          ret[stk.top()] = nums[i % n];
          stk.pop();
        }
        stk.push(i % n);
      }
      return ret;
    }
};