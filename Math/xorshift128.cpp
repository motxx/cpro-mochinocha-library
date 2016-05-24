struct xor128 {
  unsigned x,y,z,w;
  xor128(): x(89165727), y(157892372), z(7777777), w(757328) {}
  unsigned next() {
    unsigned t=x^(x<<11);
    x=y;y=z;z=w;
    return w=w^(w>>19)^t^(t>>8);
  }
  unsigned next(unsigned k) {
    return next()%k;
  }
} rndgen;