#include "header/header.h"

namespace test {
void init_function_a() {
    std::cout << "init_function_a called!" << std::endl;
}

REGISTER_FUNC(init_function_a);
}
