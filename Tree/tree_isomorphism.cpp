namespace tree {

using tree_type = vector<vector<int>>;

string to_string(tree_type const& t, int v, int par = -1) {
  ostringstream oss;
  oss << '(';
  vector<string> children;
  children.resize(t[v].size());
  for(int u: t[v]) {
    if(u == par) continue;
    children.emplace_back(to_string(t, u, v));
  }
  sort(children.begin(), children.end());
  for(auto const& child: children)
    oss << child;
  oss << ')';
  return oss.str();
}

bool tree_isomorphism(tree_type const& a, tree_type const& b) {
  return to_string(a, 0) == to_string(b, 0);
}

}