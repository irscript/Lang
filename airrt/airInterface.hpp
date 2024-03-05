#ifndef __AIRINTERFACE_INC__
#define __AIRINTERFACE_INC__

#include "airABCF.hpp"
namespace airrt
{

    // 运行的函数
    struct IExecutor
    {
        virtual ~IExecutor() = default;
        // 设置运行参数
        virtual bool setEntry(abc::FunctionHD *func, uint32_t argc, uint32_t *argv,void* ret) = 0;
        // 执行
        virtual uintptr_t exec() = 0;
    };
    // 运行时上下文接口
    struct IContext
    {
        virtual ~IContext() = default;

        // 获取函数
      //  virtual abc::FunctionHD *getFunc(abc::String &name) = 0;

        // 获取执行器
        virtual IExecutor *newExecutor() = 0;
        // 释放执行器
        virtual void releaseExecutor(IExecutor *executor) = 0;
    };

}

#endif // __AIRINTERFACE_INC__