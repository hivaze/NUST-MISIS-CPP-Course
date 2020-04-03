#ifndef LABS_RECTANGLE_H
#define LABS_RECTANGLE_H

struct Rectangle {

private:

    float x, y;
    float width;
    float height;

    bool isEqualF(float value1, float value2) const {
        return std::abs(value1 - value2) < std::numeric_limits<double>::epsilon();
    }

public:

    Rectangle() = default;
    Rectangle(const Rectangle & rectangle) = default;
    Rectangle(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

    ~Rectangle() = default;

    // Площадь прямоугольника
    float square() const {
        return width * height;
    }

    bool isLine() const {
        return (height * width == 0) && (height > 0 || width > 0);
    }

    /*
     * Пересеченеи прямоугольников
     *
     * При отсутствии пересечения
     * rec1.intersection(rec2).square() == 0
     */
    Rectangle intersection(const Rectangle & rec2);

    Rectangle& operator=(const Rectangle & rectangle) = default;

    bool operator==(Rectangle & rec) const;
    bool operator!=(Rectangle & rec) const;

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getWidth() const {
        return width;
    }

    float getHeight() const {
        return height;
    }

};


#endif //LABS_RECTANGLE_H
