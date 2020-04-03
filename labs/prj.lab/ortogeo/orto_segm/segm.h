#ifndef LABS_SEGM_H
#define LABS_SEGM_H

struct Segm {

private:

    float x, y;
    float length_x;
    float length_y;

    bool isEqualF(float value1, float value2) const {
        return std::abs(value1 - value2) < std::numeric_limits<double>::epsilon();
    }

public:

    Segm() = default;
    Segm(const Segm & segm) = default;
    Segm(float x, float y, float length_x, float length_y) {}

    ~Segm() = default;

    /*
     * Пересеченеи прямоугольников
     *
     * При отсутствии пересечения
     * todo
     */
    Segm intersection(const Segm & segm2);

    Segm& operator=(const Segm & segm) = default;

    bool operator==(Segm & segm) const;
    bool operator!=(Segm & segm) const;

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getXLength() const {
        return length_x;
    }

    float getYLength() const {
        return length_y;
    }

};


#endif //LABS_SEGM_H
