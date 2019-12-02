#include <stdio.h>

void enqueue(int i,int y);
void dequeue();
void display();

struct node{
	int data;
	struct node* next;
	int priority;
};

struct node* front = NULL;
struct node* rear = NULL;

int main(){
	//int i;
	//scanf("%d",&i);

	int s,j=2,r;
	do{ 
		printf("\n#####################################################################\n");
		printf("\nEnter one to enqueue \n");
		printf("\nEnter two to dequeu \n");
		printf("\nEnter three display items in the queue \n");
		printf("\n#####################################################################\n");
		scanf("%d",&s);int data=0, priority=0;
		switch(s)
	    {
		    case 1:
		    	
		    	printf("Enter the data: \n");
		    	scanf("%d",&data);
		    	printf("Enter the priority: \n");
		    	scanf("%d",&priority);
		    	enqueue(data,priority);
		    	break;
		    case 2:
		    	dequeue();
		    	break;
		    case 3:
		    	Display();
		    	break;
		    default:
		    	printf("no operation for this number choose(1,2,3)");
		    	break;
	    }j = 1;
	printf("\nif you want to continue press num>0 else press 0:");
	scanf("%d",&r);
}while(j<=r);
	return 0;
}


void enqueue(int data1, int priority1){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data1;
	temp->priority = priority1;
	temp->next = NULL;
	if(front==NULL && rear==NULL){
		front = rear = temp;
	}else{
		struct node* temp1 = front;
		if(temp1->priority > temp->priority){
            front = temp;
            temp->next = temp1;
            return;
        }
        
		while(temp1->next != NULL && temp1->next->priority < temp->priority){
			temp1 = temp1->next;
		}
		if(temp1->next != NULL) {
			temp->next = temp1->next;
		}
		temp1->next = temp;
	}
}
void dequeue(){
	struct node* temp = front;
	if(front == NULL){
		return;
	}
	if(front == rear){
		front = rear = NULL;
	}else{
		front = front->next;
	}
	int poped = temp->data;
	free(temp);
	printf("\n %d poped.\n",poped);
}
void Display(){
	struct node* temp;
    if( front == NULL) printf("Empty Queue\n");
    else
    {
        temp=front;
        printf("elements in queue\n");
        while(temp)
        {
            printf("%d  %d\n",temp->data, temp->priority);
            temp=temp->next;
        }
    }
}
