namespace math {

constexpr int MaxComb = ;

struct Combination {

  long long comb_[MaxComb][MaxComb];
    
  Combination() {
    rep(i, MaxComb) {
      comb_[i][0] = 1;
      REP(j, 1, i+1) {
        comb_[i][j] = comb_[i-1][j-1] + comb_[i-1][j];
        comb_[i][j] %= MOD;
      }
    }
  }

  long long comb(int n, int r) const { return comb_[n][r]; }

};

}