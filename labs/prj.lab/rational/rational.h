#ifndef RATIONAL_RATIONAL_H_102019
#define RATIONAL_RATIONAL_H_102019

#include <iosfwd>
#include <algorithm>

//! \brief Рациональные числа.
class Rational {
public:

    Rational() = default;
    Rational(const Rational&) = default;
    explicit Rational(const int num);
    Rational(const int num, const int denum);

    Rational& operator=(const Rational&) = default;

    int num() const { return num_; }
    int denum() const { return denum_; }

    Rational operator-() const;
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    bool operator==(const Rational& rhs) const;

    std::istream& read_from(std::istream& istrm);
    std::ostream& write_to(std::ostream& ostrm) const;

private:

    static int GCD(int n, int d) {
        while (d) {
            n %= d;
            std::swap(n, d);
        }
        return n;
    }

    void normalize();

    int num_{0};

    int denum_{1};

    const static char delimiter_{'/'};

};

inline std::istream& operator>>(std::istream& istrm, Rational& r) {
    return r.read_from(istrm);
}
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& r) {
    return r.write_to(ostrm);
}

inline Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) += rhs;
}

inline Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) -= rhs;
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) *= rhs;
}

inline Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) /= rhs;
}

#endif
