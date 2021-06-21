// 找出数组中重复的数字。
// 使用哈希集合解决

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> temp;
        for (int i = 0; i != nums.size(); ++i){
            if (temp.count(nums[i]) == 1){
                return nums[i];
            }else {
                temp.insert(nums[i]);
            }
        }
        return -1;
    }
};