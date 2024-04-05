// 1次元上に並べる
#include <bits/extc++.h>
using namespace std;

int main() {
  enum {
    N = 4
  };
  int i;
  int npa = 0;
  vector<double> cd(N*3);
  double l = 1.0;
  // x only 1次元
  for(i = 0; i < N; i++){
    cd[npa*3]   = l*i;
    cd[npa*3+1] = 0;
    cd[npa*3+2] = 0;
    npa++;
  }
  for(i = 0; i < npa*3; i += 3){
    printf("%d %f %f %f\n", i/3, cd[i], cd[i+1], cd[i+2]);
  }
  return 0;
}