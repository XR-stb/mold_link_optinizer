#include "header/header.h"

namespace test {
void init_function_b() {
    std::cout << "init_function_b called!" << std::endl;
}
REGISTER_FUNC(init_function_b);// 如何用的是inline的注册宏，这里是同一个行号就不会注册进去
}
