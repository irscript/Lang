#ifndef __AIROPENUM_INC__
#define __AIROPENUM_INC__
namespace airrt::abc::Enum
{
    // 操作码相关枚举值
    struct Opcode
    {
        enum : unsigned int
        {
            nop = 0, // 空操作

            //---------------------常量赋值指令-----------------------
            // 4 bit 常量赋值指令: op-des-imm :8-4-4
            const_w32_I4_s4 = 1, // imm 为有符号整数，有符号扩展至 32 bit。
            const_w32_I4_u4 = 2, // imm 为无符号整数，无符号扩展至 32 bit。
            const_w64_I4_s4 = 3, // imm 为有符号整数，有符号扩展至 64 bit。
            const_w64_I4_u4 = 4, // imm 为无符号整数，无符号扩展至 64 bit。

            // 16 bit 常量赋值指令: op-des-imm :8-8-16
            const_w32_I8_s16 = 5, // imm 为有符号整数，有符号扩展至 32 bit。
            const_w32_I8_u16 = 6, // imm 为无符号整数，无符号扩展至 32 bit。
            const_w64_I8_s16 = 7, // imm 为有符号整数，有符号扩展至 64 bit。
            const_w64_I8_u16 = 8, // imm 为无符号整数，无符号扩展至 64 bit。
            const_w32_I8_L16 = 7, // imm 存放在寄存器低 16 bit，不改变高 16 bit。
            const_w32_I8_H16 = 8, // imm 存放在寄存器高 16 bit，不改变低 16 bit。

            // 32 bit 常量赋值指令: op-des-imm :8-8-32
            const_w32_I8_i32 = 9,  // 原样拷贝，支持32 bit 整数和浮点。
            const_w64_I8_s32 = 10, // imm 为无符号整数，无符号扩展至 32 bit。
            const_w64_I8_u32 = 11, // imm 为有符号整数，有符号扩展至 64 bit。

            // 64 bit 常量赋值指令: op-des-imm :8-8-64
            const_w64_I8_i64 = 12, // 原样拷贝，支持64 bit 整数和浮点。

            //---------------------常量赋值指令-----------------------
            // 常量赋值指令: op--sub-des-imm :8-8-8-8
            const_byte_subop = 13,

            //---------------------寄存器间赋值指令-----------------------
            // 寄存器间赋值指令：op-des-src:8-4-4
            move_w32_I4 = 14, // 32 位寄存器值传递,R32.des=R32.src
            move_w64_I4 = 15, // 64 位寄存器值传递,R64.des=R64.src
            // 寄存器间赋值指令：op-des-src:8-8-16
            move_w32_I8 = 16, // 32 位寄存器值传递,R32.des=R32.src
            move_w64_I8 = 17, // 64 位寄存器值传递,R64.des=R64.src
            // 寄存器间赋值指令：op-src-des:8-8-16
            move_w32_I16 = 16, // 32 位寄存器值传递,R32.des=R32.src
            move_w64_I16 = 17, // 64 位寄存器值传递,R64.des=R64.src

            // 寄存器间赋值指令：op-sub-des-src:8-8-8-8
            move_reg_I8_subop = 18,
            // 寄存器间赋值指令：op-sub-des-src:8-8-16-16
            move_reg_I16_subop = 19,

            //--------------------二地址运算指令-----------------------
            // 二地址运算指令:op-sub-des-src:8-8-8-8
            math_op2_I8_subop = 20,
            // 二地址运算指令:op-sub-des-src:8-8-16-16
            math_op2_I16_subop = 21,

            //--------------------三地址运算指令-----------------------
            // 二地址运算指令:op-sub-des-src-src2:8-8-8-4-4
            math_op3_I4_subop = 22,
            // 二地址运算指令:op-sub-des-src-src2:8-8-16-8-8
            math_op3_I8_subop = 23,
            // 二地址运算指令:op-sub-des-src-src2:8-8-16-16-16
            math_op3_I16_subop = 24,

            //--------------------分支跳转指令-----------------
            // 直接跳转指令：op-imm:8-8-32,中间 8 bit 为对齐域
            jmp_imm32 = 25,
            // 直接跳转指令：op-reg:8-8,寄存器中存储的是32位无符号偏移
            jmp_reg_I8 = 26,
            // 直接跳转指令：op-reg:8-8-16,中间 8 bit 为对齐域
            jmp_reg_I16 = 27,
            // 0 比较跳转指令：op-sub-reg-offset:8-8-16-32
            jbrz_subop = 28,

        };
    };

}
#endif // __AIROPENUM_INC__