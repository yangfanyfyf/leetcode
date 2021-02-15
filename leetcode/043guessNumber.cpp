

int guessNumber(int n) {
  int L = 0;
  int R = n;
  while (L <= R)
  {
    int mid = L + (R - L) / 2;
    if (guess(mid) == 0){
      return mid;
    }else if (guess(mid) == -1){
      R = mid - 1;
    }else{
      L = mid + 1;
    }
  }
  return -1;
}