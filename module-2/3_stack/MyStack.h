#pragma once

template <class T>
struct ListNode  // односвязный список
{
  T data;             // выводит значение элемента
  ListNode<T> *next;  // указатель на следующий элемент
};

template <class T>
class Stack {
  ListNode<T> *head;  // указатель на вершину

 public:
  Stack();
  ~Stack();

  Stack(const Stack<T> &copy)  // конструктор копирования
  {
    while (!this->isEmpty()) {
      this->pop();
    }

    ListNode<T> *temp1 = new ListNode<T>;
    temp1 = copy.head;
    Stack<T> stack1;

    while (temp1 != nullptr) {
      stack1.push(temp1->data);
      temp1 = temp1->next;
    }

    temp1 = stack1.head;

    while (temp1 != nullptr) {
      this->push(temp1->data);
      temp1 = temp1->next;
    }
    delete temp1;
  }

  void push(T);    // добавить элемент в начало
  void pop();      // удалить элемент вначале
  T *top();        // значение верхнего элемента
  bool isEmpty();  // пуст ли стек
  void reverse();  // элементы в обратном порядке
  int size();      // размер стека
};

template <class T>
void multipliers(int n, Stack<T> &stack);