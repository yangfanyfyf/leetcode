// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回滑动窗口中的最大值。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/5dnu5e/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 返回值是每个范围内的最大值
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      deque<int> monoQueue;
      // 先压入k个，填充
      for (int i =  0; i != k; ++i){
        while (!monoQueue.empty() && nums[i] >= nums[monoQueue.back()]){
          monoQueue.pop_back();
        }
        monoQueue.push_back(i);
      }

      vector<int> ans = {nums[monoQueue.front()]};
      for (int i = k; i != n; ++i){
        while (!monoQueue.empty() && nums[i] >= nums[monoQueue.back()]){
          monoQueue.pop_back();
        }
        monoQueue.push_back(i);
        while (monoQueue.front() <= i - k){
          monoQueue.pop_front();
        }
        ans.push_back(nums[monoQueue.front()]);
      }
      return ans;
    }
};