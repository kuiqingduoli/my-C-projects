#ifndef _NODE_H_ 
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct node
{
	int value;          // 节点存储的数据
	struct node *next;  // 指向下一个节点的指针
} Node;

// 定义链表结构（包含头尾指针）
typedef struct list
{
	Node *head;  // 指向链表头节点的指针
	Node *tail;  // 指向链表尾节点的指针
} List;

// 函数声明

// 向链表尾部添加新节点
void add(List *plist, int number);

// 显示链表中所有节点的值
void show(List *plist);

// 在指定位置插入新节点
void inserted(List *plist, int num, int index);

// 在链表中搜索指定值
int search(List *plist, int num);

// 删除链表中第一个包含指定值的节点
void Delete(List *plist, int num);

// 计算链表的长度
int length(List *plist);

// 反转链表
void reverse(List *plist);

// 释放链表所有节点的内存
void Free(List *plist);

#endif
