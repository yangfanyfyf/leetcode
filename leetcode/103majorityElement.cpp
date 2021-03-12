// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/majority-element
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int times = nums.size() / 2;
        int t = 1;
        for (int i = 0; i != nums.size() - 1; ++i){
            if (nums[i] != nums[i + 1]){
                t = 1;
                continue;
            }
            ++t;
            if ( t > times){
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

