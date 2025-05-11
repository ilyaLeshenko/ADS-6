// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;

public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        if (!head || value.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            if (!tail) tail = head;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data.prior >= value.prior) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next) {
            tail = newNode;
        }
    }
    T pop() {
        if (!head) {
            throw "Queue is empty!";
        }        
        Node* temp = head;
        T result = temp->data;
        head = head->next;        
        if (!head) {
            tail = nullptr;
        }        
        delete temp;
        return result;
    }
    bool isEmpty() const {
        return head == nullptr;
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
