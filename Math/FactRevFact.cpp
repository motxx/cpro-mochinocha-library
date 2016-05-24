namespace math {

const int MaxFact = ;

struct FactRevFactList {

  array<long long, MaxFact+1> fact_;
  array<long long, MaxFact+1> rev_fact_;

  FactRevFactList() {
    fact_[0] = 1;
    for(int i=1; i<MaxFact; i++) {
      fact_[i] = fact_[i-1] * i;
      fact_[i] %= MOD;
    }

    rev_fact_[MaxFact-1] = mod_pow(fact_[MaxFact-1], (long long)MOD-2, MOD);

    for(int i=MaxFact-2; i>=0; i--) {
      rev_fact_[i] = rev_fact_[i+1] * (i+1);
      rev_fact_[i] %= MOD;
    }
  }

  long long fact(int x) const { return fact_[x]; }
  long long fact_inv(int x) const { return rev_fact_[x]; }

};

}