// Copyright 2019 CERZAR

#include <gtest/gtest.h>
#include "../include/Stack.h"
#include "../include/Stack_for_NoCopy.h"
#include <exception>
class Class
{
public:
    int x;
    int y;

    Class()
    {
        x = 0;
        y = 0;
    }
    Class(int x1, int y1)
    {
        this->x = x1;
        this->y = y1;
    }
    Class(const Class& v)
    {
        this->x = v.x;
        this->y = v.y;
    }
};

TEST(Stack_Test,All_Tests)
{
    int a=5,b=8;
    Stack<int> stack;
    stack.push(a);
    stack.push(b);

    EXPECT_EQ(stack.head(),b);
    stack.pop();
    EXPECT_EQ(stack.head(),a);
    stack.pop();

    EXPECT_THROW(stack.pop(), std::exception);

    EXPECT_EQ(std::is_move_constructible<Stack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<Stack<int>>::value, true);
    EXPECT_EQ(std::is_copy_constructible<Stack<int>>::value, false);
    EXPECT_EQ(std::is_copy_assignable<Stack<int>>::value, false);
}

TEST(Stack_for_NoCopy_Test, All_Tests)
{
    int x1=2,y1=4;
    int x2=3,y2=7;
    Class pnt(x1,y1);

    Stack_for_NoCopy<Class> stack;
    stack.push(Class(x1,y1));
    stack.push_emplace(x2,y2);

    EXPECT_EQ(stack.head().x,x2);
    stack.pop();
    EXPECT_EQ(stack.head().y,y1);

    EXPECT_EQ(std::is_move_constructible<Stack_for_NoCopy<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<Stack_for_NoCopy<int>>::value, true);
    EXPECT_EQ(std::is_copy_constructible<Stack_for_NoCopy<int>>::value, false);
    EXPECT_EQ(std::is_copy_assignable<Stack_for_NoCopy<int>>::value, false);
}
