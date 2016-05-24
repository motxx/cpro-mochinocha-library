/*
  ベル数
  自然数を分割する方法の総数
  Verified: http://codeforces.com/contest/568/problem/B
 */
namespace math { namespace combination {

namespace memorized { namespace bell_number_arg1 {
  enum { max_value = COMBINATION_MAX };
  bool __computed = false; inline bool computed() {if(__computed) { return true; } else { __computed = true; return false; }}
  ll dp[max_value];
}}

int bell_number(int N) {
  using memorized::bell_number_arg1::dp;
  if(memorized::bell_number_arg1::computed()) { return dp[N]; }

  // Make bell numbers
  using memorized::combination::max_value;

  dp[0] = dp[1] = 1;
  REP(i, 1, max_value) rep(k, i+1) {
    dp[i+1] += (ll)comb(i, k) * dp[k] % MOD;
    dp[i+1] %= MOD;
  }
  return dp[N];
}

}}