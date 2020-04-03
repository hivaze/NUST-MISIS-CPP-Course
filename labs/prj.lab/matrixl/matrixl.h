//
// Created by Сергей Братчиков on 20/12/2019.
//

#ifndef LABS_MATRIXL_H
#define LABS_MATRIXL_H


#include <cstddef>
#include <memory>

class MatrixL {

public:

    MatrixL() = default;
    MatrixL(const MatrixL& mtrx);
    MatrixL(const std::ptrdiff_t col_, const std::ptrdiff_t row);

    ~MatrixL();

    std::ptrdiff_t col_count() const;
    std::ptrdiff_t row_count() const;

    float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i);
    const float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const;

    MatrixL& operator=(const MatrixL& rhs);

private:

    float* data_{ nullptr };
    float** dataptr_{ nullptr };
    std::ptrdiff_t col_{ 0 };
    std::ptrdiff_t row_{ 0 };

};

#endif //LABS_MATRIXL_H
