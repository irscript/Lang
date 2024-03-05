#include "airInterface.hpp"

namespace airrt
{
    // 字节码文件管理
    struct FileManager
    {
        FileManager();
        ~FileManager();

        // 加载文件
        abc::BCFile *load(const char *path);
        // 释放文件
        void release(abc::BCFile *file);

    private:
        uint32_t file;       // 文件最大数量:缓存数量
        uint32_t count;      // 文件真实数量:实际数量
        abc::BCFile **files; // 文件数组
        abc::String *main;   // 主文件名称
    };

    // 内存管理
    struct MemoryManager
    {
        MemoryManager();
        ~MemoryManager();

        // 释放内存
        void release(void *ptr);

    private:
        uint32_t count; // 内存数量
        void **mems;    // 内存数组
    };
    // 运行时环境上下文
    struct EvnContext : IContext
    {
        EvnContext();
        virtual ~EvnContext();
        // 初始化环境
        bool init();
        // 获取执行器
        virtual IExecutor *newExecutor() override;
        // 释放执行器
        virtual void releaseExecutor(IExecutor *executor) override;

    private:
    private:
        FileManager mFileManager;  // 文件管理
        MemoryManager mMemManager; // 内存管理
    };

    // 执行器
    struct Executor : IExecutor
    {
        Executor(EvnContext &context);
        virtual ~Executor();

        /**
         * 设置函数入口
         * @param func 指向要设置入口的函数的指针。
         * @param argc 参数数量。
         * @param argv 参数值数据的指针。
         * @param retv 返回值的地址。
         * @return 成功返回true，失败返回false。
         */
        virtual bool setEntry(abc::FunctionHD *func, uint32_t argc, uint32_t *argv, void *retv) override;
        // 执行函数
        virtual uintptr_t exec() override;

    private:
        /**
         * 构建函数栈
         * @param func 指向abc::FunctionHD类型的指针，表示待构建栈的功能描述。
         *             FunctionHD是一个高级函数描述结构，包含了函数的各种信息，
         *             如函数名、参数列表、返回类型等。
         * @note 本函数不返回任何值，但会根据func参数描述的内容，构建并初始化一个栈。
         */
        void buildStack(abc::FunctionHD *func);

    private:
        EvnContext &mContext;

        // 运行时栈
        struct FuncStack
        {
            FuncStack *mPrev;       // 上一个函数栈
            abc::FunctionHD *mFunc; // 执行的当前函数数据
            uintptr_t mRet;         // 返回值的存储地址
            uint32_t mIP;           // IP 寄存器
            uint32_t mReg[];        // 当前函数需要的寄存器
        };
        FuncStack *mStack; // 当前栈
    };

}