#include "array.h"
#include <stdio.h>

//typedef struct
// {
//	int *array;
//	int size;
// }Array;

int main()
{
	Array a=array_create(20);
	printf("%d\n",array_size(&a));
	printf("%d\n",a.size);
	*array_at(&a,0)=10;
	printf("%d\n",*array_at(&a,0));
	array_set(&a,1,5);
	printf("%d\n",array_get(&a,1));
	int number=0;
	int cnt=0;
	while(number!=-1)
	{
		scanf("%d",&number);
		*array_at(&a,cnt++)=number;
	}
	int i;
	cnt=0;
	for(i=0;i<a.size;i++)
	{
		printf("%d ",a.array[i]);
		cnt++;
		if(cnt==5)
		{
			printf("\n");
			cnt=0;
		}
	}
	array_free(&a);
}
