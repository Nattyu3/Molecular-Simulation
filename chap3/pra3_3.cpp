// Box-Mullar法を使用した乱数の分布
#include <bits/extc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

int main() {
  int n = 20;
  vector<int> bunpu(n, 0);

  srand(time(NULL));
  rep(i, 100000) {
    double u0 = (double)rand()/RAND_MAX;
    double u1 = (double)rand()/RAND_MAX;
    printf("%f, %f\n",u0, u1);
    double S = sqrt(-2. * log(u0)) * cos(2. * M_PI * u1);
    S *= 4.;
    S += 10.;
    if (0 <= S && S < n) bunpu[(int)S]++;
  }

  rep(i, n) {
    printf("bunpu[%d]=%d\n",i,bunpu[i]);
  }

  rep(i, n) {
    if (i >= 10) printf("%d: ",i);
    else printf(" %d: ",i);
    rep(j, bunpu[i] / 500) {
      printf("*");
    }
    printf("\n");
  }  

  return 0;
}