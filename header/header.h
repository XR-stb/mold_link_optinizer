#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "marco/marco.h"

struct CallbackInfo {
    std::function<void()> func;
    std::string name;
};

// 单例基类
class Singleton {
protected:
    Singleton() = default;
    ~Singleton() = default;
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// 回调管理单例类
class CallbackManager : public Singleton {
private:
    std::vector<CallbackInfo> callbacks_;
    CallbackManager() = default;
    ~CallbackManager() = default;

public:
    static CallbackManager& Instance() {
        static CallbackManager instance;
        return instance;
    }

    bool RegCallbackFunc(std::function<void()> func, const std::string& name) {
        callbacks_.push_back({func, name});
        std::cout << "Registered callback: " << name << std::endl;
        return true;
    }

    void ExecuteCallbacks() {
        for (const auto& callback : callbacks_) {
            callback.func();
        }
    }
};

// 宏定义：用于注册初始化函数
#define REGISTER_FUNC(init_func) \
    __attribute__((unused)) static bool FILE_UNIQUE_VAR = \
        CallbackManager::Instance().RegCallbackFunc(init_func, #init_func)
