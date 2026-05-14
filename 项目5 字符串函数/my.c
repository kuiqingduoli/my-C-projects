#include "my.h"
#include <stdlib.h>

/*
 * 计算字符串长度
 * 实现思路: 遍历字符串直到遇到'\0'，计数器记录字符个数
 */
int mylen(char *s)
{
    int cnt = 0;  // 计数器，记录字符个数
    
    // 遍历字符串直到遇到字符串结束符'\0'
    while (s[cnt] != '\0')
    {
        cnt++;  // 字符数加1
    }
    
    return cnt;  // 返回字符串长度
}

/*
 * 比较两个字符串
 * 实现思路: 逐个字符比较，遇到不同或任一字符串结束则停止
 * 根据ASCII码值返回比较结果
 */
int mycmp(char *s1, char *s2)
{
    int cnt = 0;  // 用于遍历字符串的索引
    int ret;      // 存储比较结果
    
    // 循环比较两个字符串，直到任一字符串结束
    while (s1[cnt] != '\0' && s2[cnt] != '\0')
    {
        // 如果当前字符不同，退出循环
        if (s1[cnt] != s2[cnt])
        {
            break;
        }
        cnt++;  // 移动到下一个字符
    }
    
    // 根据最后一个比较的字符确定返回值
    if (s1[cnt] > s2[cnt])
    {
        ret = 1;    // s1 > s2
    }
    else if (s1[cnt] == s2[cnt])
    {
        ret = 0;    // s1 == s2
    }
    else
    {
        ret = -1;   // s1 < s2
    }
    
    return ret;  // 返回比较结果
}

/*
 * 复制字符串s2到s1
 * 实现思路: 逐个字符复制，包括字符串结束符'\0'
 */
char *mycpy(char *s1, char *s2)
{
    int i;  // 循环索引
    
    // 遍历源字符串s2，复制每个字符到s1
    for (i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];  // 复制字符
    }
    
    s1[i] = '\0';  // 添加字符串结束符
    return s1;     // 返回目标字符串指针
}

/*
 * 连接字符串s2到s1末尾
 * 实现思路: 先找到s1的末尾，然后将s2的内容追加到后面
 */
char *mycat(char *s1, char *s2)
{
    int cnt1 = 0;  // 用于遍历s1
    
    // 找到s1的末尾（'\0'的位置）
    while (s1[cnt1] != '\0')
    {
        cnt1++;
    }
    
    int cnt2 = 0;  // 用于遍历s2
    
    // 将s2的内容复制到s1的末尾
    while (s2[cnt2] != '\0')
    {
        s1[cnt1] = s2[cnt2];  // 复制字符
        cnt1++;               // s1位置后移
        cnt2++;               // s2位置后移
    }
    
    s1[cnt1] = '\0';  // 添加字符串结束符
    return s1;        // 返回连接后的字符串指针
}

/*
 * 比较两个字符串的前len个字符
 * 实现思路: 在mycmp基础上添加长度限制
 */
int myncmp(char *s1, char *s2, int len)
{
    int cnt = 0;  // 用于遍历字符串的索引
    
    // 循环比较前len个字符，但不超过任一字符串的长度
    while (cnt < len && s1[cnt] != '\0' && s2[cnt] != '\0')
    {
        if (s1[cnt] != s2[cnt])  // 找到不同字符
        {
            break;
        }
        cnt++;  // 移动到下一个字符
    }
    
    // 如果已经比较了len个字符，说明前len个字符相同
    if (cnt == len)
    {
        return 0;  // 前len个字符完全相同
    }
    
    // 否则，根据当前字符的大小关系返回结果
    if (s1[cnt] > s2[cnt])
    {
        return 1;    // s1 > s2
    }
    else if (s1[cnt] < s2[cnt])
    {
        return -1;   // s1 < s2
    }
    else
    {
        // 当前字符相同，但其中一个字符串已结束
        if (s1[cnt] == '\0' && s2[cnt] != '\0')
        {
            return -1;  // s1较短
        }
        else if (s2[cnt] == '\0' && s1[cnt] != '\0')
        {
            return 1;   // s2较短
        }
        else
        {
            return 0;   // 都结束，且最后字符相同
        }
    }
}

/*
 * 复制s2的前len个字符到s1
 * 实现思路: 在mycpy基础上添加长度限制
 */
char *myncpy(char *s1, char *s2, int len)
{
    int i;  // 循环索引
    
    // 复制最多len个字符，或直到遇到s2的结束符
    for (i = 0; i < len && s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];  // 复制字符
    }
    
    // 如果s2提前结束，用'\0'填充剩余位置
    // 这是标准库strncpy的行为，保证复制恰好len个字符
    while (i < len)
    {
        s1[i] = '\0';  // 填充'\0'
        i++;           // 继续填充下一个位置
    }
    
    return s1;  // 返回目标字符串指针
}

/*
 * 连接s2的前len个字符到s1末尾
 * 实现思路: 在mycat基础上添加长度限制
 */
char *myncat(char *s1, char *s2, int len)
{
    int cnt1 = 0;  // 用于遍历s1
    
    // 找到s1的末尾
    while (s1[cnt1] != '\0')
    {
        cnt1++;
    }
    
    int cnt2 = 0;  // 用于遍历s2
    
    // 从s2复制最多len个字符到s1末尾
    while (cnt2 < len && s2[cnt2] != '\0')
    {
        s1[cnt1] = s2[cnt2];  // 复制字符
        cnt1++;               // s1位置后移
        cnt2++;               // s2位置后移
    }
    
    s1[cnt1] = '\0';  // 添加字符串结束符
    return s1;        // 返回连接后的字符串指针
}

/*
 * 在字符串中查找指定字符（正向查找）
 * 实现思路: 从字符串开头开始遍历，找到第一个匹配的字符
 */
char *mychr(char *s, char c)
{
    char *p = NULL;  // 初始化返回指针为NULL
    int i;           // 循环索引
    
    // 遍历字符串
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)  // 找到匹配字符
        {
            p = &s[i];  // 保存字符地址
            break;      // 退出循环
        }
    }
    
    return p;  // 返回指针，如果未找到则为NULL
}

/*
 * 在字符串中查找指定字符（反向查找）
 * 实现思路: 从字符串末尾向前遍历，找到最后一个匹配的字符
 */
char *myrchr(char *s, char c)
{
    char *p = NULL;  // 初始化返回指针为NULL
    int i;           // 循环索引
    
    // 先遍历到字符串末尾，找到'\0'的位置
    for (i = 0; s[i] != '\0'; i++)
    {
        // 空循环，目的是让i递增到字符串结束符的位置
    }
    
    // 从字符串末尾向前遍历
    // 注意: i现在指向'\0'，所以i-1指向最后一个有效字符
    for (i--; i >= 0; i--)
    {
        if (s[i] == c)  // 找到匹配字符
        {
            p = &s[i];  // 保存字符地址
            break;      // 退出循环
        }
    }
    
    return p;  // 返回指针，如果未找到则为NULL
}
