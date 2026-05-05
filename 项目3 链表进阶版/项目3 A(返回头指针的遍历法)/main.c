#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct node
{
	int value;
	struct node *next;
}Node;
*/
Node *add(Node *head,int number);//向链表末尾添加新节点
void show(Node *head); //显示链表所有节点
int search(Node *head,int num);//搜索链表中是否存在指定数字
Node *Delete(Node *head,int num); //删除链表中第一个匹配的节点
Node *Free(Node *head);//释放链表所有节点内存
int main(int argc, char *argv[]) 
{
	int number;
	Node *head=NULL;
	do
	{
		printf("请输入一个数字(输入-1结束)\n"); 
		scanf("%d",&number);
		if(number!=-1)
		{
			head=add(head,number);
		}
	}while(number!=-1);
	show(head);
	int num;
	printf("请输入要搜索的数字\n");
	scanf("%d",&num);
	int isfound=search(head,num);
	char isdelete[10];
	if(isfound)
	{
		printf("是否删除此数(yes or no)\n");
		scanf("%9s",isdelete);
		if(strcmp(isdelete,"yes")==0)
		{
			head=Delete(head,num);
			printf("已删除此数\n");
			show(head);
		}else if(strcmp(isdelete,"no")==0)
		{
			show(head);
		}else
		{
			printf("输入有误!\n");
		}
	}
	head=Free(head);
	return 0;
}
Node *add(Node *head,int number)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(p==NULL)
	{
		printf("内存分配失败，退出程序！\n");
		exit(1);
	}
	Node *last=head;
	if(last==NULL)
	{
		head=p;
	}else
	{
		while(last->next)
		{  
			last=last->next;
		}
		last->next=p;
	}
	return head;
}
void show(Node *head)
{
	Node *p;
	printf("目前的链表为:\n");
	for(p=head;p;p=p->next)
	{
		printf("%d ",p->value);
	}
	printf("\n");
}
int search(Node *head,int num)
{
	int isfound=0;
	Node *p;
	for(p=head;p;p=p->next)
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
Node *Delete(Node *head,int num)
{
	Node *p,*q=NULL;
	for(p=head;p;q=p,p=p->next)
	{
		if(p->value==num)//找到要删除的节点
		{
			if(q)//如果要删除的不是头节点（有前驱节点）
			{
				q->next=p->next;//前驱节点的next指针跳过当前节点，指向当前节点的下一个节点
			}else//要删除的是头节点
			{
				head=p->next; //更新头指针，跳过当前头节点
			}
			free(p);
			break; //删除一个节点后退出循环
		}
	}
	return head;
}
Node *Free(Node *head)
{
	Node *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		free(p);
	}
	return head;
}
