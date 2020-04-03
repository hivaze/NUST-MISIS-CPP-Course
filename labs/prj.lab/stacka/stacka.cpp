//
// Created by Сергей Братчиков on 14/12/2019.
//

#include <stdexcept>
#include "stacka.h"

StackA::StackA(const StackA &arr) {
    capacity_ = arr.capacity_;
    head_ = arr.head_;
    data_ = new float[capacity_];
    for (int i = 0; i <= arr.head_; i++) {
        data_[i] = arr.data_[i];
    }
}

void StackA::push(const float val) {
    if (capacity_ <= head_ + 1) {
        if (capacity_ == 0) {
            capacity_ = 1;
        }
        else {
            capacity_ = capacity_ * 2;
        }
        float *data = new float[capacity_];
        for (int i = 0; i <= head_; i++) {
            data[i] = data_[i];
        }
        data_ = data;
    }
    head_++;
    data_[head_] = val;
}

float& StackA::top() {
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    return data_[head_];
}

void StackA::pop() {
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    head_--;
}

StackA& StackA::operator=(const StackA &arr) {
    if (&arr == this) { return *this; }
    StackA temp(arr);
    std::swap(temp.data_, data_);
    std::swap(temp.head_, head_);
    std::swap(temp.capacity_, capacity_);
    return (*this);
}
