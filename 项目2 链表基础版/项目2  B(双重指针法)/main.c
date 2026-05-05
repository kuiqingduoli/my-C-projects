#include "node.h"
#include <stdio.h>
#include <stdlib.h> 

/*typedef struct node
{
	int value;
	struct node *next;
}Node;
*/
int main(int argc, char *argv[]) 
{
	Node *head=NULL;
	Node **last=&head;//指向指针的指针 
	int number;
	do
	{
		printf("请输入一个数字(输入-1结束)\n");
		scanf("%d",&number);
		if(number!=-1)
		{
			Node *p=(Node*)malloc(sizeof(Node));
			p->value=number;
			p->next=NULL;
			*last=p;//将新节点挂到最后一个节点的 next上 
			last=&(p->next);//更新 last指向新节点的 next 
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
