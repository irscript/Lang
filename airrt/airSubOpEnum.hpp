#ifndef __AIRSUBOPENUM_INC__
#define __AIRSUBOPENUM_INC__

namespace airrt::abc::Enum
{
    // 操作子码相关枚举值

    // 常量赋值指令子码
    struct const_byte_subop
    {
        enum : unsigned int
        {
            // op--sub-des-imm :8-8-8-8
            const_w32_I8_B0 = 0, // 将 imm 存放在寄存器的第 1 个字节，不改变其他字节。
            const_w32_I8_B1 = 1, // 将 imm 存放在寄存器的第 2 个字节，不改变其他字节。
            const_w32_I8_B2 = 2, // 将 imm 存放在寄存器的第 3 个字节，不改变其他字节。
            const_w32_I8_B3 = 3, // 将 imm 存放在寄存器的第 4 个字节，不改变其他字节。

            const_w32_I8_s8 = 4, // imm 为有符号整数，有符号扩展至 32 bit
            const_w32_I8_u8 = 5, // imm 为无符号整数，无符号扩展至 32 bit
            const_w64_I8_s8 = 6, // imm 为有符号整数，有符号扩展至 64 bit
            const_w64_I8_u8 = 7, // imm 为无符号整数，无符号扩展至 64 bit

            // op--sub-des-imm :8-8-16-16
            const_w32_I16_s16 = 8,  // imm 为有符号整数，有符号扩展至 32 bit
            const_w32_I16_u16 = 9,  // imm 为无符号整数，无符号扩展至 32 bit
            const_w64_I16_s16 = 10, // imm 为有符号整数，有符号扩展至 64 bit
            const_w64_I16_u16 = 11, // imm 为无符号整数，无符号扩展至 64 bit

            // op--sub-des-imm :8-8-16-32
            const_w32_I16_i32 = 12, // 原样拷贝，支持32 bit 整数和浮点。
            const_w64_I16_s32 = 13, // imm 为有符号整数，有符号扩展至 64 bit
            const_w64_I16_u32 = 14, // imm 为无符号整数，无符号扩展至 64 bit

            // op--sub-des-imm :8-8-16-64
            const_w64_I16_i64 = 15, // 原样拷贝，支持64 bit 整数和浮点。
        };
    };

    // 寄存器间赋值指令子码
    struct move_reg_subop
    {
        enum : unsigned int
        {
            // 截断扩展、赋值
            extend_w32_B0_s8 = 0, // 获取寄存器的第 1 个字节，进行有符号扩展到 32 位
            extend_w32_B0_u8 = 1, // 获取寄存器的第 1 个字节，进行无符号扩展到 32 位
            extend_w32_B1_s8 = 2, // 获取寄存器的第 2 个字节，进行有符号扩展到 32 位
            extend_w32_B1_u8 = 3, // 获取寄存器的第 2 个字节，进行无符号扩展到 32 位
            extend_w32_B2_s8 = 4, // 获取寄存器的第 3 个字节，进行有符号扩展到 32 位
            extend_w32_B2_u8 = 5, // 获取寄存器的第 3 个字节，进行无符号扩展到 32 位
            extend_w32_B3_s8 = 6, // 获取寄存器的第 4 个字节，进行有符号扩展到 32 位
            extend_w32_B3_u8 = 7, // 获取寄存器的第 4 个字节，进行无符号扩展到 32 位

            extend_w32_L16_s16 = 8,  // 获取寄存器的低 16 bit，进行有符号扩展到 32 位
            extend_w32_L16_u16 = 9,  // 获取寄存器的低 16 bit，进行无符号扩展到 32 位
            extend_w32_H16_s16 = 10, // 获取寄存器的高 16 bit，进行有符号扩展到 32 位
            extend_w32_H16_u16 = 11, // 获取寄存器的高 16 bit，进行无符号扩展到 32 位

            move_w32_i32 = 12, // 原样拷贝，支持32 bit 整数和浮点。

            extend_w64_B0_s8 = 13, // 获取寄存器的第 1 个字节，进行有符号扩展到 64 位
            extend_w64_B0_u8 = 14, // 获取寄存器的第 1 个字节，进行无符号扩展到 64 位
            extend_w64_B1_s8 = 15, // 获取寄存器的第 2 个字节，进行有符号扩展到 64 位
            extend_w64_B1_u8 = 16, // 获取寄存器的第 2 个字节，进行无符号扩展到 64 位
            extend_w64_B2_s8 = 17, // 获取寄存器的第 3 个字节，进行有符号扩展到 64 位
            extend_w64_B2_u8 = 18, // 获取寄存器的第 3 个字节，进行无符号扩展到 64 位
            extend_w64_B3_s8 = 19, // 获取寄存器的第 4 个字节，进行有符号扩展到 64 位
            extend_w64_B3_u8 = 20, // 获取寄存器的第 4 个字节，进行无符号扩展到 64 位

            extend_w64_L16_s16 = 21, // 获取寄存器的低 16 bit，进行有符号扩展到 64 位
            extend_w64_L16_u16 = 22, // 获取寄存器的低 16 bit，进行无符号扩展到 64 位
            extend_w64_H16_s16 = 23, // 获取寄存器的高 16 bit，进行有符号扩展到 64 位
            extend_w64_H16_u16 = 24, // 获取寄存器的高 16 bit，进行无符号扩展到 64 位

            extend_w64_s32 = 25, // 获取32位寄存器的值，进行有符号到 64 位
            extend_w64_u32 = 26, // 获取32位寄存器的值，进行无符号到 64 位

            move_w64_i64 = 27, // 原样拷贝，支持64 bit 整数和浮点。

            // 类型转换：整数转浮点数:cast_from_<src>_to_<des>
            cast_s32_f32 = 28, // 32 bit 有符号整数转 32 bit 浮点数
            cast_s32_f64 = 29, // 32 bit 有符号整数转 64 bit 浮点数
            cast_u32_f32 = 30, // 32 bit 无符号整数转 32 bit 浮点数
            cast_u32_f64 = 31, // 32 bit 无符号整数转 64 bit 浮点数

            cast_s64_f32 = 32, // 64 bit 有符号整数转 32 bit 浮点数
            cast_s64_f64 = 33, // 64 bit 有符号整数转 64 bit 浮点数
            cast_u64_f32 = 34, // 64 bit 无符号整数转 32 bit 浮点数
            cast_u64_f64 = 35, // 64 bit 无符号整数转 64 bit 浮点数

            // 类型转换：浮点数转整数:cast_from_<src>_to_<des>
            cast_f32_s32 = 36, // 32 bit 浮点数转 32 bit 有符号整数
            cast_f32_u32 = 37, // 32 bit 浮点数转 32 bit 无符号整数
            cast_f32_s64 = 38, // 32 bit 浮点数转 64 bit 有符号整数
            cast_f32_u64 = 39, // 32 bit 浮点数转 64 bit 无符号整数

            cast_f64_s32 = 40, // 64 bit 浮点数转 32 bit 有符号整数
            cast_f64_u32 = 41, // 64 bit 浮点数转 32 bit 无符号整数
            cast_f64_s64 = 42, // 64 bit 浮点数转 64 bit 有符号整数
            cast_f64_u64 = 43, // 64 bit 浮点数转 64 bit 无符号整数

            // 类型转换：浮点数转浮点数:cast_from_<src>_to_<des>
            cast_f32_f64 = 44, // 32 bit 浮点数转 64 bit 浮点数
            cast_f64_f32 = 45, // 64 bit 浮点数转 32 bit 浮点数
        };
    };

    // 二地址运算指令
    struct math_op2
    {
        enum : unsigned int
        {
            // 普通一元运算
            not_w32 = 0, // 32 bit 按位取反
            not_w64 = 1, // 64 bit 按位取反

            inv_w32 = 2, // 32 bit 逻辑取反
            inv_w64 = 3, // 64 bit 逻辑取反

            neg_s32 = 4, // 32 bit 符号取反
            neg_s64 = 5, // 64 bit 符号取反
            neg_f32 = 6, // 32 bit 符号取反
            neg_f64 = 7, // 64 bit 符号取反

            abs_s32 = 8,  // 32 bit 取绝对值
            abs_s64 = 9,  // 64 bit 取绝对值
            abs_f32 = 10, // 32 bit 取绝对值
            abs_f64 = 11, // 64 bit 取绝对值

            // 与 0 比较运算

            cmp_ltz_i32 = 12, // 32 bit 整数 与 0 比较，des = src < 0 ? 1 : 0
            cmp_ltz_i64 = 13, // 64 bit 整数 与 0 比较，des = src < 0 ? 1 : 0
            cmp_ltz_f32 = 14, // 32 bit 浮点数 与 0 比较，des = src < 0 ? 1 : 0
            cmp_ltz_f64 = 15, // 64 bit 浮点数 与 0 比较，des = src < 0 ? 1 : 0

            cmp_lez_i32 = 16, // 32 bit 整数 与 0 比较，des = src <= 0 ? 1 : 0
            cmp_lez_i64 = 17, // 64 bit 整数 与 0 比较，des = src <= 0 ? 1 : 0
            cmp_lez_f32 = 18, // 32 bit 浮点数 与 0 比较，des = src <= 0 ? 1 : 0
            cmp_lez_f64 = 19, // 64 bit 浮点数 与 0 比较，des = src <= 0 ? 1 : 0

            cmp_gtz_i32 = 20, // 32 bit 整数 与 0 比较，des = src > 0 ? 1 : 0
            cmp_gtz_i64 = 21, // 64 bit 整数 与 0 比较，des = src > 0 ? 1 : 0
            cmp_gtz_f32 = 22, // 32 bit 浮点数 与 0 比较，des = src > 0 ? 1 : 0
            cmp_gtz_f64 = 23, // 64 bit 浮点数 与 0 比较，des = src > 0 ? 1 : 0

            cmp_gez_i32 = 24, // 32 bit 整数 与 0 比较，des = src >= 0 ? 1 : 0
            cmp_gez_i64 = 25, // 64 bit 整数 与 0 比较，des = src >= 0 ? 1 : 0
            cmp_gez_f32 = 26, // 32 bit 浮点数 与 0 比较，des = src >= 0 ? 1 : 0
            cmp_gez_f64 = 27, // 64 bit 浮点数 与 0 比较，des = src >= 0 ? 1 : 0

            cmp_eqz_i32 = 28, // 32 bit 整数 与 0 比较，des = src == 0 ? 1 : 0
            cmp_eqz_i64 = 29, // 64 bit 整数 与 0 比较，des = src == 0 ? 1 : 0
            cmp_eqz_f32 = 30, // 32 bit 浮点数 与 0 比较，des = src == 0 ? 1 : 0
            cmp_eqz_f64 = 31, // 64 bit 浮点数 与 0 比较，des = src == 0 ? 1 : 0

            cmp_nez_i32 = 32, // 32 bit 整数 与 0 比较，des = src != 0 ? 1 : 0
            cmp_nez_i64 = 33, // 64 bit 整数 与 0 比较，des = src != 0 ? 1 : 0
            cmp_nez_f32 = 34, // 32 bit 浮点数 与 0 比较，des = src != 0 ? 1 : 0
            cmp_nez_f64 = 35, // 64 bit 浮点数 与 0 比较，des = src != 0 ? 1 : 0

            // 三角函数
            sin_f32 = 36,  // 32 bit 浮点数三角正弦函数
            cos_f32 = 37,  // 32 bit 浮点数三角余弦函数
            tan_f32 = 38,  // 32 bit 浮点数三角正切函数
            asin_f32 = 39, // 32 bit 浮点数三角反正弦函数
            acos_f32 = 40, // 32 bit 浮点数三角反余弦函数
            atan_f32 = 41, // 32 bit 浮点数三角反正切函数

            sin_f64 = 42,  // 64 bit 浮点数三角正弦函数
            cos_f64 = 43,  // 64 bit 浮点数三角余弦函数
            tan_f64 = 44,  // 64 bit 浮点数三角正切函数
            asin_f64 = 45, // 64 bit 浮点数三角反正弦函数
            acos_f64 = 46, // 64 bit 浮点数三角反余弦函数
            atan_f64 = 47, // 64 bit 浮点数三角反正切函数

            // 倒数：reciprocal
            recip_f32 = 48, // 32 bit 浮点数倒数函数
            recip_f64 = 49, // 64 bit 浮点数倒数函数

        };
    };

    // 三地址运算指令
    struct math_op3
    {
        enum : unsigned int
        {
            // 加法
            add_i32 = 0, // 32 bit 整数相加
            add_i64 = 1, // 64 bit 整数相加
            add_f32 = 2, // 32 bit 浮点数相加
            add_f64 = 3, // 64 bit 浮点数相加

            // 减法
            sub_i32 = 4, // 32 bit 整数相减
            sub_i64 = 5, // 64 bit 整数相减
            sub_f32 = 6, // 32 bit 浮点数相减
            sub_f64 = 7, // 64 bit 浮点数相减

            // 乘法
            mul_s32 = 8,  // 32 bit 整数相乘
            mul_u32 = 9,  // 32 bit 整数相乘
            mul_s64 = 10, // 64 bit 整数相乘
            mul_u64 = 11, // 64 bit 整数相乘
            mul_f32 = 12, // 32 bit 浮点数相乘
            mul_f64 = 13, // 64 bit 浮点数相乘

            // 除法
            div_s32 = 12, // 32 bit 整数相除
            div_u32 = 13, // 32 bit 整数相除
            div_s64 = 14, // 64 bit 整数相除
            div_u64 = 15, // 64 bit 整数相除
            div_f32 = 16, // 32 bit 浮点数相除
            div_f64 = 17, // 64 bit 浮点数相除

            // 取余：remainder
            rem_s32 = 18, // 32 bit 整数取余
            rem_u32 = 19, // 32 bit 整数取余
            rem_s64 = 20, // 64 bit 整数取余
            rem_u64 = 21, // 64 bit 整数取余

            //--------------位运算-------------------
            and_w32 = 22, // 32 bit 与运算
            and_w64 = 23, // 64 bit 与运算
            or_w32 = 24,  // 32 bit 或运算
            or_w64 = 25,  // 64 bit 或运算
            xor_w32 = 26, // 32 bit 异或运算
            xor_w64 = 27, // 64  bit 异或运算

            andn_w32 = 28, // 32 bit 与非运算
            andn_w64 = 29, // 64 bit 与非运算
            orn_w32 = 30,  // 32 bit 或非运算
            orn_w64 = 31,  // 64 bit 或非运算
            xorn_w32 = 32, // 32 bit 异或非运算
            xorn_w64 = 33, // 64  bit 异或非运算

            //-------------位移运算-----------
            shl_w32 = 34, // 32 bit 逻辑左移运算
            shl_w64 = 35, // 64 bit 逻辑左移运算
            shr_w32 = 36, // 32 bit 逻辑右移运算
            shr_w64 = 37, // 64 bit 逻辑右移运算
            sar_w32 = 38, // 32 bit 算术右移运算
            sar_w64 = 39, // 64 bit 算术右移运算
            rol_w32 = 40, // 32 bit 循环左移运算
            rol_w64 = 41, // 64 bit 循环左移运算
            ror_w32 = 42, // 32 bit 循环右移运算
            ror_w64 = 43, // 64 bit 循环右移运算

            //--------------逻辑运算--------------
            andl_w32 = 44, // 32 bit 逻辑与运算
            andl_w64 = 45, // 64 bit 逻辑与运算
            orl_w32 = 46,  // 32 bit 逻辑或运算
            orl_w64 = 47,  // 64 bit 逻辑或运算

            //---------------比较运算--------------
            cmp_eq_i32 = 48, // 32 bit 整数比较，des = src == src2 ? 1 : 0
            cmp_eq_i64 = 49, // 64 bit 整数比较，des = src == src2 ? 1 : 0
            cmp_eq_f32 = 50, // 32 bit 浮点数比较，des = src == src2 ? 1 : 0
            cmp_eq_f64 = 51, // 64 bit 浮点数比较，des = src == src2 ? 1 : 0

            cmp_ne_i32 = 52, // 32 bit 整数比较，des = src != src2 ? 1 : 0
            cmp_ne_i64 = 53, // 64 bit 整数比较，des = src != src2 ? 1 : 0
            cmp_ne_f32 = 54, // 32 bit 浮点数比较，des = src != src2 ? 1 : 0
            cmp_ne_f64 = 55, // 64 bit 浮点数比较，des = src != src2 ? 1 : 0

            cmp_lt_s32 = 56, // 32 bit 整数比较，des = src < src2 ? 1 : 0
            cmp_lt_u32 = 57, // 32 bit 整数比较，des = src < src2 ? 1 : 0
            cmp_lt_s64 = 58, // 64 bit 整数比较，des = src < src2 ? 1 : 0
            cmp_lt_u64 = 59, // 64 bit 整数比较，des = src < src2 ? 1 : 0
            cmp_lt_f32 = 60, // 32 bit 浮点数比较，des = src < src2 ? 1 : 0
            cmp_lt_f64 = 61, // 64 bit 浮点数比较，des = src < src2 ? 1 : 0

            cmp_le_s32 = 62, // 32 bit 整数比较，des = src <= src2 ? 1 : 0
            cmp_le_u32 = 63, // 32 bit 整数比较，des = src <= src2 ? 1 : 0
            cmp_le_s64 = 64, // 64 bit 整数比较，des = src <= src2 ? 1 : 0
            cmp_le_u64 = 65, // 64 bit 整数比较，des = src <= src2 ? 1 : 0
            cmp_le_f32 = 66, // 32 bit 浮点数比较，des = src <= src2 ? 1 : 0
            cmp_le_f64 = 67, // 64 bit 浮点数比较，des = src <= src2 ? 1 : 0

            cmp_gt_s32 = 68, // 32 bit 整数比较，des = src > src2 ? 1 : 0
            cmp_gt_u32 = 69, // 32 bit 整数比较，des = src > src2 ? 1 : 0
            cmp_gt_s64 = 70, // 64 bit 整数比较，des = src > src2 ? 1 : 0
            cmp_gt_u64 = 71, // 64 bit 整数比较，des = src > src2 ? 1 : 0
            cmp_gt_f32 = 72, // 32 bit 浮点数比较，des = src > src2 ? 1 : 0
            cmp_gt_f64 = 73, // 64 bit 浮点数比较，des = src < src2 ? 1 : 0

            cmp_ge_s32 = 74, // 32 bit 整数比较，des = src >= src2 ? 1 : 0
            cmp_ge_u32 = 75, // 32 bit 整数比较，des = src >= src2 ? 1 : 0
            cmp_ge_s64 = 76, // 64 bit 整数比较，des = src >= src2 ? 1 : 0
            cmp_ge_u64 = 77, // 64 bit 整数比较，des = src >= src2 ? 1 : 0
            cmp_ge_f32 = 78, // 32 bit 浮点数比较，des = src >= src2 ? 1 : 0
            cmp_ge_f64 = 79, // 64 bit 浮点数比较，des = src >= src2 ? 1 : 0

            //-------------标准数学指令---------------

            // 最大值: des = src > src2 ? src : src2
            max_s32 = 80, // 32 bit 整数最大值
            max_u32 = 81, // 32 bit 整数最大值
            max_s64 = 82, // 64 bit 整数最大值
            max_u64 = 83, // 64 bit 整数最大值
            max_f32 = 84, // 32 bit 浮点数最大值
            max_f64 = 85, // 64 bit 浮点数最大值

            // 最小值: des = src < src2 ? src : src2
            min_s32 = 86, // 32 bit 整数最小值
            min_u32 = 87, // 32 bit 整数最小值
            min_s64 = 88, // 64 bit 整数最小值
            min_u64 = 89, // 64 bit 整数最小值
            min_f32 = 90, // 32 bit 浮点最小值
            min_f64 = 91, // 64 bit 浮点最小值

            // 浮点数取余
            rem_f32 = 16, // 32 bit 浮点数取余
            rem_f64 = 17, // 64 bit 浮点数取余
        };
    };

    // 0 比较跳转指令子码
    struct jbrz
    {
        enum : unsigned int
        {
            cmp_ltz_i32 = 0, // 32 bit 整数 与 0 比较，des = src < 0 ? 1 : 0
            cmp_ltz_i64 = 1, // 64 bit 整数 与 0 比较，des = src < 0 ? 1 : 0
            cmp_ltz_f32 = 2, // 32 bit 浮点数 与 0 比较，des = src < 0 ? 1 : 0
            cmp_ltz_f64 = 3, // 64 bit 浮点数 与 0 比较，des = src < 0 ? 1 : 0

            cmp_lez_i32 = 16, // 32 bit 整数 与 0 比较，des = src <= 0 ? 1 : 0
            cmp_lez_i64 = 17, // 64 bit 整数 与 0 比较，des = src <= 0 ? 1 : 0
            cmp_lez_f32 = 18, // 32 bit 浮点数 与 0 比较，des = src <= 0 ? 1 : 0
            cmp_lez_f64 = 19, // 64 bit 浮点数 与 0 比较，des = src <= 0 ? 1 : 0

            cmp_gtz_i32 = 20, // 32 bit 整数 与 0 比较，des = src > 0 ? 1 : 0
            cmp_gtz_i64 = 21, // 64 bit 整数 与 0 比较，des = src > 0 ? 1 : 0
            cmp_gtz_f32 = 22, // 32 bit 浮点数 与 0 比较，des = src > 0 ? 1 : 0
            cmp_gtz_f64 = 23, // 64 bit 浮点数 与 0 比较，des = src > 0 ? 1 : 0

            cmp_gez_i32 = 24, // 32 bit 整数 与 0 比较，des = src >= 0 ? 1 : 0
            cmp_gez_i64 = 25, // 64 bit 整数 与 0 比较，des = src >= 0 ? 1 : 0
            cmp_gez_f32 = 26, // 32 bit 浮点数 与 0 比较，des = src >= 0 ? 1 : 0
            cmp_gez_f64 = 27, // 64 bit 浮点数 与 0 比较，des = src >= 0 ? 1 : 0

            cmp_eqz_i32 = 28, // 32 bit 整数 与 0 比较，des = src == 0 ? 1 : 0
            cmp_eqz_i64 = 29, // 64 bit 整数 与 0 比较，des = src == 0 ? 1 : 0
            cmp_eqz_f32 = 30, // 32 bit 浮点数 与 0 比较，des = src == 0 ? 1 : 0
            cmp_eqz_f64 = 31, // 64 bit 浮点数 与 0 比较，des = src == 0 ? 1 : 0

            cmp_nez_i32 = 32, // 32 bit 整数 与 0 比较，des = src != 0 ? 1 : 0
            cmp_nez_i64 = 33, // 64 bit 整数 与 0 比较，des = src != 0 ? 1 : 0
            cmp_nez_f32 = 34, // 32 bit 浮点数 与 0 比较，des = src != 0 ? 1 : 0
            cmp_nez_f64 = 35, // 64 bit 浮点数 与 0 比较，des = src != 0 ? 1 : 0

        };
    };
}

#endif // __AIRSUBOPENUM_INC__