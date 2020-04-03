#include <stdexcept>
#include "queuel.h"

QueueL::QueueL(const QueueL& obj) {
    Node* objHead(obj.head_);
    while (objHead != nullptr) {
        push(objHead->value_);
        objHead = objHead->next_;
    }
}

QueueL::~QueueL() {
    while (!is_empty()) {
        pop();
    }
}

float& QueueL::top() {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    } else {
        return head_->value_;
    }
}

void QueueL::pop() {
    if (!is_empty()) {
        Node* nextHead(head_->next_);
        delete head_;
        head_ = nextHead;
        if (is_empty()) {
            tail_ = nullptr;
        }
    }
}

void QueueL::push(const float val) {
    Node* newTail = new Node{ val, nullptr };
    if (this->is_empty()) {
        head_ = newTail;
        tail_ = newTail;
    } else {
        tail_->next_ = newTail;
        tail_ = newTail;
    }
}

QueueL& QueueL::operator=(const QueueL& obj) {
    if (this != &obj) {
        while (!this->is_empty()) {
            this->pop();
        }
        Node* objHead(obj.head_);
        while (objHead != nullptr) {
            this->push(objHead->value_);
            objHead = objHead->next_;
        }
    }
    return *this;
}
