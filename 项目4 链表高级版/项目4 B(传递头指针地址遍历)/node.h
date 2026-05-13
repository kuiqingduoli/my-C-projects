#ifndef _NODE_H
#define _NODE_H

#include <stdio.h>
#include <stdlib.h>

/* 定义链表节点结构体 */
typedef struct node
{
    int value;          // 节点存储的数据
    struct node *next;  // 指向下一个节点的指针
} Node;

/* 函数声明 */

// 向链表尾部添加新节点
void add(Node **Phead, int number);

// 显示链表中所有节点的值
void show(Node *head);

// 在链表中搜索指定值
int search(Node *head, int num);

// 删除链表中第一个包含指定值的节点
void Delete(Node **Phead, int num);

// 在指定位置插入新节点
void inserted(Node **Phead, int num, int index);

// 反转链表
void reverse(Node **Phead);

// 计算链表的长度（节点个数）
int length(Node *head);

// 释放链表所有节点的内存
void Free(Node **Phead);

#endif
