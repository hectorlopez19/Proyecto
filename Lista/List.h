#pragma once
#include <iostream>

template <typename T>
class Node {
  private:
    int index;
    T value;
    Node* next;
    Node* prev;
  
  public:
    Node(const T& newValue) {
      index = 0;
      value = newValue;
      next = nullptr;
      prev = nullptr;
    }

    void push(const T& newValue) {
      if(next == nullptr) {
        next = new Node<T>(newValue);
        next->index = index + 1;
        next->prev = this;
      }
      else {
        next->push(newValue);
      }
    }

    void pop() {
      if(next == nullptr) {
        prev->next = nullptr;
        delete this;
      }
      else {
        next->pop();
      }
    }

    void increaseIndex() {
      index++;
      if(next != nullptr) {
        next->increaseIndex();
      }
    }

    void insert(int inIndex, const T& newValue) {
      if(inIndex >= 0) {
        if(inIndex == index) {
          Node* newNode = new Node<T>(newValue);
          newNode->index = index;
          prev->next = newNode;
          newNode->prev = prev;
          prev = newNode;
          newNode->next = this;
          increaseIndex();
        }
        else if(next != nullptr) {
          next->insert(inIndex, newValue);
        }
      }
    }

    void decraseIndex() {
      index--;
      if(next != nullptr) {
        next->decraseIndex();
      }
    }

    void delIndex(int inIndex) {
      if(inIndex >= 0) {
        if(index == inIndex) {
          if(prev != nullptr) {
            prev->next = next;
          }
          if(next != nullptr) {
            next->prev = prev;
            next->decraseIndex();
          }
          delete this;
        }
        else if(next != nullptr) {
          next->delIndex(inIndex);
        }
      }
    }

    void del(const T& delValue) {
      if(value == delValue) {
        if(prev != nullptr) {
          prev->next = next;
        }
        if(next != nullptr) {
          next->prev = prev;
          next->decraseIndex();
        }
        delete this;
      }
      else if(next != nullptr) {
        next->del(delValue);
      }
    }

    void showList() {
      if(index == 0) {
        std::cout << "[";
      }
      if(next != nullptr) {
        std::cout << value << ", ";
        next->showList();
      }
      else {
        std::cout << value << "]\n";
      }
    }

};