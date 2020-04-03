#include <matrixa/matrixa.h>

using namespace std;

MatrixA::MatrixA(const ptrdiff_t col, const ptrdiff_t row) {
    if (row <= 0 || col <= 0) {
        throw invalid_argument("Not Matrix!");
    }
    n_row_ = row;
    n_col_ = col;
    data_ = make_unique<float[]>(n_row_ * n_col_);
    for (ptrdiff_t i = 0; i < n_row_; i++) {
        for (ptrdiff_t j = 0; j < n_col_; j++) {
            data_[i * n_col_ + j] = 0;
        }
    }
}

MatrixA::MatrixA(const MatrixA &mat) {
    n_row_ = mat.n_row_;
    n_col_ = mat.n_col_;
    data_ = make_unique<float[]>(n_row_ * n_col_);
    for (ptrdiff_t i = 0; i < n_row_; i++) {
        for (ptrdiff_t j = 0; j < n_col_; j++)
            data_[i * n_col_ + j] = mat.data_[i * n_col_ + j];
    }
}


MatrixA& MatrixA::operator=(const MatrixA& mat) {
    if (&mat == this) {
        return *this;
    }
    n_col_ = mat.n_col_;
    n_row_ = mat.n_row_;
    data_.reset(mat.data_.get());
    return *this;
}

float& MatrixA::at(const ptrdiff_t i, const ptrdiff_t j) {
    if (i >= n_row_ || i < 0 || j >= n_col_ || j < 0) {
        throw out_of_range("Out of range!");
    }
    return data_[i * n_col_ + j];
}

const float& MatrixA::at(const ptrdiff_t i, const ptrdiff_t j) const {
    if (i >= n_row_ || i < 0 || j >= n_col_ || j < 0) {
        throw out_of_range("Out of range!");
    }
    return data_[i * n_col_  +j];
}