struct unicycle_graph {
  
  /*
    assumed bidirectional graph
    1. check graph_type
    2. add all edges
    3. run build()
   */

  int N;

  using graph_type = pair<int, ll>; // to, cost;
  vector<vector<graph_type>> g;

  vector<int> cycle_vs_;
  vector<bool> in_cycle_v_;

  using edge = pair<int, int>;  // end points
  set<edge> in_cycle_edge_;

  unicycle_graph(int n) : N(n), g(n), in_cycle_v_(n) {}

  void add_edge(int f, int t, int c) {
    g[f].emplace_back(t, c);
    g[t].emplace_back(f, c);
  }

  void build() {
    vector<bool> vis(N);
    vector<int> prev(N);

    std::function<bool(int, int)> dfs = [&](int x, int p) {
      for(auto const& e: g[x]) {
        int to, cost; tie(to, cost) = e;
        if(to == p) { continue; }
        prev[to] = x;
        if(vis[to]) {
          for(int curr = x; curr != to; curr = prev[curr]) {
            cycle_vs_.push_back(curr);
            in_cycle_v_[curr] = 1;
            in_cycle_edge_.emplace(prev[curr], curr);
            in_cycle_edge_.emplace(curr, prev[curr]);
          }
          cycle_vs_.push_back(to);
          in_cycle_v_[to] = 1;
          in_cycle_edge_.emplace(to, prev[to]);
          in_cycle_edge_.emplace(prev[to], to);
          reverse(all(cycle_vs_));
          return true;
        }
        else {
          vis[to] = 1;
          if(dfs(to, x)) { return true; }
        }
      }
      return false;
    };

    rep(i, N) {
      if(!vis[i]) { vis[i] = 1; if(dfs(i, -1)) { break; } }
    }
  }

  bool in_cycle(int x) { return in_cycle_v_[x]; }
  bool in_cycle_edge(int f, int t) { return in_cycle_edge_.count({f, t}); }
  vector<int> const& cycle_vertices() { return cycle_vs_; }

};