#include "init/init.h"
#include <iostream> // why here need include?
namespace test {
// 测试初始化函数
void init_function_1() {
    std::cout << "Initialization function 1 called!" << std::endl;
}
REGISTER_FUNC(init_function_1);

void func4() {
    std::cout << "func4" << std::endl;
}
REGISTER_FUNC(func4);

void tmpfun(){}
}
