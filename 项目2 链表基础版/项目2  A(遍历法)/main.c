#include "node.h"
#include <stdlib.h>
#include <stdio.h>

/*
typedef struct node
{
	int value;
	struct node *next;
}Node;
*/
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
			//1.申请新节点内存 
			Node *p=(Node*)malloc(sizeof(Node));
			p->value=number;
			p->next=NULL;
			//2.将新节点连接到链表尾部 
			Node *last=head;
			if(last)
			{
				//如果不是第一个节点，遍历找到最后一个节点 
				while(last->next)
				{
					last=last->next;
				}
				//将新节点挂在最后 
				last->next=p;
	     	}else
	     	{
	     		//如果是第一个节点，设为头 
	     		head=p;
			}
	   }
		
	}while(number!=-1);
	int num;
	printf("请输入一个数字\n");
	scanf("%d",&num);
	Node *i;
	int found=0; 
	for(i=head;i;i=i->next)
	{
		if(i->value==num)
		{
			printf("找到了\n");
			found=1;
			break;
		}
	}
	if(!found)
	{
		printf("没找到\n");
	}
	Node *temp;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(head);
	}
	
	return 0;
}
