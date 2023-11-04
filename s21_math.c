#include "s21_math.h"

long double s21_atan(double x) {
  long int n = 0;
  int sign1 = 0, sign2 = 0;
  if (x < 0.0) {
    x = -x;
    sign1 = 1;
  }
  if (x > 1.0) {
    x = 1.00 / x;
    sign2 = 1;
  }
  while (x > s21_PI / 12.00) {
    n++;
    x = (1.0 / (x + s21_SQRT3)) * ((x * s21_SQRT3) - 1.00);
  }
  x = x *
      (0.55913709 / (1.4087812 + (x * x)) + 0.60310579 - 0.05160454 * (x * x));
  while (n > 0) {
    x += s21_PI / 6;
    n--;
  }
  if (sign2) {
    x = s21_PI / 2.0 - x;
  }
  if (sign1) {
    x = -x;
  }
  return x;
}

int s21_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_acos(double x) {
  long double half_pi = s21_PI / 2.0;
  return half_pi - s21_asin(x);
}

long double s21_asin(double x) {
  return (x != 1 && x != -1) ? s21_atan(x / (s21_sqrt((1 - x * x))))
                             : x * s21_PI / 2;
}

long double s21_ceil(double x) {
  return ((long long)x < x) ? (long long)x + 1 : (long long)x;
}

long double s21_cos(double x) {
  long double res = 1;
  int exp = 2;
  int mp = -1;
  long double step = mp * (s21_pow(x, exp)) / fact(exp);
  while (step > 1e-10 || step < -1e-10) {
    res += step;
    exp += 2;
    mp = -mp;
    step = mp * (s21_pow(x, exp)) / fact(exp);
  }
  return res;
}

long double fact(long double n) {
  long double res = 1.00;
  for (long int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

long double s21_exp(double x) {
  long double step = 1.0;
  long double i = 1.0;
  long double res = 1.0;
  int flag = 0;
  if (x == s21_INF) {
    res = s21_INF;
  } else if (x == -s21_INF) {
    res = 0;
  } else {
    if (x < 0) {
      x *= -1;
      flag = 1;
    }
    while (s21_EPS < s21_fabs(step)) {
      step *= x / i;
      res += step;
      i++;
      if (res > __DBL_MAX__) {
        res = s21_INF;
        step = 0;
      }
    }
    if (flag) {
      res = 1 / res;
    }
  }
  return res;
}

long double s21_fabs(double x) {
  long double result = (x > 0) ? x : -x;
  return result;
}

long double s21_floor(double x) {
  return ((long int)x <= x) ? (long int)x : (long int)x - 1;
}

long double s21_fmod(double x, double y) {
  long double res = s21_NAN;
  if (y != 0.0) {
    res = x - ((int)(x / y) * y);
  }
  return res;
}

long double s21_log(double x) {
  long double result = 0;
  double y = 0;
  if (x == 0.0) {
    result = s21_INF;
  } else if (x == -s21_INF) {
    result = s21_NAN;
  } else if (x == s21_INF) {
    result = s21_INF;
  } else if (x > 0) {
    for (int i = 0; i < 1000; i++) {
      y = result;
      result = y + 2 * (x - s21_exp(y)) / (x + s21_exp(y));
    }
  } else {
    result = s21_NAN;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  int flag = 0;
  if (exp == 0) {
    result = 1;
  } else {
    if (base < 0 && (int)exp < exp) {
      result = s21_NAN;
    } else {
      if (base < 0) {
        base = -base;
        flag = 1;
      }
      if (base != 0) {
        result = s21_exp(exp * s21_log(base));
      } else {
        result = 0;
      }
      if (flag && (int)exp % 2 != 0) {
        result = -result;
      }
    }
    if (base == 0 && exp < 0) {
      result = s21_INF;
    }
  }
  return result;
}

long double s21_sin(double x) {
  long int n = 0, sign = 1;
  if (x < 0) {
    x = -x;
    sign = -sign;
  }
  x = s21_fmod(x, 2 * s21_PI);
  if (x > s21_PI) {
    x -= s21_PI;
    sign = -sign;
  }
  if (x > s21_PI / 2) {
    x = s21_PI - x;
  }
  long double sum = x, t = x;
  while (s21_fabs((double)t) >= 1e-10) {
    n++;
    t = -t * x * x / (2 * n) / (2 * n + 1);
    sum += t;
  }
  sum *= sign;
  return sum;
}

long double s21_sqrt(double x) {
  long double top = x + 1;
  long double bottom = 0;
  long double mid = -s21_NAN;
  while (top - bottom > 1e-6 && x > 0) {
    mid = (top + bottom) / 2.0;
    if (mid * mid < x) {
      bottom = mid;
    } else {
      top = mid;
    }
  }

  return mid;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }