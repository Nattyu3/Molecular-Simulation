// 分布を調べる2
#include <bits/extc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

int main() {
  double d;
  int n = 5;
  vector<int> bunpu(n, 0);

  srand(time(NULL));
  rep(i, 100000) {
    d = (double)rand()/RAND_MAX*5;
    printf("d = %f\n",d);
    bunpu[(int)d]++;
  }

  rep(i, n) {
    printf("bunpu[%d]=%d\n",i,bunpu[i]);
  }

  rep(i, n) {
    printf("%d: ",i);
    rep(j, bunpu[i] / 1000) {
      printf("*");
    }
    printf("\n");
  }  

  return 0;
}