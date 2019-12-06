// Copyright 2019 CERZAR

#pragma once
#include <utility>

template <typename T>
struct Node_for_NoCopy
{
    T value;
    Node_for_NoCopy<T>* prev;
};

template <typename T>
class Stack_for_NoCopy
{
private:
    Node_for_NoCopy<T>* top = nullptr;
public:
    Stack_for_NoCopy()= default;
    Stack_for_NoCopy(const Stack_for_NoCopy &Stack_for_NoCopy)= delete; // no copy
    Stack_for_NoCopy(Stack_for_NoCopy&& Stack_for_NoCopy)= default; // constructable move
    auto operator=(Stack_for_NoCopy&& Stack_for_NoCopy) noexcept ->class Stack_for_NoCopy& = default; // assignable move
    template <typename ... Args>
    void push_emplace(Args&& ... value);
    void push(T&& value);
    const T& head() const;
    T pop();
};

template<typename T>
template<typename ...Args>
inline void Stack_for_NoCopy<T>::push_emplace(Args && ... value)
{
    auto* current = top;
    top = new Node_for_NoCopy<T>{{std::forward<Args>(value)...}, current};
}

template<typename T>
inline void Stack_for_NoCopy<T>::push(T && value)
{
    auto* current = top;
    top = new Node_for_NoCopy<T>{std::forward<T>(value), current};
}

template<typename T>
const T & Stack_for_NoCopy<T>::head() const
{
    return top->value;
}

template<typename T>
T Stack_for_NoCopy<T>::pop()
{
    T value = top->value;
    top = top->prev;

    return value;
}