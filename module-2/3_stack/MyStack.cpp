#include "MyStack.h"

template <class T>
Stack<T>::Stack() {
  head = nullptr;
}

template <class T>
Stack<T>::~Stack() {
  while (!isEmpty()) pop();
}

template <class T>
void Stack<T>::push(T data) {
  ListNode<T> *tmp = new ListNode<T>();

  tmp->next = head;
  tmp->data = data;
  head = tmp;
}

template <class T>
T *Stack<T>::top() {
  return &head->data;
}

template <class T>
void Stack<T>::pop() {
  if (!this->isEmpty()) {
    ListNode<T> *tmp = head;
    head = head->next;
    delete tmp;
  }
}

template <class T>
bool Stack<T>::isEmpty() {
  return head == nullptr;
}

template <class T>
void Stack<T>::reverse() {
  T arr[100];
  int i = 0;
  while (!isEmpty()) {
    arr[i] = *top();
    pop();
    i++;
  }
  for (int j = 0; j < i; j++) {
    push(arr[j]);
  }
}

template <class T>
int Stack<T>::size() {
  int i;
  ListNode<T> *current = head;

  for (i = 0; current; i++) current = current->next;

  return i;
}

template <class T>
void multipliers(int n, Stack<T> &stack) {
  T div = 2;
  while (n > 1) {
    while (n % div == 0) {
      stack.push(div);
      n = n / div;
    }
    div++;
  }
}