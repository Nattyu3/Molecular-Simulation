// 一辺の長さ
#include <bits/extc++.h>
#define ll long long

using namespace std;

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
    NUM_FCC_PARTICLE = 4
  };
  int nla = 2;
  int npa = NUM_FCC_PARTICLE * (int)pow(nla, 3);

  double side_unit = pow(NUM_FCC_PARTICLE / density, 1./3.);
  double side = side_unit * nla;

  cout << side_unit << endl;
  cout << side << endl;

  return 0;
}
