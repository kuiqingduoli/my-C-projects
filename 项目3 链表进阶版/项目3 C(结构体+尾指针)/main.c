#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct list
{
    Node *head;
    Node *tail; 
} List;
*/
void add(List *plist,int number); //向链表末尾添加节点
void show(List *plist); //显示链表所有节点
int search(List *plist,int num);//搜索链表中是否存在某个值
void Delete(List *plist,int num);//删除链表中第一个匹配的节点
void Free(List *plist);//释放链表所有节点内存
int main()
{
	List list;
	list.head=list.tail=NULL;
	int number;
	do
	{
		printf("请输入一个数字(输入-1结束)\n");
		scanf("%d",&number);
		if(number!=-1)
		{
			add(&list,number);
		}
	}while(number!=-1);
	show(&list);
	int num;
	printf("请输入搜索的数字\n");
	scanf("%d",&num);
	int isfound=search(&list,num);
	if(isfound)
	{
		printf("将删除此数字\n");
		Delete(&list,num);
		show(&list);
	}
	Free(&list);
}
void add(List *plist,int number)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(p==NULL) 
	{
		printf("内存分配失败！将退出程序\n");
		exit(1);
	}
	if(plist->head==NULL) //如果链表为空
	{
		plist->head=p; //新节点成为头节点
		plist->tail=p; //同时也是尾节点
	}else //链表不为空
	{
		plist->tail->next=p; //当前尾节点指向新节点
		plist->tail=p; //// 更新尾指针指向新节点
	}
}
void show(List *plist)
{
	Node *p;
	printf("此时的链表为:\n");
	for(p=plist->head;p;p=p->next)
	{
		printf("%d ",p->value);
	}
	printf("\n");
}
int search(List *plist,int num)
{
	Node *p;
	int isfound=0;
	for(p=plist->head;p;p=p->next)
	{
		if(num==p->value)
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
void Delete(List *plist,int num)
{
	Node *p,*q=NULL; //p:当前节点指针，q:前驱节点指针
	for(p=plist->head;p;q=p,p=p->next)
	{
		if(p->value==num)
		{
			if(q) //不是头节点
			{
				q->next=p->next; //前驱节点指向当前节点的后继
				if(p==plist->tail) //如果删除的是尾节点，需要更新尾指针
				{
					plist->tail=q; //尾指针指向前一个节点
				}
			}else //删除头节点
			{
				plist->head=p->next; //更新头指针指向下一个节点
				if(plist->head==NULL) //如果删除后链表为空，尾指针也要设为NULL
				{
					plist->tail=NULL;
				}
			}
			free(p);
			break;
		}
	}
}
void Free(List *plist)
{
	Node *p;
	while(plist->head!=NULL)
	{
		p=plist->head; //保存当前头节点
		plist->head=plist->head->next; //头指针指向下一个节点
		free(p); //释放当前节点内存
	}
	plist->tail=NULL; //将尾指针也设为NULL
}
