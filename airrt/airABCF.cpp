#include "airABCF.hpp"
namespace airrt::abc
{
    int32_t String::compare(const String &str) const
    {
        // 首先比较两个字符串的值
        if (mValue == str.mValue)
        {
            // 如果值相等，进一步按字符比较
            for (uint32_t i = 0; i < mSize; ++i)
            {
                if (mData[i] != str.mData[i])
                {
                    // 发现不相等的字符，根据大小返回-1或1
                    return mData[i] < str.mData[i] ? -1 : 1;
                }
            }
            // 所有字符都相等，返回0表示两个字符串相等
            return 0;
        }
        // 如果字符串的值不相等，比较长度较小的那个字符串
        uint32_t len = mSize < str.mSize ? mSize : str.mSize;
        for (uint32_t i = 0; i < len; ++i)
        {
            if (mData[i] != str.mData[i])
            {
                // 发现不相等的字符，根据大小返回-1或1
                return mData[i] < str.mData[i] ? -1 : 1;
            }
        }
        // 两个字符串前缀相同，但长度不同，较短的字符串认为较大
        return 1;
    }

    bool String::equals(const String &str) const
    {
        // 首先比较两个字符串的哈希值，如果不相等，则字符串内容一定不相等
        if (mValue != str.mValue)
            return false;
        for (uint32_t i = 0; i < mSize; ++i)
        {
            // 遍历字符串的每个字符，找到第一个不相等的字符即返回false
            if (mData[i] != str.mData[i])
            {
                return false;
            }
        }
        // 当遍历完所有字符后，如果没有发现不相等的字符，则字符串相等
        return true;
    }
}