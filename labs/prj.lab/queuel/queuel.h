//
// Created by Сергей Братчиков on 20/12/2019.
//

#ifndef LABS_QUEUEL_H
#define LABS_QUEUEL_H


#include <limits>

class QueueL {

public:

    QueueL() = default;
    QueueL(const QueueL& obj);

    ~QueueL();

    void push(const float value);
    void pop();
    float& top();

    bool is_empty() const { return head_ == nullptr; };

    QueueL& operator=(const QueueL& obj);

private:

    struct Node{
        float value_{ std::numeric_limits<float>::epsilon() };
        Node* next_{ nullptr };
    };

    Node* head_{ nullptr };
    Node* tail_{ nullptr };

};


#endif //LABS_QUEUEL_H
