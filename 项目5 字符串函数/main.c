#include "my.h"     // 包含自定义头文件
#include <stdio.h>  // 标准输入输出
#include <stdlib.h> // 标准库函数

int main()
{
    // 测试mylen函数
    printf("----mylen函数测试----\n");
    char s1[20] = "hello";
    printf("测试字符串: s1 = %s\n", s1);
    printf("mylen(s1) = %d\n", mylen(s1));
    printf("正确结果应为: 5\n\n");
    
    // 测试mycmp函数
    printf("----mycmp函数测试----\n");
    char s2[20] = "abc";
    char s3[20] = "abd";
    printf("s2 = %s\n", s2);
    printf("s3 = %s\n", s3);
    printf("mycmp(s2, s3) = %d\n", mycmp(s2, s3));
    printf("正确结果应为: -1 (因为\"abc\" < \"abd\")\n\n");
    
    // 测试mycpy函数
    printf("----mycpy函数测试----\n");
    printf("复制前:\n");
    char s4[20] = "hello";
    char s5[20] = "h";
    printf("s4 = %s\n", s4);
    printf("s5 = %s\n", s5);
    printf("mycpy(s5, s4) = %s\n", mycpy(s5, s4));
    printf("复制后:\n");
    printf("s4 = %s (应该不变)\n", s4);
    printf("s5 = %s (应该变成\"hello\")\n\n", s5);
    
    // 测试mycat函数
    printf("----mycat函数测试----\n");
    printf("连接前:\n");
    char s6[20] = "hello";
    char s7[20] = "world";
    printf("s6 = %s\n", s6);
    printf("s7 = %s\n", s7);
    printf("mycat(s6, s7) = %s\n", mycat(s6, s7));
    printf("连接后:\n");
    printf("s6 = %s (应该变成\"helloworld\")\n", s6);
    printf("s7 = %s (应该不变)\n\n", s7);
    
    // 测试myncmp函数
    printf("----myncmp函数测试----\n");
    printf("重新初始化测试数据:\n");
    char s8[20] = "abc";
    char s9[20] = "abd";
    printf("s8 = %s\n", s8);
    printf("s9 = %s\n", s9);
    printf("myncmp(s8, s9, 1) = %d\n", myncmp(s8, s9, 1));
    printf("正确结果应为: 0 (因为前1个字符相同)\n");
    printf("myncmp(s8, s9, 2) = %d\n", myncmp(s8, s9, 2));
    printf("正确结果应为: 0 (因为前2个字符相同)\n");
    printf("myncmp(s8, s9, 3) = %d\n", myncmp(s8, s9, 3));
    printf("正确结果应为: -1 (因为第3个字符不同)\n\n");
    
    // 测试myncpy函数
    printf("----myncpy函数测试----\n");
    printf("复制前:\n");
    char s10[20] = "Hello";
    char s11[20] = "h";
    printf("s10 = %s\n", s10);
    printf("s11 = %s\n", s11);
    printf("myncpy(s11, s10, 1) = %s\n", myncpy(s11, s10, 1));
    printf("复制后:\n");
    printf("s10 = %s (应该不变)\n", s10);
    printf("s11 = %s (应该变成\"H\")\n\n", s11);
    
    // 测试myncat函数
    printf("----myncat函数测试----\n");
    printf("连接前:\n");
    char s12[20] = "hello";
    char s13[20] = "world";
    printf("s12 = %s\n", s12);
    printf("s13 = %s\n", s13);
    printf("myncat(s12, s13, 1) = %s\n", myncat(s12, s13, 1));
    printf("连接后:\n");
    printf("s12 = %s (应该变成\"hellow\")\n", s12);
    printf("s13 = %s (应该不变)\n\n", s13);
    
    // 测试mychr函数
    printf("----mychr函数测试----\n");
    char s14[20] = "Hello";
    printf("s14 = %s\n", s14);
    printf("mychr(s14, 'l') = %s\n", mychr(s14, 'l'));
    printf("正确结果应为: \"llo\" (指向第一个'l'的位置)\n\n");
    
    // 测试myrchr函数
    printf("----myrchr函数测试----\n");
    printf("s14 = %s\n", s14);
    printf("myrchr(s14, 'l') = %s\n", myrchr(s14, 'l'));
    printf("正确结果应为: \"lo\" (指向最后一个'l'的位置)\n\n");
    
    printf("所有函数测试完成！\n");
    return 0;  // 程序正常结束
}
