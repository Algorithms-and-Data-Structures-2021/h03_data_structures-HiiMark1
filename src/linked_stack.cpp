#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

    void LinkedStack::Push(Element e) {
        SinglyNode *node = new SinglyNode(e, top_);
        size_++;
        top_ = node;
    }

    void LinkedStack::Pop() {
        if (top_ == nullptr) {
            throw std::logic_error("cannot pop out from empty stack");
        }
        if (size_ == 1) {
            delete top_;
            top_ = nullptr;
        } else {
            SinglyNode *node = top_->next;
            delete top_;
            top_ = node;
        }
        size_--;
    }

    void LinkedStack::Clear() {
        for (SinglyNode *current_node = top_; current_node != nullptr;) {
            auto delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
        top_ = nullptr;
        size_ = 0;
    }

// === РЕАЛИЗОВАНО ===

    LinkedStack::~LinkedStack() {
        Clear();
    }

    std::optional<Element> LinkedStack::Peek() const {
        return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
    }

    bool LinkedStack::IsEmpty() const {
        return size_ == 0;
    }

    int LinkedStack::size() const {
        return size_;
    }

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

    std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
        os << "size: " << stack.size_ << '\n';
        for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
            if (current_node == stack.top_) os << "[TOP] ";
            os << enum2str(current_node->data) << '\n';
        }
        return os;
    }

}  // namespace itis