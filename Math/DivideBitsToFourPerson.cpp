// 4人で分け合う(<=> 3人で分けて幾つか残しておく) O(4^N) 過不足なし
rep(a, 1<<N) {
  int remain_a = (1 << N) - 1 - a;
  for(int b = remain_a; b >= 0; b--) {
    b &= remain_a;
    int remain_b = (1 << N) - 1 - a - b;
    for(int c = remain_b; c >= 0; c--) {
      c &= remain_b;
      int d = (1 << N) - 1 - a - b - c;

    }
  }
}