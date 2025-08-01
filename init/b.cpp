#include "header/header.h"

namespace test {
void init_function_b() {
    std::cout << "init_function_b called!" << std::endl;
}
REGISTER_FUNC(init_function_b);
}
