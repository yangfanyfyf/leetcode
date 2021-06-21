// 替换字符串中的空格

class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for (int i = 0; i != s.size(); ++i){
            if (s[i] != ' '){
                ret += s[i];
            }else {
                ret += "%20";
            }
        }
        return ret;
    }
};