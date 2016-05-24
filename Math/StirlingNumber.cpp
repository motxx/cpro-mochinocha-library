/*
  スターリング数
  異なるN個をちょうどKグループに分けるときの方法の数
  高々Kグループに分ける場合は、グループi(1<=i<=K)をN回選ぶ方法の数となり、これは単なる重複順列でK^Nとなる
  Verified: http://yukicoder.me/problems/663
 */
namespace math { namespace combination {

namespace memorized { namespace stirling_number {
  enum { max_value = COMBINATION_MAX };
  bool __computed = false; inline bool computed() {if(__computed) { return true; } else { __computed = true; return false; }}
  ll dp[max_value][max_value];
}}

int stirling_number(int N, int K) {
  using memorized::stirling_number::dp;
  if(memorized::stirling_number::computed()) { return dp[N][K]; }

  // Make stirling numbers
  using memorized::stirling_number::max_value;

  REP(i, 1, max_value) {  // undefined when i = 0
    dp[i][1] = dp[i][i] = 1;
    REP(j, 2, i) {
      dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
      dp[i][j] %= MOD;
    }
  }

  return dp[N][K];
}

}}