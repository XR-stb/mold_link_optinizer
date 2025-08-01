#include <iostream>
#include <string>
#include <vector>
#include <functional>

// 模拟注册回调函数
enum Timing {
    kTimingInitialize,
    kTimingPostInitialize,
};

enum Priority {
    kPriorityLow,
    kPriorityHigh,
};

struct CallbackInfo {
    Timing timing;
    Priority priority;
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

    bool RegCallbackFunc(Timing timing, Priority priority, std::function<void()> func, const std::string& name) {
        callbacks_.push_back({timing, priority, func, name});
        std::cout << "Registered callback: " << name << " (Timing: " << timing << ", Priority: " << priority << ")" << std::endl;
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
    __attribute__((unused)) static inline bool FILE_UNIQUE_VAR = \
        CallbackManager::Instance().RegCallbackFunc(kTimingInitialize, kPriorityHigh, init_func, #init_func)
