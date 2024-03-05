#include "airInterface.hpp"

namespace airrt
{
    //运行时环境上下文
    struct EvnContext:IContext
    {
        //初始化环境
        bool init();

        //加载文件模块
        bool loadModule(const char* path);

        //释放文件模块
        void releaseModule(const char* path);

        //分析文件模块
    };
}