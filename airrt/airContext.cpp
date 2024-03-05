#include "airContext.hpp"

namespace airrt
{
    EvnContext::EvnContext()
    {
    }

    EvnContext::~EvnContext()
    {
    }

    bool EvnContext::init()
    {
    }

    IExecutor *EvnContext::newExecutor()
    {
        return nullptr;
    }

    void EvnContext::releaseExecutor(IExecutor *executor)
    {
    }

    Executor::Executor(EvnContext &context)
        : mContext(context), mStack(nullptr)
    {
    }

    Executor::~Executor()
    {
    }

    void Executor::buildStack(abc::FunctionHD *func)
    {
    }

    bool Executor::setEntry(abc::FunctionHD *func, uint32_t argc, uint32_t *argv, void *retv)
    {
        // 验证参数
        if (func == nullptr || argc != func->mArgs ||
            (argc != 0 && argv == nullptr))
            return false;
        // 分配栈
        buildStack(func);
        // 传递参数
        if (argc != 0)
        {
            // 计算参数填充地址
            uint32_t argshift = func->mRegs - func->mArgs;
            uint32_t *des = &mStack->mReg[argshift];
            // 拷贝数据
            memcpy(des, argv, argc * sizeof(uint32_t));
        }
        // 设置返回值地址
        mStack->mRet = (uintptr_t)retv;
        return true;
    }

    uintptr_t Executor::exec()
    {
        return 0;
    }
}