#include "node.h"

/* 向链表尾部添加新节点
 * 参数：
 *   head - 链表头指针
 *   number - 要添加的数值
 * 返回值：
 *   新的链表头指针
 */
Node *add(Node *head, int number)
{
	// 创建新节点并初始化
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	
	Node *last = head;  // 用于查找链表尾节点的指针
	
	if(last == NULL)  // 如果链表为空
	{
		head = p;  // 新节点成为头节点
	}
	else  // 如果链表不为空
	{
		// 遍历到链表最后一个节点
		while(last->next)
		{
			last = last->next;
		}
		// 将新节点连接到链表尾部
		last->next = p;
	}
	
	return head;  // 返回头指针
}

/* 显示链表中所有节点的值
 * 参数：
 *   head - 链表头指针
 */
void show(Node *head)
{
	Node *p;  // 用于遍历链表的临时指针
	printf("现在的链表为:\n");
	
	// 遍历链表并打印每个节点的值
	for(p = head; p; p = p->next)
	{
		printf("%d ", p->value);
	}
	printf("\n");
}

/* 在链表中搜索指定值
 * 参数：
 *   head - 链表头指针
 *   num - 要搜索的数值
 * 返回值：
 *   1表示找到，0表示未找到
 */
int search(Node *head, int num)
{
	Node *p;           // 用于遍历链表的临时指针
	int cnt = 0;       // 记录节点位置
	int isfound = 0;   // 是否找到的标志，0-未找到，1-找到
	
	// 遍历链表查找目标值
	for(p = head; p; p = p->next)
	{
		cnt++;  // 位置计数加1
		
		if(p->value == num)  // 找到目标值
		{
			printf("找到了，是链表中的第%d个数\n", cnt);
			isfound = 1;  // 设置找到标志
			break;        // 找到后退出循环
		}
	}
	
	if(!isfound)  // 如果未找到
	{
		printf("没找到\n");
	}
	
	return isfound;  // 返回查找结果
}

/* 删除链表中第一个包含指定值的节点
 * 参数：
 *   head - 链表头指针
 *   num - 要删除的数值
 * 返回值：
 *   新的链表头指针
 */
Node *Delete(Node *head, int num)
{
	Node *q, *p = NULL;  // p:当前节点指针，q:前一个节点指针
	
	// 遍历链表查找要删除的节点
	for(p = head; p; q = p, p = p->next)
	{
		if(p->value == num)  // 找到要删除的节点
		{
			if(q == NULL)  // 要删除的是头节点
			{
				head = p->next;  // 更新头指针，跳过当前节点
			}
			else  // 要删除的是中间或尾部节点
			{
				q->next = p->next;  // 前一个节点跳过当前节点
			}
			
			free(p);  // 释放被删除节点的内存
			break;    // 只删除第一个匹配的节点
		}
	}
	
	return head;  // 返回头指针
}

/* 在指定位置插入新节点
 * 参数：
 *   head - 链表头指针
 *   num - 要插入的数值
 *   index - 插入位置（从1开始计数）
 * 返回值：
 *   新的链表头指针
 */
Node *inserted(Node *head, int num, int index)
{
	// 创建新节点并初始化
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = num;
	p->next = NULL;
	
	// 检查位置有效性
	if(index < 1)
	{
		printf("插入的位置无效\n");
		free(p);  // 释放已分配但未使用的节点内存
		return head;  // 返回原头指针
	}
	
	// 在头部插入
	if(index == 1)
	{
		p->next = head;  // 新节点指向原头节点
		head = p;        // 更新头指针为新节点
		printf("已插入\n");
		return head;     // 返回新头指针
	}
	
	// 在其他位置插入
	Node *q1 = NULL;    // 前一个节点指针
	Node *q2 = head;    // 当前节点指针
	int pos = 1;        // 当前位置计数器
	
	// 遍历链表找到插入位置
	while(q2 != NULL && pos < index)
	{
		q1 = q2;         // 保存前一个节点
		q2 = q2->next;   // 移动到下一个节点
		pos++;           // 位置计数加1
	}
	
	// 检查插入位置是否超出链表长度
	if(pos < index)
	{
		printf("插入的位置超出链表长度\n");
		free(p);  // 释放已分配但未使用的节点内存
		return head;  // 返回原头指针
	}
	
	// 执行插入操作
	q1->next = p;  // 前一个节点指向新节点
	p->next = q2;  // 新节点指向原来的当前节点
	printf("已插入\n");
	
	return head;  // 返回头指针
}

/* 反转链表
 * 参数：
 *   head - 链表头指针
 * 返回值：
 *   反转后的链表头指针
 */
Node *reverse(Node *head)
{
	Node *pre = NULL;    // 前一个节点指针，初始为NULL
	Node *curr = head;   // 当前节点指针，从头节点开始
	Node *next = NULL;   // 下一个节点指针
	
	// 遍历链表，逐个反转节点间的指针方向
	while(curr)
	{
		next = curr->next;  // 保存下一个节点
		curr->next = pre;   // 当前节点指向前一个节点（反转）
		pre = curr;         // 前一个节点移动到当前位置
		curr = next;        // 当前节点移动到下一个位置
	}
	
	head = pre;  // 更新头指针为原链表的最后一个节点
	return head;  // 返回新的头指针
}

/* 释放链表所有节点的内存
 * 参数：
 *   head - 链表头指针
 * 返回值：
 *   NULL（表示链表已清空）
 */
Node *Free(Node *head)
{
	Node *p;  // 用于临时存储节点指针
	
	// 遍历链表，逐个释放节点内存
	while(head)
	{
		p = head;          // 保存当前节点
		head = head->next; // 头指针指向下一个节点
		free(p);           // 释放当前节点
	}
	
	return head;  // 此时head为NULL
}
