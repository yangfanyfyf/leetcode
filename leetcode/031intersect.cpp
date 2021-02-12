// 给定两个数组，编写一个函数来计算它们的交集。

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 遍历
        vector<int> ret;
        for (auto x : nums1){
            auto it = find(nums2.begin() ,nums2.end(), x);
            if (it != nums2.end()){
                nums2.erase(it);
                ret.push_back(x);
            }
        }
        return ret;
    }
};
*/
// 可以先排序，再用双指针

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//       vector<int> ret;
//       sort(nums1.begin(), nums1.end());
//       sort(nums2.begin(), nums2.end());
//       int p1 = 0, p2 = 0;
//       while (p1 != nums1.size() && p2 != nums2.size()){
//         if (nums1[p1] == nums2[p2]){
//           ret.push_back(nums1[p1]);
//           ++p1;
//           ++p2;
//         }else if(nums1[p1] > nums2[p2]){
//           ++p2;
//         }else if (nums1[p1] < nums2[p2]){
//           ++p1;
//         }
//       }
//       return ret;
//     }
// };

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> ret;
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      int p1 = 0, p2 = 0;
      while (p1 != nums1.size() && p2 != nums2.size()){
        if (nums1[p1] == nums2[p2]){
          ret.push_back(nums1[p1]);
          ++p1;
          ++p2;
        }else if(nums1[p1] > nums2[p2]){
          ++p2;
        }else if (nums1[p1] < nums2[p2]){
          ++p1;
        }
      }
      return ret;
    }


int main(){
  vector<int> nums1{3,2,2,4,1};
  vector<int> nums2{2,2,2};
  vector<int> ret = intersect(nums1, nums2);
  for (auto x : ret){
    cout << x << " ";
  }
  cout << endl;
}
