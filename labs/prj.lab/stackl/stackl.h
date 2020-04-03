//
// Created by Сергей Братчиков on 14/12/2019.
//

#ifndef LABS_STACKL_H
#define LABS_STACKL_H


class StackL {

public:

    StackL() = default;
    StackL(const StackL &arr);

    ~StackL();

    void push(const float val);
    void pop();
    float& top();
    const float& top() const;

    bool is_empty() const { return head_ == nullptr; }

    StackL& operator=(const StackL &arr);

private:

    struct Node {
        Node* next_{ nullptr };
        float data_{ 0.0f };
    };

    Node* head_{ nullptr };

};

#endif //LABS_STACKL_H