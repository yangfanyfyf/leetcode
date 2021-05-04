// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

// 请你找出并返回这两个正序数组的 中位数。

class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k){
      int m = nums1.size(), n = nums2.size();
      int index1 = 0, index2 = 0;
      while (true){
        // 一个数组被完全忽略
        if (index1 == m){
          return nums2[index2 + k - 1];
        }
        if (index2 == n){
          return nums1[index1 + k - 1];
        }
        if (k == 1){
          return min(nums1[index1], nums2[index2]);
        }
        // 普通情况
        // 判断中间值的大小
        int newIndex1 = min (index1 + k / 2 - 1, m - 1);
        int newIndex2 = min (index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        // 忽略了 index1 前的数字
        if (pivot1 <= pivot2){
          // k 去除掉已经无效的数字，在剩下的数字中继续寻找
          k -= newIndex1 - index1 + 1;
          index1 = newIndex1 + 1;
        }else {
          k -= newIndex2 - index2 + 1;
          index2 = newIndex2 + 1;
        }
      }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int totalLength = nums1.size() + nums2.size();
      // 中位数可能是一个或者是两个的平均值
      if  (totalLength % 2 == 1){
        return getKthElement(nums1, nums2, (totalLength + 1) / 2);
      }else {
        return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
      }
    }
};