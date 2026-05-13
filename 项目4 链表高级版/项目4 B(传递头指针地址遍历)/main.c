#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    Node *head = NULL;  // 链表头指针，初始为空链表
    int number;         // 用于存储用户输入的数字
    
    printf("========== 链表操作演示 ==========\n");
    
    // 循环读取用户输入，构建链表
    do {
        printf("请输入一个数字(输入-1结束): ");
        scanf("%d", &number);
        
        if (number != -1) {
            add(&head, number);  // 将数字添加到链表尾部
        }
    } while (number != -1);  // 输入-1时结束循环
    
    show(head);  // 显示当前链表
    
    int num;  // 用于存储要搜索/删除/插入的数字
    
    // 搜索操作
    printf("请输入要搜索的数字: ");
    scanf("%d", &num);
    int isfound = search(head, num);  // 搜索并返回结果
    
    // 删除操作
    printf("请输入要删除的数字: ");
    scanf("%d", &num);
    isfound = search(head, num);  // 先搜索确认存在
    
    if (isfound) {
        Delete(&head, num);  // 删除节点
        printf("已删除\n");
        show(head);  // 显示删除后的链表
    } else {
        printf("未找到该数字，无法删除\n");
    }
    
    // 插入操作
    int index;  // 插入位置
    printf("请输入要插入的数字和插入的位置: ");
    scanf("%d %d", &num, &index);
    inserted(&head, num, index);  // 在指定位置插入
    show(head);  // 显示插入后的链表
    
    // 反转操作
    printf("将链表反转\n");
    reverse(&head);  // 反转链表
    show(head);  // 显示反转后的链表
    
    // 计算长度
    int len = length(head);  // 获取链表长度
    printf("现在链表的长度为: %d\n", len);
    
    // 释放内存
    Free(&head);  // 释放链表所有节点的内存
    
    printf("========== 程序结束 ==========\n");
    return 0;
}
