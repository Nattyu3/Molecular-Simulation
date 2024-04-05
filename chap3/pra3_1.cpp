// 分布を調べる
#include <bits/extc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

int main() {
  double d;
  int n = 5;
  vector<int> bunpu(n, 0);

  srand(time(NULL));
  rep(i, 10) {
    d = (double)rand()/RAND_MAX*5;
    printf("d = %f\n",d);
    bunpu[(int)d]++;
  }

  rep(i, n) {
    printf("bunpu[%d]=%d\n",i,bunpu[i]);
  }

  return 0;
}