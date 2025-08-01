#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "header/header.h"

int main() {
    std::cout << "Main function started!" << std::endl;
    // 执行所有回调函数
    CallbackManager::Instance().ExecuteCallbacks();
    return 0;
}
