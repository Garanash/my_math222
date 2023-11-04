#ifndef S21_MATH_H
#define S21_MATH_H

#define s21_INF 1.0 / 0.0
#define s21_PI 3.14159265358979323846
#define s21_SQRT3 1.732050807569
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-6

#ifndef DBL_MAX
#define DBL_MAX 1.7976931348623157e+308
#endif

#ifndef DBL_MIN
#define DBL_MIN 2.2250738585072014e-308
#endif

long double s21_atan(double x);
long double s21_sin(double x);
long double s21_exp(double x);
int s21_abs(int x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double fact(long double n);
long double s21_asin(double x);
long double s21_cos(double x);
long double s21_floor(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
#endif
