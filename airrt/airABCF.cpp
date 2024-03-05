#include "airABCF.hpp"
namespace airrt::abc
{
    int32_t String::compare(const String &str)
    {
        // 首先比较两个字符串的值
        if (value == str.value)
        {
            // 如果值相等，进一步按字符比较
            for (uint32_t i = 0; i < size; ++i)
            {
                if (data[i] != str.data[i])
                {
                    // 发现不相等的字符，根据大小返回-1或1
                    return data[i] < str.data[i] ? -1 : 1;
                }
            }
            // 所有字符都相等，返回0表示两个字符串相等
            return 0;
        }
        // 如果字符串的值不相等，比较长度较小的那个字符串
        uint32_t len = size < str.size ? size : str.size;
        for (uint32_t i = 0; i < len; ++i)
        {
            if (data[i] != str.data[i])
            {
                // 发现不相等的字符，根据大小返回-1或1
                return data[i] < str.data[i] ? -1 : 1;
            }
        }
        // 两个字符串前缀相同，但长度不同，较短的字符串认为较大
        return 1;
    }
}