  // TEMPLATE GRID-DP-4  not verified
  // 「1つ上」「1つ左」さえあれば状況判断ができる
  int dp[1 << W];
  dp[0] = 1;
  rep(y, H) {
    rep(x, W) {
      rep(i, 1<<W) {
        bool left = (x != 0) && ((i & 1) == 1);
        bool up   = (y != 0) && (((i >> (W - 1)) & 1) == 1);

        rep(k, 2) {
          // 接続判定処理

          int next = ((i << 1) + k) & ((1 << W) - 1);

          // 更新処理
        }
      }
    }
  }