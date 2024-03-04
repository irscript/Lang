
--设置语言标准
set_languages("c++17","c99")

-- 设置构建模式
add_rules("mode.release", "mode.debug")

-- 添加头文件目录
add_includedirs(".")
-- 添加子项目
includes("airc",    -- 编译器
         "airvm",   -- 虚拟机
         "airrt",   -- 运行时
         "abctest"  -- 字节码文件测试构建
         )