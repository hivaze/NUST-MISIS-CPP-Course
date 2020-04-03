//
// Created by Сергей Братчиков on 14/12/2019.
//

#ifndef LABS_STACKA_H
#define LABS_STACKA_H


#include <cstddef>

class StackA {

public:

    StackA() = default;
    StackA(const StackA &arr);

    ~StackA() { delete[] data_; data_ = nullptr; }

    void push(const float val);
    void pop();
    float& top();

    bool is_empty() const { return head_ == -1; }

    StackA& operator=(const StackA &arr);

private:

    ptrdiff_t head_{ -1 };
    ptrdiff_t capacity_{ 0 };
    float* data_{ nullptr };

};

#endif //LABS_STACKA_H
