// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

// 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。



class Solution {
private:
    int start;
    int end;
public:
    void reverseString(vector<char>& s) {
        start = 0;
        end = s.size() -1;
        helper(start, end, s);
    }
    
    
    void helper(int start, int end, vector<char> &s){
        if (start >= end)
            return;
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        ++start;
        --end;
        helper(start, end, s);
    }
};