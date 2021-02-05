// 给定一个有序数组，在原地删除重复的元素，并且返回移除后的数组的长度
// 实际上没有进行删除

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
          return 0;
        }
        int i = 0;
        for (int j = 1; j != nums.size(); ++j){
          if (nums[i] != nums[j]){
            nums[++i] = nums[j];
          }
        }
        return ++i;
    }
};