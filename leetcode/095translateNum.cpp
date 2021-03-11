// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。

// 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/9vgn1j/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int translateNum(int num) {
      string src = to_string(num);
      int p = 0, q = 0, r = 1;
      for (int i = 0; i != src.size(); ++i){
        p = q;
        q = r;
        r = 0;
        r += q;
        if (i == 0){
          continue;
        }
        
        auto pre = src.substr(i - 1, 2);
        if (pre <= "25" && pre >= "10"){
          r += p;
        }
      }
      return r;
    }
};