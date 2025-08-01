#pragma once

#include "header/header.h"

namespace test {
// 测试初始化函数
void init_function_1() {
    std::cout << "Initialization function 1 called!" << std::endl;
}
REGISTER_FUNC(init_function_1);

void init_function_2() {
    std::cout << "Initialization function 2 called!" << std::endl;
}
REGISTER_FUNC(init_function_2);

void func3() {
    std::cout << "func3" << std::endl;
}
REGISTER_FUNC(func3);
}