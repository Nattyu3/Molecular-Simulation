// LJポテンシャルの微分
#include <stdio.h>
#include <math.h>
int main() {
  int i,j;
  double cd[6], df[3], dd[3];
  double rd,dphi;
  for(i = 0; i < 6; i++){
    cd[i] = 0;
  }
  i = 0; j = 3;
  for(cd[j] = 1.0; cd[j] < 4.0; cd[j] += 0.01){
    dd[0] = cd[i]   - cd[j];
    dd[1] = cd[i+1] - cd[j+1];
    dd[2] = cd[i+2] - cd[j+2];
    rd  = dd[0]*dd[0] + dd[1]*dd[1] + dd[2]*dd[2];
    dphi = 4.0*(12.0*pow(rd,-7) - 6.0*pow(rd,-4));
    df[0] = dphi*dd[0];
    df[1] = dphi*dd[1];
    df[2] = dphi*dd[2];
    printf("%f % f\n",cd[j],df[0]);
  }
  return 0;
}