#include <iostream>
#include <cmath>

#include "segm.h"

bool Segm::operator==(Segm &segm) const {
    return isEqualF(x, segm.x) && isEqualF(y, segm.y) && isEqualF(length_x, segm.length_x) && isEqualF(length_y, segm.length_y);
}

bool Segm::operator!=(Segm &segm) const {
    return !(*this == segm);
}

Segm Segm::intersection(const Segm& segm2) {
    float left   = fmaxf(x, segm2.x);
    float right  = fminf(x + length_x, segm2.x + segm2.length_x);
    float bot    = fmaxf(y, segm2.y);
    float top    = fminf(y + length_y, segm2.y + segm2.length_y);
    if ((right - left != 0) && (top - bot != 0)) {
        Segm temp(0, 0 , -1, -1);
        return temp;
    }
    Segm result(left, bot, right - left, top - bot);
    return result;
}

std::ostream &operator<<(std::ostream &os, const Segm & rectangle) {
    os << "segm " << rectangle.getX() << " " << rectangle.getY() << " " << rectangle.getXLength() << " " << rectangle.getYLength();
    return os;
}

std::istream &operator>>(std::istream &is, Segm & rectangle) {
    float x, y, x_length, y_length;
    std::string text{"segm "};
    std::cin >> text;
    std::cin >> x;
    std::cin >> y;
    std::cin >> x_length;
    std::cin >> y_length;
    rectangle = Segm(x, y, x_length, y_length);
    return is;
}
