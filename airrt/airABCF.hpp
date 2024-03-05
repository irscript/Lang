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
            uint32_t mValue; // 用于快速判断字符串是否相等
            struct
            {
                uint16_t mSize; // 字符串长度值，不包括\0
                uint16_t mHash; // 字符串哈希值
            };
        };
        char mData[]; // 字符串数据

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
        int32_t compare(const String &str) const;

        /**
         * 检查当前字符串与另一个字符串是否相等。
         * @param str 要比较的另一个字符串。
         * @return 如果两个字符串相等返回true，否则返回false。
         */
        bool equals(const String &str) const;
    };

    // 文件头
    struct FileHeader
    {
        uint8_t mMagic[4]; // 文件标识，用于判断文件是否为字节码文件
        uint8_t mMd5[16];  // 文件的md5值,除本字段后的所有字段参与计算

        uint8_t mEndian; // 字节序，大端：0xAA，小端：0x55
        uint8_t mArch;   // 地址架构，32位地址：32,64位地址：64
        uint16_t mKind;  // 文件类型：标识动态库、可执行文件等

        uint32_t mFormat;   // 文件格式版本号
        uint32_t mInstruct; // 指令版本号

        uint64_t mTime; // 生成时间

        uint32_t mEntry; // 入口地址

        uint32_t mOffset; // 段表偏移，相对于文件起始的偏移量
    };

    // 程序版本作者等信息，在文件中存储使用压缩后的json格式
    struct FileInfo
    {
        const char *mName;    // 程序名
        const char *mVersion; // 版本号
        const char *mAuthor;  // 作者名
        const char *mCompany; // 公司名
    };

    // 段节表
    struct SegmentTable
    {
        uintptr_t mCount; // 段数量

        struct Item
        {
            uintptr_t mKind;   // 段类别
            uintptr_t mOffset; // 段偏移
        };
        Item mItem[];
    };

    // 字符串表
    struct StringTable
    {
        uintptr_t mCount;         // 字符串数量
        const String *mItemPtr[]; // 字符串表
    };

    // ANI函数项
    struct ANIFunc
    {
        union
        {
            uintptr_t mIndex;    // 字符串索引
            const String *mName; // 字符串地址
        };                       // 函数名称
        uintptr_t mFunc;         // 函数地址
    };
    // ANI项
    struct ANIItem
    {
        uintptr_t mCount; // 函数数量
        ANIFunc mFunc[];  // 函数信息
    };
    // ANI表项
    struct ANITableItem
    {
        union
        {
            uintptr_t mIndex;    // 字符串索引
            const String *mName; // 字符串地址
        };                       // 动态库名称
        uintptr_t mHandle;       // 动态库句柄

        ANIItem mDetail; // 动态库信息
    };
    // ANI表
    struct ANITable
    {
        uintptr_t mCount; // ANI数量

        union Item
        {
            ANITableItem *mItems; // ANI表项
            uintptr_t mOffset;    // ANI表项偏移
        };
        Item mItems[];
    };

    // 动态库表
    struct DynamicTable
    {
        uintptr_t mCount; // 动态库数量

        struct Item
        {
            union
            {
                uintptr_t mIndex;    // 字符串索引
                const String *mName; // 字符串地址
            };                       // 动态库名称
            uintptr_t mHandle;       // 动态库文件句柄
        };

        Item mItems[];
    };

    // 类型信息头
    struct TypeHD
    {
        uint32_t mFlag;  // 类型标志
        uint32_t mCount; // 成员数量
        union
        {
            uintptr_t mIndex;    // 字符串索引
            const String *mName; // 字符串地址
        };                       // 类型名
        size_t mSize;            // 大小
        size_t mAlign;           // 对齐
    };

    // 基本类型
    using BaseType = TypeHD;

    // 枚举类型
    struct EnumType : public TypeHD
    {
    };

    // 结构体类型
    struct StructType : public TypeHD
    {
    };

    // 联合体
    struct UnionType : public TypeHD
    {
    };

    // 类类型
    struct ClassType : public TypeHD
    {
    };
    // 接口类型
    struct InterfaceType : public TypeHD
    {
    };
    // 委托类型
    struct DelegateType : public TypeHD
    {
    };

    // 类型段表
    struct TypeTable
    {
        uintptr_t mCount; // 类型数量

        union Item
        {
            TypeHD *mType;     // 类型表项地址
            uintptr_t mOffset; // 类型表项偏移
        };
        Item mItems[]; // 类型表项
    };

    // 函数信息头
    struct FunctionHD
    {
        union
        {
            uintptr_t mIndex;    // 字符串索引
            const String *mName; // 字符串地址
        };                       // 函数名
        uintptr_t mSign;         // 函数签名
        uintptr_t mData;         // 背景数据：文件中是偏移，内存中会计算并存储真正的偏移地址
        uint32_t mFlag;          // 函数标志
        uint32_t mRegs;          // 函数使用的寄存器数量
        uint32_t mArgs;          // 函数的参数寄存器数量
        uint32_t mTotal;         // 函数指令数量
        uint16_t mItem[];        // 函数指令
    };

    // 函数段表
    struct FunctionTable
    {
        uintptr_t mCount; // 函数数量
        FunctionHD *mItems[];
    };

    // 重定位段表
    struct RelocationTable
    {
        uintptr_t mCount; // 重定位数量
    };

    // 字节码文件
    struct BCFile
    {
        uintptr_t mMemsize; // 文件内存大小
        uintptr_t mAddress; // 文件加载地址

        FileHeader *mHd;       // 文件头
        SegmentTable *mSegtab; // 段表

        StringTable *mStrtab;     // 字符串节表
        uintptr_t mStrsec;        // 字符串节
        ANITable *mANItab;        // ANI节表
        uintptr_t mANIsec;        // ANI节
        DynamicTable *mDyntab;    // 动态库节表
        uintptr_t mDynsec;        // 动态库节
        TypeTable *mTypetab;      // 类型节表
        uintptr_t mTypesec;       // 类型节
        FunctionTable *mFunctab;  // 函数节表
        uintptr_t mFuncsec;       // 函数节
        RelocationTable *mReltab; // 重定位节表
        uintptr_t mRelsec;        // 重定位节

        String *mPath; // 文件名称路径

        // 计算段节的真实地址
        void calcSegmentTable();
        // 计算顶层项的地址
        void calcTopItem();
    };
}
#endif // __AIRABCF_INC__