#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

using foo = void(int); // 定义函数类型, using 的使用见上一节中的别名语法
void functional(foo f) { // 参数列表中定义的函数类型 foo 被视为退化后的函数指针类型 foo*
    f(1); // 通过函数指针调用函数
}


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        auto f = [](int value) {
            std::cout << value << std::endl;
        };
        functional(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
        f(1); // lambda 表达式调用
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}