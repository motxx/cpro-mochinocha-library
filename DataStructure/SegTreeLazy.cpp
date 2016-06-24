struct SegTree {
  int N; 
  vector<ll> dat, sum;
  SegTree(int n) {
    N = 1;
    while(N < n) N *= 2;
    dat.assign(2 * N - 1, 0);
    sum.assign(2 * N - 1, 0);
  }
 
  void add(int a, int b, ll x) { add(a, b, x, 0, 0, N); }
 
  ll add(int a, int b, ll x, int k, int l, int r) {
    if(b <= l || r <= a) { return dat[k]; }
    if(a <= l && r <= b) {
      sum[k] += x;
      return dat[k] += x;
    }
    int m = (l + r) / 2;
    return dat[k] = max(add(a, b, x, 2 * k + 1, l, m), add(a, b, x, 2 * k + 2, m, r)) + sum[k];
  }
 
  ll getMax(int a, int b) { return getMax(a, b, 0, 0, N); }
  ll getMax(int a, int b, int k, int l, int r) {
    if(b <= l || r <= a) { return -1<<29; }
    if(a <= l && r <= b) { return dat[k]; }
    int m = (l + r) / 2;
    return max(getMax(a, b, 2 * k + 1, l, m), getMax(a, b, 2 * k + 2, m, r)) + sum[k];
  }
 
};