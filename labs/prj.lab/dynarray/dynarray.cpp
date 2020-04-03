#include "dynarray.h"
#include <iostream>

#include  <algorithm>
#include  <stdexcept>


DynArray::DynArray(const DynArray& arr) : capacity_(arr.size_), size_(arr.size_), data_(new float[capacity_]{0.0f}) {
    std::copy(arr.data_, arr.data_ + arr.size_, data_);
}

DynArray::DynArray(const std::ptrdiff_t size) : capacity_(size), size_(size) {
    if (capacity_ < 0) {
        throw std::logic_error("DynArray ctor - negative size");
    }
    data_ = new float[capacity_]{0.0f};
}

DynArray & DynArray::operator=(const DynArray& rhs) {
    if (this != &rhs) {
        if (capacity_ < rhs.size_) {
            capacity_ = rhs.size_;
            delete[] data_;
            data_ = new float[capacity_];;
        }
        size_ = rhs.size_;
        std::copy(rhs.data_, rhs.data_ + size_, data_);
    }
    return *this;
}


float & DynArray::operator[](const std::ptrdiff_t i) {
    if (i < 0 || size_ <= i) {
        throw std::out_of_range("DynArray::operator[] index out of range");
    }
    return data_[i];
}

const float & DynArray::operator[](const std::ptrdiff_t i) const {
    if (i < 0 || size_ <= i) {
        throw std::out_of_range("DynArray::operator[] index out of range");
    }
    return data_[i];
}

void DynArray::resize(const std::ptrdiff_t newSize) {
    if (newSize < 0) {
        throw std::logic_error("DynArray::resize - negative size");
    }
    if (capacity_ < newSize) {
        capacity_ = newSize;
        float* new_data = new float[capacity_];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        data_ = new_data;
    }
    if (size_ < newSize) {
        std::fill(data_ + size_, data_ + newSize, 0.0f);
    }
    size_ = newSize;
}