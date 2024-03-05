#include <iostream>
#include "airrt/airContext.hpp"
int main(int argc, const char *argv[])
{

    airrt::EvnContext context; // 创建上下文
    context.init();

    auto executor = context.newExecutor();   // 创建执行器
    executor->setEntry(nullptr, 0, nullptr); // 设置入口
    executor->exec();

    context.releaseExecutor(executor); // 释放执行器
    return 0;
}
