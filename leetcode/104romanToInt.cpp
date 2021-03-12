class Solution {
public:
    int getInt(char c){
      switch(c){
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
      }
      return -1;
    }
    int romanToInt(string s) {
      int ans = 0;
      int n = s.size();
      for (int i = 0; i < n; ++i){
        if (i < n - 1 && getInt(s[i]) >= getInt(s[i + 1]) || i == n - 1){
          ans += getInt(s[i]);
        }else {
          ans += getInt(s[i + 1]) - getInt(s[i]);
          ++i;
        }
      }
      return ans;
    }
};