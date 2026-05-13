#include "node.h"

/* 向链表尾部添加新节点
 * 参数：
 *   plist - 指向链表结构的指针
 *   number - 要添加的数值
 */
void add(List *plist, int number)
{
	// 创建新节点
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	
	if(plist->head == NULL)  // 如果链表为空
	{
		plist->head = p;  // 新节点成为头节点
		plist->tail = p;  // 同时也是尾节点
	}
	else  // 链表不为空
	{
		plist->tail->next = p;  // 将新节点连接到当前尾节点后面
		plist->tail = plist->tail->next;  // 更新尾节点为新节点
	}
}

/* 显示链表中所有节点的值
 * 参数：
 *   plist - 指向链表结构的指针
 */
void show(List *plist)
{
	printf("当前的链表为:\n");
	Node *p;  // 用于遍历的指针
	
	// 遍历链表并打印每个节点的值
	for(p = plist->head; p; p = p->next)
	{
		printf("%d ", p->value);
	}
	printf("\n");
}

/* 在指定位置插入新节点
 * 参数：
 *   plist - 指向链表结构的指针
 *   num - 要插入的数值
 *   index - 插入位置（从1开始计数）
 */
void inserted(List *plist, int num, int index)
{
	// 检查位置有效性
	if(index < 1)
	{
		printf("插入的位置无效\n");
		return; 
	}
	
	// 创建新节点
	Node *p = (Node *)malloc(sizeof(Node));
	p->value = num;
	p->next = NULL;
	
	// 在头部插入
	if(index == 1)
	{
		p->next = plist->head;  // 新节点指向原头节点
		plist->head = p;        // 更新头节点为新节点
		
		// 如果链表原本为空，需要同时更新尾节点
		if(plist->tail == NULL)
		{
			plist->tail = p;
		}
		return;
	}
	
	// 在其他位置插入
	Node *q1 = NULL;        // 前一个节点指针
	Node *q2 = plist->head; // 当前节点指针
	int pos = 1;             // 当前位置计数器
	
	// 遍历链表找到插入位置
	while(q2 != NULL && pos < index)
	{
		q1 = q2;           // 保存前一个节点
		q2 = q2->next;     // 移动到下一个节点
		pos++;             // 位置计数
	}
	
	// 检查插入位置是否超出链表长度
	if(pos < index)
	{
		printf("插入的位置超出链表长度\n");
		free(p);  // 释放已分配但未使用的新节点内存
		return;
	}
	
	// 执行插入操作
	q1->next = p;  // 前一个节点指向新节点
	p->next = q2;  // 新节点指向原来的当前节点
	
	// 如果插入在尾部，需要更新尾节点
	if(q2 == NULL)
	{
		plist->tail = p;
	}
}

/* 在链表中搜索指定值
 * 参数：
 *   plist - 指向链表结构的指针
 *   num - 要搜索的数值
 * 返回值：
 *   找到返回1，未找到返回0
 */
int search(List *plist, int num)
{
	Node *p;           // 用于遍历的指针
	int cnt = 0;       // 记录节点位置
	int isfound = 0;   // 是否找到的标志
	
	// 遍历链表查找目标值
	for(p = plist->head; p; p = p->next) 
	{
		cnt++;  // 位置计数
		
		if(p->value == num)  // 找到目标值
		{
			printf("找到了，为链表中的第%d个数\n", cnt);
			isfound = 1;  // 设置找到标志
			break;        // 找到后退出循环
		}
	}
	
	if(!isfound)  // 如果未找到
	{
		printf("没有找到\n");
	}
	
	return isfound;  // 返回查找结果
}

/* 删除链表中第一个包含指定值的节点
 * 参数：
 *   plist - 指向链表结构的指针
 *   num - 要删除的数值
 */
void Delete(List *plist, int num)
{
	Node *q, *p = NULL;  // p:当前节点, q:前一个节点
	
	// 遍历链表查找要删除的节点
	for(p = plist->head; p; q = p, p = p->next)
	{
		if(p->value == num)  // 找到要删除的节点
		{
			if(q == NULL)  // 要删除的是头节点
			{
				plist->head = p->next;  // 更新头节点
				
				// 如果链表只有一个节点，删除后链表为空
				if(p->next == NULL)
				{
					plist->tail = NULL;  // 更新尾节点
				}
			}
			else  // 要删除的是中间或尾部节点
			{
				q->next = p->next;  // 前一个节点跳过当前节点
				
				// 如果删除的是尾节点
				if(p->next == NULL)
				{
					plist->tail = q;  // 更新尾节点
				}
			}
			
			free(p);  // 释放被删除节点的内存
			break;    // 只删除第一个匹配的节点
		}
	}
}

/* 计算链表的长度
 * 参数：
 *   plist - 指向链表结构的指针
 * 返回值：
 *   链表的节点个数
 */
int length(List *plist)
{
	int cnt = 0;  // 节点计数器
	Node *p;      // 用于遍历的指针
	
	// 遍历链表并计数
	for(p = plist->head; p; p = p->next)
	{
		cnt++;
	}
	
	return cnt;  // 返回节点总数
}

/* 反转链表
 * 参数：
 *   plist - 指向链表结构的指针
 */
void reverse(List *plist)
{
	// 如果链表为空或只有一个节点，无需反转
	if(plist->head == NULL || plist->head->next == NULL)
	{
		return;
	}
	
	// 保存原来的头节点，反转后将变成尾节点
	Node *old_head = plist->head;
	
	// 反转链表的三指针法
	Node *pre = NULL;      // 前一个节点
	Node *curr = plist->head;  // 当前节点
	Node *next = NULL;     // 下一个节点
	
	// 遍历链表，逐个反转节点间的指针方向
	while(curr)
	{
		next = curr->next;  // 保存下一个节点
		curr->next = pre;   // 当前节点指向前一个节点（反转）
		pre = curr;         // 前一个节点移动到当前位置
		curr = next;        // 当前节点移动到下一个位置
	}
	
	// 更新头尾指针
	plist->head = pre;      // 新的头节点是原链表的尾节点
	plist->tail = old_head; // 新的尾节点是原链表的头节点
}

/* 释放链表所有节点的内存
 * 参数：
 *   plist - 指向链表结构的指针
 */
void Free(List *plist)
{
	Node *p;  // 用于临时存储节点指针
	
	// 遍历链表，逐个释放节点内存
	while(plist->head)
	{
		p = plist->head;              // 保存当前节点
		plist->head = plist->head->next;  // 头指针指向下一个节点
		free(p);                      // 释放当前节点
	}
	
	plist->tail = NULL;  // 释放完所有节点后，尾指针设为NULL
}
