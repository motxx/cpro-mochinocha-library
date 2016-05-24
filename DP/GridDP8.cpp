  // TEMPLATE GRID-DP-8  not verified
  // 「1つ上」「1つ左」「1つ左上」「1つ右上」さえあれば状況判断ができるタイプ
  // メモリが 1 << (W+1) だけ必要になる
  int dp[1 << (W + 1)];
  rep(y, H) {
    rep(x, W) {
      rep(i, 1<<(W+1)) {
        bool left     = (x != 0) && ((i & 1) == 1);
        bool upright  = (y != 0) && (x != W - 1) && (((i >> (W - 2)) & 1) == 1);
        bool up       = (y != 0) && (((i >> (W - 1)) & 1) == 1);
        bool upleft   = (x != 0) && (y != 0) && (((i >> W) & 1) == 1);

        rep(k, 2) {
          // 接続判定処理

          int next = ((i << 1) + k) & ((1 << (W + 1)) - 1);

          // 更新処理

        }
      }
    }
  }