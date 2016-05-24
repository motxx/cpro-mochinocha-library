namespace visualizer {

ofstream ofs;

void init() {
  ofs = ofstream("data.js");
}

void polygon(Polygon& g) {
  ofs << "polygon_start" << g[0] << endl;
  REP(i, 1, g.size()) {
    ofs << "lineTo" << g[i] << endl;
  }
  ofs << "polygon_end()" << endl;
}

void show_picture() {
  ofs.close();
  int r = system("open visualizer.html");
  assert(!WEXITSTATUS(r));
}