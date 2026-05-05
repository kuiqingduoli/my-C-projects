#include "node.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct node
{
	int value;
	struct node *next;
}Node;
*/

void add(Node **phead,int number); //向链表末尾添加节点
void show(Node **phead); //显示链表所有节点
int search(Node **phead,int num); //搜索链表中是否存在某个值
void Delete(Node **phead,int num); //删除链表中第一个匹配的节点
void Free(Node **phead); //释放链表所有节点内存
int main()
{
	int number;
	Node *head=NULL;
	do
	{
		printf("请输入一个数字(输入-1结束)\n");
		scanf("%d",&number);
		if(number!=-1)
		{
			add(&head,number);
		}
	}while(number!=-1);
	show(&head);
	int num;
	printf("请输入要搜索的数字\n");
	scanf("%d",&num);
	int isfound=search(&head,num);
	if(isfound)
	{
		printf("将删除此数字\n");
	    Delete(&head,num);
	    show(&head);
	}
	Free(&head);
	return 0;
	
}
void add(Node **phead,int number)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(p==NULL)
	{
		printf("内存分配失败！程序退出\n");
		exit(1);
	}
	Node *last=*phead;
	if(last==NULL) //如果链表为空
	{
		*phead=p; //新节点成为头节点
	}else //链表不为空
	{
		while(last->next) //遍历到最后一个节点
		{
			last=last->next;
		}
		last->next=p; //将新节点连接到末尾
	}
}
void show(Node **phead)
{
	Node *p;
	printf("此时的链表为:\n");
	for(p=*phead;p;p=p->next)
	{
		printf("%d ",p->value);
	}
	printf("\n");
}
int search(Node **phead,int num)
{
	Node *p;
	int isfound=0;
	for(p=*phead;p;p=p->next)
	{
		if(p->value==num)
		{
			printf("找到了\n");
			isfound=1;
			break;
		}
	}
	if(!isfound)
	{
		printf("没找到\n");
	}
	return isfound;
}
void Delete(Node **phead,int num)
{
	Node *p,*q=NULL; //p:当前节点指针，q:前驱节点指针
	for(p=*phead;p;q=p,p=p->next)
	{
		if(p->value==num)
		{
			if(q) //如果要删除的不是头节点
			{
				q->next=p->next; //前驱节点指向当前节点的后继
			}else //要删除的是头节点
			{
				*phead=p->next; //更新头指针指向下一个节点
			}
			free(p);
			break;
		}
	}
}
void Free(Node **phead)
{
	Node *p;
	while(*phead!=NULL)
	{
		p=*phead;
		*phead=(*phead)->next;
		free(p);
	}
}

