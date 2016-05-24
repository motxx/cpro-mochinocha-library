namespace graph::visualizer {

using graph_type = vector<vector<int>>;

void directed_graph(graph_type& g, const string fname = "digraph") {
  const string gfname = "__graph_vis_out_" + fname + ".dot";
  ofstream ofs(gfname);
  ofs << "digraph {" << endl;
  rep(i, g.size()) rep(k, g[i].size()) {
    ofs << i << " -> " << g[i][k] << ";" << endl;
  }
  ofs << "}" << endl;
  ofs.close();
  int r = system(("dot -Tpng " + gfname + " > " + fname + ".png").c_str());
  if(!WEXITSTATUS(r)) {
    r = system(("rm " + gfname).c_str());
    if(!WEXITSTATUS(r)) {
//      r = system(("open " + fname + ".png").c_str()); assert(!r && "open error");
    } else assert(0 && "rm error");
  } else assert(0 && "dot error");
}

}