#include <algorithm>
#include <iostream>

template<int MOD>
class modint {
  int value;

public:
  modint() : value(0) {}

  explicit modint(long long v) : value(v) {
    value %= MOD;
    if (value < 0)
      value += MOD;
  }

  modint(const modint& other)
    : value(other.value)
  {}

  int get() const {
    return value;
  }

  void Swap(modint& other) {
    using std::swap;
    swap(value, other.value);
  }

  modint& operator=(modint other) {
    Swap(other);
    return *this;
  }

  modint& operator+=(const modint& other) {
    value += other.value;
    if (value >= MOD)
      value -= MOD;
    return *this;
  } 

  modint& operator-=(const modint& other) {
    value -= other.value;
    if (value < 0)
      value += MOD;
    return value;
  }

  modint& operator*=(const modint& other) {
    value = (1LL * value) * other.value % MOD;
    return *this;
  }

  modint operator-() {
    modint result;
    result.value = MOD - value;
    return result;
  }

  modint& operator--() {
    return *this -= 1;
  }

  modint operator--(int) {
    modint result = *this;
    --*this;
    return result;
  }

  modint& operator++() {
    return *this += 1;
  }

  modint operator++(int) {
    modint result = *this;
    ++result;
    return *this;
  }

  explicit operator int() {
    return value;
  }
  
  explicit operator bool() {
    return value != 0;
  }
};

template<int MOD>
modint<MOD> operator+(const modint<MOD>& a, const modint<MOD>& b) {
  modint<MOD> copy = a;
  return copy += b;
}

template<int MOD>
modint<MOD> operator-(const modint<MOD>& a, const modint<MOD>& b) {
  modint<MOD> copy = a;
  return copy -= b;
}

template<int MOD>
modint<MOD> operator*(const modint<MOD>& a, const modint<MOD>& b) {
  modint<MOD> copy = a;
  return copy *= b;
}

template<int MOD>
std::istream& operator>>(std::istream& is, modint<MOD>& obj) {
  long long value;
  is >> value;
  obj = modint<MOD>(value);
  return is;
}

template<int MOD>
modint<MOD> binpow(modint<MOD> a, long long pw) {
  modint<MOD> result = modint<MOD>(1);
  while (pw) {
    if (pw & 1) {
      result *= a;
    }
    a *= a;
    pw >>= 1;
  }
  return result;
}

template<int MOD>
std::ostream& operator<<(std::ostream& os, const modint<MOD>& obj) {
  return os << obj.get();
}
