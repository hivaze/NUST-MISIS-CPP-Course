//
// Created by Сергей Братчиков on 14/12/2019.
//

#ifndef LABS_QUEUEA_H
#define LABS_QUEUEA_H

class QueueA {

public:

    QueueA() = default;
    QueueA(const QueueA &arr);

    ~QueueA() { delete[] data_; }

    void push(const float val);
    void pop();
    float& top();

    bool is_empty() const { return last_ < first_; }

    QueueA& operator=(const QueueA &arr);

private:

    ptrdiff_t last_{ -1 };
    ptrdiff_t first_{ 0 };
    ptrdiff_t capacity_{ 0 };
    float* data_{ nullptr };

};


#endif //LABS_QUEUEA_H
