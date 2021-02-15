// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

 vector<int> plusOne(vector<int>& digits){
   for(int i = digits.size() - 1; i >= 0; --i){
     digits[i] = digits[i] + 1;
     digits[i] = digits[i] % 10;
     if (digits[i] != 0){
       return digits;
     }
   }
   digits.insert(digits.begin(), 1);
   return digits;
 }