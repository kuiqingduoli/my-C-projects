#ifndef _NODE_H_  // 头文件保护宏，防止重复包含
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>

/* 定义链表节点结构体 */
typedef struct node
{
	int value;          // 节点存储的整数值
	struct node *next;  // 指向下一个节点的指针
} Node;

/* 函数声明 */

// 向链表尾部添加新节点，返回链表头指针
Node *add(Node *head, int number);

// 显示链表中所有节点的值
void show(Node *head);

// 在链表中搜索指定值，返回是否找到(1-找到,0-未找到)
int search(Node *head, int num);

// 删除链表中第一个包含指定值的节点，返回链表头指针
Node *Delete(Node *head, int num);

// 在指定位置插入新节点，返回链表头指针
Node *inserted(Node *head, int num, int index);

// 反转链表，返回新的链表头指针
Node *reverse(Node *head);

// 释放链表所有节点的内存，返回NULL指针
Node *Free(Node *head);

#endif
