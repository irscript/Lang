--虚拟机
target("airvm")
    set_kind("binary")
    add_deps("airrt")
    add_files("Main.cpp")