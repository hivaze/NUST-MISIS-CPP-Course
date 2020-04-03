#include <iostream>
#include <cmath>

#include "rectangle.h"

bool Rectangle::operator==(Rectangle & rec) const {
    return isEqualF(x, rec.x) && isEqualF(y, rec.y) && isEqualF(width, rec.width) && isEqualF(height, rec.height);
}

bool Rectangle::operator!=(Rectangle & rec) const {
    return !(*this == rec);
}

Rectangle Rectangle::intersection(const Rectangle & rec2) {
    float leftX   = fmaxf( x, rec2.x );
    float rightX  = fminf( x + width, rec2.x + rec2.width );
    float topY    = fmaxf( y, rec2.y );
    float bottomY = fminf( y + height, rec2.y + rec2.height );
    if ( leftX <= rightX && topY <= bottomY ) {
        return Rectangle( leftX, topY, rightX - leftX, bottomY - topY );
    }
    else {
        return Rectangle(0, 0, 0, 0);
    }
}

std::ostream &operator<<(std::ostream &os, const Rectangle & rectangle) {
    os << "rect " << rectangle.getX() << " " << rectangle.getY() << " " << rectangle.getWidth() << " " << rectangle.getHeight();
    return os;
}

std::istream &operator>>(std::istream &is, Rectangle & rectangle) {
    float x, y, width, height;
    std::string text{"rect "};
    std::cin >> text;
    std::cin >> x;
    std::cin >> y;
    std::cin >> width;
    std::cin >> height;
    rectangle = Rectangle(x, y, width, height);
    return is;
}