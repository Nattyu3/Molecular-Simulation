// 速度分布の確認
#include <bits/extc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

void calc_velocity_distribution(vector<double> vl, int npa)
{
  int i,j;

  enum {
    N = 20
  };
  int vel_dis[N];
  double dv;
  double dis_min,dis_max;

  dis_min = -2;
  dis_max =  2;
  dv = (dis_max - dis_min)/N;
  
  for(i = 0; i < N; i++){
    vel_dis[i] = 0;
  }
  for(i = 0; i < npa*3; i++){
    j = (vl[i]-dis_min)/dv;
    if(j >= 0 && j < N){
      vel_dis[j]++;
    }
  }
  for(i = 0; i < N; i++){
    printf("% f %f\n",
           dv*(i+0.5)+dis_min,
           (double)vel_dis[i]/npa*3);
  }
}

int main() {
 // アボガドロ定数 /mol
 // ボルツマン係数 J/K
 // 分子量 g/mol
  const double avogadro = 6.0221367e+23;
  const double kb       = 1.380658e-23;
  const double argon    = 39.948;

 // 長さ m
 // 質量 kg
 // 単位エネルギー J
 // 時間 s
  double unit_length = 3.4e-10;
  double unit_mass   = argon / avogadro * 1e-3;
  double unit_erg_J  = 120. * kb;
  double unit_time   = sqrt(unit_length * unit_length * unit_mass / unit_erg_J);

 // 密度 kg/m^3
 // 設定温度 K
 // 時間刻み幅 s
  double density     = 1.38e+3;
  double target_temp = 86.64;
  double h           = 2.0e-15;

 // 無次元化
  density = density * pow(unit_length, 3) / unit_mass;
  target_temp = target_temp * kb / unit_erg_J;
  h = h / unit_time;

  enum {
    N = 4
  };
  int nla = 2;
  int npa = N * (int)pow(nla, 3);

  vector<double> vl(npa*3); // x, y, z
  vector<double> sum(3, 0.); // x, y, z
  double ma = 0;
  srand(time(NULL));

  /* 速度の設定 */
  for(int i = 0; i < npa*3; i++){
    double u0 = (double)rand()/RAND_MAX;
    double u1 = (double)rand()/RAND_MAX;
    vl[i] = sqrt(-2.*log(u0))*cos(2.*M_PI*u1);
  }

  /* 速度の和の計算 */
  for(int i = 0; i < npa*3; i += 3){
    for(int j = 0; j < 3; j++){
      sum[j] += vl[i+j];
    }
  }

  /* 速度の和をゼロになるようにする */
  for(int i = 0; i < 3; i++){
    sum[i] /= npa;
  }
  for(int i = 0; i < npa*3; i += 3){
    for(int j = 0; j < 3; j++){
      vl[i+j] -= sum[j];
    }
  }

  calc_velocity_distribution(vl, npa);

  return 0;
}
