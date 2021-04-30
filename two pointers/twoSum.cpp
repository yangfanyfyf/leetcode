// 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

// 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

// 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x18hfc/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0, right = numbers.size() - 1;
      int sum = 0;
      while (left < right){
        sum = numbers[left] + numbers[right];
        if (sum == target){
          return {left + 1, right + 1};
        }else if (sum < target){
          ++left;
          while (left < right && numbers[left] == numbers[left - 1]){
            ++left;
          }
        }else if (sum > target){
          --right;
          while (left < right && numbers[right] == numbers[right + 1]){
            --right;
          }
        }
      }
      return {};
    }
};