// Copyright 2019 CERZAR

#pragma once
#include <exception>

template <typename T>
struct Node
{
    T value;
    Node<T>* prev;
};

template <typename T>
class Stack
{
private:
    Node<T>* top = nullptr;
public:
    Stack()= default;
    Stack(const Stack &stack)= delete; // no copy
    Stack(Stack&& stack)= default; // constructable
    auto operator=(Stack&& stack) noexcept ->class Stack& = default; // assignable
    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;
};

template<typename T>
void Stack<T>::push(T && value)
{
    if (!top)
    {
        top = new Node<T>;
        top->value = value;
        top->prev = nullptr;
    }else
    {
        auto *curruent = new Node<T>;
        curruent->value = top->value;
        curruent->prev = top->prev;
        top->value = value;
        top->prev = curruent;
    }
}

template<typename T>
void Stack<T>::push(const T & value)
{
    if (!top)
    {
        top = new Node<T>;
        top->value = value;
        top->prev = nullptr;
    }else
    {
        auto *curruent = new Node<T>;
        curruent->value = top->value;
        curruent->prev = top->prev;
        top->value = value;
        top->prev = curruent;
    }
}

template<typename T>
void Stack<T>::pop()
{
    if (top)
        top = top->prev;
    else
        throw std::exception();
}

template<typename T>
const T & Stack<T>::head() const
{
    return top->value;
}