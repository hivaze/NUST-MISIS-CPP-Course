// Copyright 2018 by Polevoy Dmitry under Free Public License 1.0.0

#ifndef MATRIXA_MATRIXA_H_20191025
#define MATRIXA_MATRIXA_H_20191025

#include <cstddef>
#include <memory>

class MatrixA {

public:

  MatrixA() = default;
  MatrixA(const MatrixA&);
  MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);

  ~MatrixA() = default;

  std::ptrdiff_t row_count() const { return n_row_;}
  std::ptrdiff_t col_count() const { return n_col_;}

  float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i);
  const float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const;

  MatrixA& operator=(const MatrixA&);

private:

  std::ptrdiff_t n_row_{0};
  std::ptrdiff_t n_col_{0};
  std::unique_ptr<float[]> data_;

};

#endif
