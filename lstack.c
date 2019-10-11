#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node *NODE;
NODE top=NULL;
int count=0;
int size=10;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nno memory");
		exit(0);
	}
	else
		return x;
}
void push(int item)
{
	if(count==size)
		printf("\noverfloew");
	else
	{
		NODE temp=getnode();
		temp->data=item;
		temp->link=top;
		top=temp;
		count++;
	}
}
void pop()
{
	if(top==NULL)
		printf("\nstack is underflow");
	else
	{
		NODE temp=top;
		top=temp->link;
		free(temp);
		count--;
	}
}
void peek()
{
	if(top==NULL)
		printf("\nno elements in stack ");
	else
		printf("%d ",top->data);
}
void isempty()
{
	if(top==NULL)
		printf("\nthe stack is empty");
	else
		printf("\nthe stack is not empty");
}
void display()
{
	NODE ptr=top;
	printf("\nthe elements in stack are\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}

int main()
{
	int options,ele;
	do
	{
		printf("\n1.push\n2.pop\n3.peek\n4.isempty\n5.display\n0.exit\n");
		scanf("%d",&options);
		switch(options)
		{
			case 1:printf("\nenter the element to be pushed: ");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:pop();
				break;
			case 3:peek();
				break;
			case 4:isempty();
				break;
			case 5:display();
				break;
		}
	}while(options!=0);
	return 0;
}

