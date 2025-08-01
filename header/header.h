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
        // std::cout << "Registered callback: " << name << std::endl; // 下面的REGISTER_FUNC用inline时cout还没初始化这里会coredump
        printf("Registered callback: %s\n", name.c_str());
        return true;
    }

    void ExecuteCallbacks() {
        for (const auto& callback : callbacks_) {
            callback.func();
        }
    }
};

// 这里inline 会被链接时被优化掉
#define REGISTER_FUNC(init_func) \
    __attribute__((unused)) inline bool FILE_UNIQUE_VAR = \
        CallbackManager::Instance().RegCallbackFunc(init_func, #init_func)

#define REGISTER_FUNC_STATIC(init_func) \
    __attribute__((unused)) static bool FILE_UNIQUE_VAR = \
        CallbackManager::Instance().RegCallbackFunc(init_func, #init_func)
