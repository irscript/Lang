--字节码文件测试构建

target("abctest")
    set_kind("binary")
    add_includedirs("../airrt")
    --add_deps("airrt")
    add_files("Main.cpp")