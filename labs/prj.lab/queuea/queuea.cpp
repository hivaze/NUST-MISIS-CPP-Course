//
// Created by Сергей Братчиков on 14/12/2019.
//

#include <stdexcept>
#include "queuea.h"

QueueA::QueueA(const QueueA &arr) {
    last_ = arr.last_;
    first_ = arr.first_;
    capacity_ = arr.capacity_;
    data_ = new float[capacity_];
    for (ptrdiff_t i = first_; i <= last_; i++) {
        data_[i % capacity_] = arr.data_[i % capacity_];
    }
}

void QueueA::push(const float val) {
    if (last_ - first_ + 1 >= capacity_) {
        ptrdiff_t capacity = capacity_ * 2;
        if (capacity == 0) {
            capacity++;
        }
        float *data = new float[capacity];
        for (ptrdiff_t i = first_; i <= last_; i++) {
            data[i - first_] = data_[i % capacity_];
        }
        std::swap(data, data_);
        std::swap(capacity, capacity_);
        last_ -= first_;
        first_ = 0;
    }
    last_++;
    data_[last_ % capacity_] = val;
}

float& QueueA::top() {
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    return data_[first_ % capacity_];
}

void QueueA::pop() {
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    first_++;
}

QueueA& QueueA::operator=(const QueueA &arr) {
    if (&arr == this) {
        return *this;
    }
    QueueA temp(arr);
    std::swap(temp.capacity_, capacity_);
    std::swap(temp.data_, data_);
    std::swap(temp.first_, first_);
    std::swap(temp.last_, last_);
    return (*this);
}