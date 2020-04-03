//
// Created by Сергей Братчиков on 14/12/2019.
//

#include <stdexcept>
#include "stackl.h"

StackL::StackL(const StackL &arr) {
    head_ = nullptr;
    if (arr.is_empty()) { return; }
    head_ = new Node{ nullptr, arr.head_->data_ };
    Node *data = arr.head_;
    Node *current = head_;
    while (data->next_ != nullptr) {
        data = data->next_;
        current->next_ = new Node{ data->next_, data->data_ };
        if (current->next_ != nullptr) {
            current = current->next_;
        }
    }
}

StackL::~StackL() {
    while (!is_empty()) pop();
}

void StackL::push(const float val) {
    head_ = new Node{ head_, val };
}

float& StackL::top() {
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    return head_->data_;
}

const float& StackL::top() const{
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    return head_->data_;
}

void StackL::pop() {
    if (is_empty()) {
        throw std::runtime_error("empty!");
    }
    else {
        Node *old = head_;
        head_ = head_->next_;
        delete old;
    }
}

StackL& StackL::operator=(const StackL &arr) {
    if (&arr == this) { return *this; }
    StackL temp(arr);
    Node* tmp = temp.head_;
    head_ = tmp;
    return *this;
}