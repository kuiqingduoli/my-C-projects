#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 创建并初始化链表结构
	List list;
	list.head = list.tail = NULL;  // 初始化为空链表
	
	int number;
	// 循环读取用户输入，构建链表
	do
	{
		printf("请输入一个数字(输入-1结束)\n");
		scanf("%d", &number);
		if(number != -1)
		{
			add(&list, number);  // 添加节点到链表尾部
		}
	} while(number != -1);  // 输入-1时结束循环
	
	show(&list);  // 显示当前链表
	
	int num;
	int index;
	
	// 插入操作
	printf("请输入要插入的数字和位置\n");
	scanf("%d %d", &num, &index);
	inserted(&list, num, index);  // 在指定位置插入节点
	show(&list);  // 显示插入后的链表
	
	// 搜索操作
	printf("请输入要搜索的数字\n");
	scanf("%d", &num);
	search(&list, num);  // 搜索指定值
	
	// 删除操作
	printf("请输入要删除的数字\n");
	scanf("%d", &num);
	if(search(&list, num))  // 先搜索确认存在
	{
		Delete(&list, num);  // 删除节点
		printf("已删除\n");
		show(&list);  // 显示删除后的链表
	}
	else
	{
		printf("无法删除\n");  // 未找到则不删除
	}
	
	// 反转操作
	printf("将链表进行反转:\n");
	reverse(&list);  // 反转链表
	show(&list);  // 显示反转后的链表
	
	// 计算长度
	int len = length(&list);
	printf("此时链表的长度为:%d\n", len);
	
	// 释放内存
	Free(&list);
	
	return 0;
}
