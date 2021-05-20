// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。



// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4cnxd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if (n <= 2){
        return n;
      }
      int slow = 2, fast = 2;
      while (fast < n){
        if (nums[slow - 2] != nums[fast]){
          nums[slow] = nums[fast];
          ++slow;
        }
        ++fast;
      }
      return slow;
    }
};


// 不用swap，直接重新赋值即可
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if (n <= 2) return n;
      int k = 2;
      for (int i = 2; i != n; ++i){
        if (nums[k - 2] != nums[i]){
          nums[k++] = nums[i];
        }
      }
      return k;
    }
};