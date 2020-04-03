#include <rational/rational.h>

#include <cassert>
#include <iostream>
#include <stdexcept>


Rational::Rational(const int num) : Rational(num, 1) {}

Rational::Rational(const int num, const int denum) : num_(num), denum_(denum) {
    if (0 == denum_) {
        throw std::invalid_argument("Rational ctor - zero denuminator.");
    }
    normalize();
}

void Rational::normalize() {
    if (num_ == 0) {
        denum_ = 1;
    } else {
        if (denum_ < 0) {
            num_ *= -1;
            denum_ *= -1;
        }
        int div = GCD(std::abs(num_), denum_);
        num_ /= div;
        denum_ /= div;
    }
}


bool Rational::operator==(const Rational& rhs) const {
    return num_ == rhs.num_ && denum_ == rhs.denum_;
}

std::istream& Rational::read_from(std::istream& istrm) {
    istrm >> num_;
    char c(0);
    istrm.get(c);
    if ('/' != c) {
        istrm.setstate(std::ios_base::failbit);
    }
    istrm.get(c);
    if (c < '0' || '9' < c) {
        istrm.setstate(std::ios_base::failbit);
    }
    istrm.putback(c);
    istrm >> denum_;
    normalize();
    return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm) const {
    ostrm << num_ << delimiter_ << denum_;
    return ostrm;
}

Rational Rational::operator-() const {
    return Rational(-num_, denum_);
}

Rational& Rational::operator+=(const Rational& rhs) {
    num_ = num_ * rhs.denum_ + rhs.num_ * denum_;
    denum_ = denum_ * rhs.denum_;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    num_ = num_ * rhs.denum_ - rhs.num_ * denum_;
    denum_ = denum_ * rhs.denum_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    num_ = num_ * rhs.num_;
    denum_ = denum_ * rhs.denum_;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    if (0 == rhs.num_) {
        throw std::invalid_argument("Rational::operator/= - divis    ion by zero");
    }
    num_ = num_ * rhs.denum_;
    denum_ = denum_ * rhs.num_;
    normalize();
    return *this;
}