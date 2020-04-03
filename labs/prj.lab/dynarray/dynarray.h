// Copyright 2018 by Polevoy Dmitry under Free Public License 1.0.0

#ifndef DYNARRAY_DYNARRAY_H_112019
#define DYNARRAY_DYNARRAY_H_112019

#include <cstddef>
#include <cstddef>

class DynArray {

public:

    DynArray() = default;
    DynArray(const DynArray& arr);
    DynArray(const std::ptrdiff_t size);

    ~DynArray() { delete[] data_; }

    DynArray& operator=(const DynArray& rhs);
    std::ptrdiff_t size() const { return size_; }
    float& operator[](const std::ptrdiff_t i);
    const float& operator[](const std::ptrdiff_t i) const;
    void resize(const std::ptrdiff_t newSize);

private:

    std::ptrdiff_t capacity_{0};  //!< размер внутреннего буфера
    std::ptrdiff_t size_{0};      //!< размер массива (кол-во элементов)
    float* data_{nullptr};        //!< данные

};

#endif