// 二つの粒子の相互作用
#include <bits/extc++.h>

using namespace std;

int main() {
  enum {
    N = 2
  };
  int i,j;
  int n = N;
  double cd[N*3], fc[N*3];
  double df[3], dd[3];
  double rd,dphi;

  cd[0] = 1.0;  cd[1] = 1.0; cd[2] = 1.0;
  // cd[3] = 2.0;  cd[4] = 2.0; cd[5] = 2.0;
  cd[3] = 2.0;  cd[4] = 3.0; cd[5] = 1.0;
  for(i = 0; i < n*3; i++){
    fc[i] = 0;
  }
  i = 0; j = 3;
  dd[0] = cd[i]   - cd[j];
  dd[1] = cd[i+1] - cd[j+1];
  dd[2] = cd[i+2] - cd[j+2];
  rd  = dd[0]*dd[0] + dd[1]*dd[1] + dd[2]*dd[2];
  dphi = 4.0*(12.0*pow(rd,-7) - 6.0*pow(rd,-4));
  df[0] = dphi*dd[0];
  df[1] = dphi*dd[1];
  df[2] = dphi*dd[2];
  fc[i]   += df[0];
  fc[i+1] += df[1];
  fc[i+2] += df[2];
  fc[j]   -= df[0];
  fc[j+1] -= df[1];
  fc[j+2] -= df[2];
  for(i = 0; i < n; i++){
    printf("%d % f % f % f\n",i,fc[i*3],fc[i*3+1],fc[i*3+2]);
  }
}