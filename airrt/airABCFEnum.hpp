#ifndef __AIRABCFENUM_INC__
#define __AIRABCFENUM_INC__

// 字节码文件相关枚举值
namespace airrt::abc::Enum
{
    // 文件头相关枚举值
    struct FileHeader
    {
        enum : unsigned int
        {
            // 文件标识
            magic = '#' | 'A' << 8 | 'I' << 16 | 'R' << 24,

            endian_big = 0xAA,    // 大端字节序
            endian_little = 0x55, // 小端字节序

            arch_bit32 = 0x32, // 32位地址架构
            arch_bit64 = 0x64, // 64位地址架构

            kind_dynamic = 0x01,    // 动态库
            kind_executable = 0x02, // 可执行文件
            kind_library = 0x03,    // 共享库
            kind_object = 0x04,     // 对象文件

            format_v1 = 0x00000001, // 字节码文件格式

            instruct_v1 = 0x00000001, // 指令版本
        };
    };

    // 段节表枚举相关枚举值
    struct SegmentTable
    {
        enum : unsigned int
        {
            unknown = 0, // 未知

            // 字符串表节
            string_table = 1,   // 字符串表
            string_section = 2, // 字符串节

            // ANI表节
            ani_table = 3,   // ANI表
            ani_section = 4, // ANI节

            // 动态库表节
            dynamic_table = 5,   // 动态库表
            dynamic_section = 6, // 动态库节

            // 类型表节
            type_table = 7,   // 类型表
            type_section = 8, // 类型节

            // 成员字段表节
            field_table = 9,    // 字段表
            field_section = 10, // 字段节

            // 签名表节
            signature_table = 11,   // 签名表
            signature_section = 12, // 签名节

            // 函数表节
            function_table = 13,   // 函数表
            function_section = 14, // 函数节

            // 变量表节
            variable_table = 15,   // 变量表
            variable_section = 16, // 变量节

            // 重定位表节
            relocation_table = 17,   // 重定位表
            relocation_section = 18, // 重定位节

            // 调用点表节
            callsite_table = 19,   // 调用点表
            callsite_section = 20, // 调用点节

        };
    };

    // 类型表相关枚举值
    struct TypeTable
    {
        enum : unsigned int
        {
            unknown = 0, // 未知

            // 函数数据已初始化
            initialized = 1 << 0,
            // 基本类型
            base_type = 1 << 1,
            // 枚举类型
            enum_type = 1 << 2,
            // 结构体类型
            struct_type = 1 << 3,
            // 联合体类型
            union_type = 1 << 4,
            // 类类型
            class_type = 1 << 5,
            // 接口类型
            interface_type = 1 << 6,
            // 静态函数委托类型
            static_delegate_type = 1 << 7,
            // 成员函数委托类型
            dynamic_delegate_type = 1 << 8,

            //未实现接口
            unimplemented_interface = 1 << 9,
            //未继承父类
            unimplemented_parent = 1 << 10,
           
        };
    };


    //签名表相关枚举值
    struct SignatureTable
    {
        enum : unsigned int
        {
            unknown = 0, // 未知

            // 签名数据已初始化
            initialized = 1 << 0,

            // 无返回值
            noreturn = 1 << 1,
            // 成员函数
            method  = 1 << 2,
        };
    };
   
    // 函数表相关枚举值
    struct FunctionTable
    {
        enum : unsigned int
        {
            unknown = 0, // 未知

            // 函数数据已初始化
            initialized = 1 << 0,

            // 成员函数
            member_function = 1 << 1,
            // 静态函数
            static_function = 1 << 2,
            // 虚函数
            virtual_function = 1 << 3,

            // 构造函数
            constructor = 1 << 4,
            // 析构函数
            destructor = 1 << 5,

            // 公共的函数
            public_function = 1 << 6,

            // 受保护的函数
            protected_function = 1 << 7,
            // 私有的函数
            private_function = 1 << 8,

            // 函数没有背景数据
            no_data = 1 << 30,
            // 函数背景数据已加载
            data_loaded = 1u << 31,
        };
    };

    //重定位表相关枚举值
    struct RelocationTable{
        enum : unsigned int
        {
            unknown = 0, // 未知

            //标识重定位项类别
            
        };
    };
    
    
}
#endif // __AIRABCFENUM_INC__