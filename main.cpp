#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "header/header.h"
// #include "init.h"

// 宏定义：用于生成唯一的变量名
#define CONTACT3(x, y) x##y
#define CONTACT2(x, y) CONTACT3(x, y)
#define CONTACT1(x, y) CONTACT2(x, y)
#define CONTACT(x, y) CONTACT1(x, y)
#define FILE_UNIQUE_VAR CONTACT(_variant_, __LINE__)

int main() {
    std::cout << "Main function started!" << std::endl;
    // 执行所有回调函数
    CallbackManager::Instance().ExecuteCallbacks();
    return 0;
}
