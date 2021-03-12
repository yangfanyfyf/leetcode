// 实现 strStr() 函数。

// 给定一个 haystack 字符串和一个 needle 字符串

// 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。

// 如果不存在，则返回  -1。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/implement-strstr
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 遍历
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }
        
        for (int i = 0; i != haystack.size(); ++i){
            if (haystack[i] == needle[0]){
                int flag = 0;
                for (int j = 0; j != needle.size(); ++j){
                    flag = 1;
                    if (haystack[i + j] != needle[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    return i;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }
        int i = 0, j = 0;
        while (i != haystack.size()){
            if (haystack[i] == needle[j]){
                ++j;
            }else {
                i -= j;
                j = 0;
            }
            ++i;
            if (j == needle.size()){
                return i - needle.size();
            }
        }
        return -1;
    }
};