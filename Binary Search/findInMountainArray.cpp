// 给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

// 如果不存在这样的下标 index，就请返回 -1。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x49ha1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr){
      int n = mountainArr.length();
      int left = 0, right = n - 1;
      while (left < right){
        int mid = left + (right - left) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)){
          left = mid + 1;
        }else{
          right = mid;
        }
      }
      return left;
    }
    

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int left1 = 0, right1 = peak;
        while (left1 <= right1){
          int mid1 = left1 + (right1 - left1) / 2;
          int midValue = mountainArr.get(mid1);
          if (midValue == target){
            return mid1;
          }else if (midValue > target){
            right1 = mid1 - 1;
          }else {
            left1 = mid1 + 1;
          }
        }

        int left2 = peak + 1, right2 = mountainArr.length() - 1;
        while (left2 <= right2){
          int mid2 = left2 + (right2 - left2) / 2;
          int midValue2 = mountainArr.get(mid2);
          if (midValue2 == target){
            return mid2;
          }else if (midValue2 > target){
            left2 = mid2 + 1;
          }else{
            right2 = mid2 - 1;
          }
        }

        return -1;
    }
};