#ifndef __AIRABCF_INC__
#define __AIRABCF_INC__

// 字节码文件结构定义

#include "Precompiled.hpp"
#include "airABCFEnum.hpp"
namespace airrt::abc
{

    // 只读字符串
    struct String
    {
        union
        {
            uint32_t value; // 用于快速判断字符串是否相等
            struct
            {
                uint16_t size; // 字符串长度值，不包括\0
                uint16_t hash; // 字符串哈希值
            };
        };
        char data[]; // 字符串数据

        /**
         * 比较两个字符串对象
         *
         * 本函数用于比较当前对象与另一个字符串对象的大小关系。首先比较两个字符串的值（value），
         * 如果相等，则进一步逐字符比较。如果两个字符串前缀相同但长度不同，
         * 则较短的字符串被认为小于较长的字符串。如果两个字符串完全相同，
         * 则返回0表示相等。此函数不支持对空字符串的比较。
         *
         * @param str 另一个字符串对象，作为比较的目标。
         * @return 返回一个整数，表示当前字符串对象与参数字符串的比较结果。
         *         - 如果当前对象小于 \p str，则返回-1；
         *         - 如果当前对象等于 \p str，则返回0；
         *         - 如果当前对象大于 \p str，则返回1。
         */
        int32_t compare(const String &str);
    };

    // 文件头
    struct FileHeader
    {
        uint8_t magic[4]; // 文件标识，用于判断文件是否为字节码文件
        uint8_t md5[16];  // 文件的md5值,除本字段后的所有字段参与计算

        uint8_t endian; // 字节序，大端：0xAA，小端：0x55
        uint8_t arch;   // 地址架构，32位地址：32,64位地址：64
        uint16_t kind;  // 文件类型：标识动态库、可执行文件等

        uint32_t format;   // 文件格式版本号
        uint32_t instruct; // 指令版本号

        uint64_t time; // 生成时间

        uint32_t entry; // 入口地址

        uint32_t offset; // 段表偏移，相对于文件起始的偏移量
    };

    // 程序版本作者等信息，在文件中存储使用压缩后的json格式
    struct FileInfo
    {
        const char *name;    // 程序名
        const char *version; // 版本号
        const char *author;  // 作者名
        const char *company; // 公司名
    };

    // 段节表
    struct SegmentTable
    {
        uintptr_t count; // 段数量

        struct
        {
            uintptr_t kind;   // 段类别
            uintptr_t offset; // 段偏移
        } item[];
    };

    // 字符串表
    struct StringTable
    {
        uintptr_t count; // 字符串数量

        const String *item[];
    };

    // ANI函数项
    struct ANIFunc
    {
        union
        {
            uintptr_t name; // 函数名称
            const String *string;
        };

        uintptr_t func; // 函数地址
    };
    // ANI项
    struct ANIItem
    {
        uintptr_t count; // 函数数量
        ANIFunc func[];  // 函数信息
    };
    // ANI表项
    struct ANITableItem
    {
        uintptr_t name;   // 动态库名称
        uintptr_t handle; // 动态库地址

        ANIItem *sub;
    };
    // ANI表
    struct ANITable
    {
        uintptr_t count; // ANI数量

        union
        {
            ANITableItem *items; // ANI表项
            uintptr_t offset;    // ANI表项偏移
        };
    };

    // 动态库表
    struct DynamicTable
    {
        uintptr_t count; // 动态库数量

        struct Item
        {
            uintptr_t name; // 动态库名称
            uintptr_t file; // 动态库文件句柄
        };

        Item items[];
    };

    // 类型信息头
    struct TypeHD
    {
        uint32_t flag; // 类型标志
        uint32_t name; // 类型名
        size_t size;   // 大小
        size_t align;  // 对齐
    };

    // 基本类型
    using BaseType = TypeHD;

    // 枚举类型
    struct EnumType
    {
        TypeHD hd; // 类型信息头

        uint32_t count; // 枚举数量
    };

    // 结构体类型
    struct StructType
    {
        TypeHD hd; // 类型信息头
    };

    // 联合体
    struct UnionType
    {
        TypeHD hd; // 类型信息头
    };

    // 类类型
    struct ClassType
    {
        TypeHD hd; // 类型信息头

        uint32_t count; // 成员数量
    };
    // 接口类型
    struct InterfaceType
    {
        TypeHD hd; // 类型信息头

        uint32_t count; // 成员数量
    };
    // 委托类型
    struct DelegateType
    {
        TypeHD hd; // 类型信息头
    };

    // 类型段表
    struct TypeTable
    {
        uintptr_t count; // 类型数量

        union
        {
            BaseType *basetype;
            EnumType *enumtype;
            StructType *structtype;
            UnionType *uniontype;
            ClassType *classtype;
            InterfaceType *interfacetype;
            DelegateType *delegatetype;
            uintptr_t offset; // 类型表项偏移
        } items[];
    };

    // 函数信息头
    struct FunctionHD
    {
        uintptr_t name;  // 函数名
        uintptr_t sign;  // 函数签名
        uintptr_t data;  // 背景数据：文件中是偏移，内存中会计算并存储真正的偏移地址
        uint32_t flag;   // 函数标志
        uint32_t reg;    // 函数使用的寄存器数量
        uint32_t arg;    // 函数的参数寄存器数量
        uint32_t ins;    // 函数指令数量
        uint16_t item[]; // 函数指令
    };

    // 函数段表
    struct FunctionTable
    {
        uintptr_t count; // 函数数量
        FunctionHD *items[];
    };

    // 重定位段表
    struct RelocationTable
    {
        uintptr_t count; // 重定位数量
    };

    // 字节码文件
    struct ByteCodeFile
    {
        uintptr_t memsize; // 文件内存大小
        uintptr_t memadr;  // 文件加载地址

        FileHeader *hd;       // 文件头
        SegmentTable *segtab; // 段表

        StringTable *strtab;       // 字符串节表
        ANITable *anitab;          // ANI节表
        DynamicTable *dynatab;     // 动态库节表
        TypeTable *typetab;        // 类型节表
        FunctionTable *functab;    // 函数节表
        RelocationTable *reloctab; // 重定位节表

        // 计算段节的真实地址
        void calcSegmentTable();
        // 计算顶层项的地址
        void calcTopItem();
    };
}
#endif // __AIRABCF_INC__