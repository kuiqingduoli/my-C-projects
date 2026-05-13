#include "node.h" 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;        // 用于存储用户输入的数字
	Node *head = NULL; // 链表头指针，初始为空链表
	
	/* 构建链表：循环读取用户输入，直到输入-1 */
	do
	{
		printf("请输入一个数字(输入-1结束)\n");
		scanf("%d", &number);
		if(number != -1)  // 如果输入的不是-1
		{
			// 调用add函数添加节点，并用返回值更新头指针
			head = add(head, number);
		}
	} while(number != -1);  // 输入-1时结束循环
	
	show(head);  // 显示当前链表
	
	int num;  // 用于存储要搜索/删除/插入的数字
	
	/* 搜索操作 */
	printf("请输入要搜索的数字\n");
	scanf("%d", &num);
	search(head, num);  // 搜索并显示结果
	
	/* 删除操作 */
	printf("请输入要删除的数字\n");
	scanf("%d", &num);
	int isfound = search(head, num);  // 先搜索确认数字存在
	if(isfound)  // 如果找到了
	{
		// 删除节点，并用返回值更新头指针
		head = Delete(head, num);
		printf("已删除\n");
		show(head);  // 显示删除后的链表
	}
	else  // 如果没找到
	{
		printf("链表中未找到此数字，无法删除\n");
	}
	
	/* 插入操作 */
	int index;  // 插入位置
	printf("请输入要插入的数字和位置\n");
	scanf("%d %d", &num, &index);
	// 插入节点，并用返回值更新头指针
	head = inserted(head, num, index);
	show(head);  // 显示插入后的链表
	
	/* 反转操作 */
	printf("将链表反转\n");
	// 反转链表，并用返回值更新头指针
	head = reverse(head);
	show(head);  // 显示反转后的链表
	
	/* 释放内存 */
	head = Free(head);  // 释放链表所有节点内存
	
	return 0;
}
