namespace tree {

template<class value_type>
struct segtree {
  int N; 
  vector<value_type> dat, sum;
  segtree(int n) {
    N = 1;
    while(N < n) N *= 2;
    dat.assign(2 * N - 1, 0);
    sum.assign(2 * N - 1, 0);
  }
 
  void add(int a, int b, value_type x) { add(a, b, x, 0, 0, N); }
  void update(int a, value_type x) { add(a, a+1, x, 0, 0, N); }
 
  value_type add(int a, int b, value_type x, int k, int l, int r) {
    if(b <= l || r <= a) { return dat[k]; }
    if(a <= l && r <= b) {
      sum[k] += x;
      return dat[k] += x;
    }
    int m = (l + r) / 2;
    return dat[k] = max(add(a, b, x, 2 * k + 1, l, m), add(a, b, x, 2 * k + 2, m, r)) + sum[k];
  }

  value_type get(int a) { return getMax(a, a+1, 0, 0, N); }
  value_type getMax(int a, int b) { return getMax(a, b, 0, 0, N); }
  value_type getMax(int a, int b, int k, int l, int r) {
    if(b <= l || r <= a) { return -1<<29; } // MINIMUM
    if(a <= l && r <= b) { return dat[k]; }
    int m = (l + r) / 2;
    return max(getMax(a, b, 2 * k + 1, l, m), getMax(a, b, 2 * k + 2, m, r)) + sum[k];
  }
 
};

} // namespace tree